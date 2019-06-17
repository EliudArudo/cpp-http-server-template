#include "lib\webserver\webserver.h"
#include "lib\socket\src\Socket.h"

#include "lib\controllers\controllers.h"

int main()
{

  webserver(8080, Controller::Request_Handler);
}
