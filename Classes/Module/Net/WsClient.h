#pragma once
#include "Base/Containers/HashMap.h"
#include "network/WebSocket.h"
#include "Base/BaseTypeDef.h"
#include "Base/Json.h"

USING_NS_CC;

class IRequest;

class WsClient : public network::WebSocket::Delegate{
  public:

	static WsClient* Create(GString pHost, int32 pPort);

	WsClient(GString pHost, int32 pPort);
	~WsClient();

	GString getUrl();
	network::WebSocket* getSocket();
	network::WebSocket::State getState();

	bool Connect();
	bool close();

	bool send(GString message);
	bool Send(IRequest *pRequest);

  private:
	network::WebSocket* _socket = nullptr;
	GString _url = "";
	GVector<IRequest *> _PendingRequests;
  GHashMap<GString, IRequest *> _Request;

	virtual void onOpen(cocos2d::network::WebSocket* ws);
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
	virtual void onClose(cocos2d::network::WebSocket* ws);
};