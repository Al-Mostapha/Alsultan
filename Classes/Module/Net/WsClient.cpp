#include "WsClient.h"
#include "IRequest.h"
#include "WsRequest.h"

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
  auto lRequest = WsRequest::Create();
  lRequest->_Url = "/api/v1/room";
  lRequest->_Method      = ERequestMethod::Get;
  lRequest->_ContentType = ERequestContentType::Json;
  lRequest->_State       = ERequestState::None;
  lRequest->_Error       = ERequestError::None;
  lRequest->_Type        = ERequestType::Http;
  lRequest->_Headers     = GMap<ERequestHeader, GString>();
  lRequest->_Token       = "";
  lRequest->_Data        = R"({"Json":"Json"})";
  lRequest->_OnComplete  = [](IResponse *pResponse, IRequest *pRequest) {
    cocos2d::log("OnComplete");
  };

  lRequest->_OnError     = [](ERequestError pError, GString pMessage) {
    cocos2d::log("OnError");
  };

  lRequest->_OnSuccess   = [](IResponse *pResponse, IRequest *pRequest) {
    cocos2d::log("OnSuccess");
  };

  lRequest->_BeforeSend  = [](IRequest *pRequest) {
    CCLOG("BeforeSend");
  };

  lRequest->Send();

}

void WsClient::onMessage(network::WebSocket * ws, const network::WebSocket::Data & data)
{
	std::string(data.bytes, data.len);
  cocos2d::log("onMessage %s", std::string(data.bytes, data.len).c_str());
}

void WsClient::onClose(network::WebSocket * ws)
{

}

void WsClient::onError(network::WebSocket * ws, const network::WebSocket::ErrorCode & error)
{
	
}