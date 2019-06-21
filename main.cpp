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

// ->> https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/Socket_cpp/examples

// ------ Send requests to another server ----------

// This is an example for Socket.cpp, a leight weight C++ class to demonstrate Sockets for Windows programming.
// It connects to www.renenyffenegger.ch, port 80, and GETs its front page.

// #include "Socket.h"
// #include <iostream>

// using namespace std;

// int main()
// {

//   try
//   {
//     SocketClient s("www.renenyffenegger.ch", 80);

//     s.SendLine("GET / HTTP/1.0");
//     s.SendLine("Host: www.renenyffenegger.ch");
//     s.SendLine("");

//     while (1)
//     {
//       string l = s.ReceiveLine();
//       if (l.empty())
//         break;
//       cout << l;
//       cout.flush();
//     }
//   }
//   catch (const char *s)
//   {
//     cerr << s << endl;
//   }
//   catch (std::string s)
//   {
//     cerr << s << endl;
//   }
//   catch (...)
//   {
//     cerr << "unhandled exception\n";
//   }

//   return 0;
// }

// This is an example for Socket.cpp, a leight weight C++ class to demonstrate Sockets for Windows programming.
// Message Distributor is a server that listens on port 2000. Any number of clients can connect to that server. When a client sends a message to the server, the server will broadcast this message to all other clients, but not to the one that sent the message.

// /*
//    msg-distributor.cpp

//    Copyright (C) 2002-2017 René Nyffenegger

//    This source code is provided 'as-is', without any express or implied
//    warranty. In no event will the author be held liable for any damages
//    arising from the use of this software.

//    Permission is granted to anyone to use this software for any purpose,
//    including commercial applications, and to alter it and redistribute it
//    freely, subject to the following restrictions:

//    1. The origin of this source code must not be misrepresented; you must not
//       claim that you wrote the original source code. If you use this source code
//       in a product, an acknowledgment in the product documentation would be
//       appreciated but is not required.

//    2. Altered source versions must be plainly marked as such, and must not be
//       misrepresented as being the original source code.

//    3. This notice may not be removed or altered from any source distribution.

//    René Nyffenegger rene.nyffenegger@adp-gmbh.ch
// */

// #include "Socket.h"
// #include <process.h>
// #include <string>
// #include <list>

// typedef std::list<Socket *> socket_list;

// socket_list g_connections;

// unsigned __stdcall Connection(void *a)
// {
//   Socket *s = (Socket *)a;

//   g_connections.push_back(s);

//   s->SendLine("Welcome to the Message Distributor");

//   while (1)
//   {
//     std::string r = s->ReceiveLine();
//     if (r.empty())
//       break;

//     for (socket_list::iterator os = g_connections.begin();
//          os != g_connections.end();
//          os++)
//     {
//       if (*os != s)
//         (*os)->SendLine(r);
//     }
//   }

//   g_connections.remove(s);

//   delete s;

//   return 0;
// }

// int main()
// {
//   SocketServer in(2000, 5);

//   while (1)
//   {
//     Socket *s = in.Accept();

//     unsigned ret;
//     _beginthreadex(0, 0, Connection, (void *)s, 0, &ret);
//   }

//   return 0;
// }