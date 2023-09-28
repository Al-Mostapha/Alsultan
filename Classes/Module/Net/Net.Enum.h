#pragma once

enum class ERequestType{
  Http,
  WebSocket
};

enum class ERequestState{
  None,
  Requesting,
  Success,
  Failed
};

enum class ERequestError{
  None,
  Timeout,
  Network,
  Server,
  Client
};

enum class ERequestContentType{
  None,
  Json,
  Form
};

enum class ERequestMethod{
  None,
  Get,
  Post,
  Put,
  Delete
};

enum class ERequestHeader{
  None,
  ContentType,
  ContentLength,
  AcceptEncoding,
  AcceptLanguage,
  Accept,
  UserAgent,
  Authorization,
  Cookie,
  Origin,
  Host,
  Connection,
  CacheControl
};
