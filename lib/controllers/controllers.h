#include "../webserver/webserver.h"

class Controller
{
public:
  Controller();

  void static Request_Handler(webserver::http_request *);
};