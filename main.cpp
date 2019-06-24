// Check Client and Message Broadcaster examples in 'lib/socket/examples'
/*
 *  TO DO
 *---------------- 
 *  controllers.cpp Separate Monolith function to GET/POST ETC HANDLERS using r->method_
 *  -- Meaning, webserver.cpp has to be modified to receive 'DELETE', 'PUT', 'PATCH' + more
 *  ** Issues to fix
 *    - POST without any data is not handled
 *    - 404 Handler is called for unsupported methods, but no JSON is sent
 *  
 *  webserver.cpp Refactor the JSON EXTRACTION CLASS to a new one
 *  -- Could make it a class so that we can do more with is, such as outputting JSON object -- I'm convinced
 *  -- Getting params from GET requests
 *---------------- 

 */

#include "lib\webserver\webserver.h"
#include "lib\controllers\controllers.h"

#include "lib\socket\src\Socket.h"
#include <iostream>

using namespace std;

int main()
{

  int port = 8080; // Should be set through an environment variable

  webserver(port, Controller::Request_Handler);
}
