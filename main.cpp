#include "lib\webserver\webserver.h"
#include "lib\socket\src\Socket.h"

#include "lib\controllers\controllers.h"

int main()
{

  int port = 8080; // Should be set through an environment variable

  webserver(port, Controller::Request_Handler);
}
