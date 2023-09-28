#include "WsClient.h"
#include "IRequest.h"

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

bool WsClient::send(GString message)
{
	try
	{
		if (this->_socket != nullptr) {
			if (this->_socket->getReadyState() == network::WebSocket::State::OPEN)
				this->_socket->send(message);
			else if (this->_socket->getReadyState() == network::WebSocket::State::CONNECTING)
				this->_pendingMessages.push_back(message);
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
	if (this->_pendingMessages.size() > 0) {
		for (GString message : _pendingMessages)
			send(message);

		this->_pendingMessages.clear();
	}

}

void WsClient::onMessage(network::WebSocket * ws, const network::WebSocket::Data & data)
{
	std::string(data.bytes, data.len);
  CCLOG("onMessage %s", std::string(data.bytes, data.len).c_str());
}

void WsClient::onClose(network::WebSocket * ws)
{

}

void WsClient::onError(network::WebSocket * ws, const network::WebSocket::ErrorCode & error)
{
	
}