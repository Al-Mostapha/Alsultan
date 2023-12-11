#include "WsClient.h"
#include "IRequest.h"
#include "WsRequest.h"
#include "WsResponse.h"

WsClient * WsClient::Create(GString pHost, int32 pPort)
{
	auto socket = new WsClient(pHost, pPort);
	return socket;
}

WsClient::WsClient(GString pHost, int32 pPort)
{
	this->_url = "ws://" + pHost + ":" + std::to_string(pPort);
}

WsClient::~WsClient()
{
	this->_socket->close();
}

GString WsClient::getUrl()
{
	return this->_url;
}

network::WebSocket * WsClient::getSocket()
{
	return this->_socket;
}

network::WebSocket::State WsClient::getState()
{
	if (this->_socket != nullptr)
		return this->_socket->getReadyState();

	return network::WebSocket::State();
}

bool WsClient::Connect()
{
	try
	{
		this->_socket = new network::WebSocket();
		return this->_socket->init(*this, this->_url);
	}
	catch (const std::exception&)
	{
		throw;
	}

	return false;
}

bool WsClient::close()
{
	try
	{
		if (this->_socket != nullptr && this->_socket->getReadyState() == network::WebSocket::State::OPEN)
			this->_socket->close();

		return true;
	}
	catch (const std::exception&)
	{
		throw;
	}

	return false;
}

bool WsClient::Send(IRequest *pReq)
{
	try
	{

		if (this->_socket != nullptr) {
			if (this->_socket->getReadyState() == network::WebSocket::State::OPEN){
        if(pReq->_BeforeSend)
          pReq->_BeforeSend(pReq);
        XJson lJson = {
          {"Url", pReq->_Url},
          {"Params", pReq->_Params},
          {"Data", pReq->_Data},
          {"Method", pReq->_Method},
          {"ContentType", pReq->_ContentType},
          {"State", pReq->_State},
          {"Error", pReq->_Error},
          {"Type", pReq->_Type},
          {"Headers", pReq->_Headers},
          {"Token", pReq->_Token},
          {"RequestID", pReq->_RequestID},
          {"TimeStamp", pReq->_TimeStamp}
        };
        CCLOG("Sending Through websocket %s", lJson.dump().c_str());
				this->_socket->send(lJson.dump());
        this->_Requests[pReq->_RequestID] = pReq;
      }
			else if (this->_socket->getReadyState() == network::WebSocket::State::CONNECTING)
				this->_PendingRequests.push_back(pReq);
		}

		return true;
	}
	catch (const std::exception&)
	{
		throw;
	}

	return false;
}

bool WsClient::send(GString message)
{
	try
	{
		if (this->_socket != nullptr) {
			if (this->_socket->getReadyState() == network::WebSocket::State::OPEN)
				this->_socket->send(message);
			// else if (this->_socket->getReadyState() == network::WebSocket::State::CONNECTING)
			// 	this->_pendingMessages.push_back(message);
		}

		return true;
	}
	catch (const std::exception&)
	{
		throw;
	}

	return false;
}



void WsClient::onOpen(network::WebSocket * ws)
{
	// if (this->_pendingMessages.size() > 0) {
	// 	for (GString message : _pendingMessages)
	// 		send(message);

	// 	this->_pendingMessages.clear();
	// }

  cocos2d::log("onOpen");
}

void WsClient::onMessage(network::WebSocket * ws, const network::WebSocket::Data & data)
{
	auto lMsg = GString(data.bytes, data.len);
  auto lRes = WSResponse::Create(lMsg);
  lRes->FromWsMsg();
  cocos2d::log("onMessage %s", lRes->_Json.dump().c_str());
  lRes->Exec();
  Exec(lRes);
}

bool WsClient::Exec(IResponse *pResponse){

  if(!pResponse->_Json.contains("RequestID"))
    return false;
  auto lRequestID = pResponse->_Json["RequestID"].get<GString>();
  if(!this->_Requests.Contains(lRequestID))
    return false;
  auto lRequest = this->_Requests[lRequestID];
  this->_Requests.erase(lRequestID);
  if(lRequest->_OnComplete)
    lRequest->_OnComplete(pResponse, lRequest);
  if(lRequest->_OnSuccess)
    lRequest->_OnSuccess(pResponse, lRequest);

  lRequest->release();
  pResponse->release();
  return true;
}

void WsClient::onClose(network::WebSocket * ws)
{

}

void WsClient::onError(network::WebSocket * ws, const network::WebSocket::ErrorCode & error)
{
	
}