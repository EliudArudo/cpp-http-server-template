#include <iostream>

#include "../webserver/webserver.h"
#include "../socket/src/Socket.h"
#include "../nlohmann/json.hpp"

#include "../services/data/data.h"

#include "controllers.h"

using nlohmann::json; // Important for sending back JSON

void Controller::Request_Handler(webserver::http_request *r)
{
    Socket s = *(r->s_);

    // Logging json body data and params sent along
    std::string params = DataService::mapToString(r->params_);

    if (params.length() > 2) // Covering the default "{}"
    {
        std::cout << "Params on " << r->method_ << " request to '" << r->path_ << "' path :" << std::endl;
        std::cout << params << std::endl;
    }

    if (r->raw_body_data_.length() > 0)
    {
        std::cout << "Data sent along with the " << r->method_ << " request to '" << r->path_ << "' path :" << std::endl;
        std::cout << r->raw_body_data_ << std::endl;
    }

    // Mapping Request methods to repective handlers
    if (r->method_ == "POST")
        POST_handler(r);
    else if (r->method_ == "GET")
        GET_handler(r);
    else if (r->method_ == "PUT")
        PUT_handler(r);
    else
        Handle_404(r);
};

void Controller::POST_handler(webserver::http_request *r)
{

    std::cout << "POST Handler called" << std::endl;

    Socket s = *(r->s_);

    std::string json_response;
    std::map<std::string, std::string> json_map_response;

    if (r->path_ == "/")
    {
        json_map_response = {{"path", "index"}, {"route", "/"}};
    }
    else if (r->path_ == "/red")
    {
        json_map_response = {{"path", "red-page"}, {"route", "/red"}};
    }
    else if (r->path_ == "/blue")
    {
        json_map_response = {{"path", "blue-page"}, {"route", "/blue"}};
    }
    else if (r->path_ == "/form")
    {
        // title = "Fill a form";

        // body = "<h1>Fill a form</h1>";
        // body += "<form action='/form'>"
        //         "<table>"
        //         "<tr><td>Field 1</td><td><input name=field_1></td></tr>"
        //         "<tr><td>Field 2</td><td><input name=field_2></td></tr>"
        //         "<tr><td>Field 3</td><td><input name=field_3></td></tr>"
        //         "</table>"
        //         "<input type=submit></form>";

        // for (std::map<std::string, std::string>::const_iterator i = r->params_.begin();
        //      i != r->params_.end();
        //      i++)
        // {

        //     body += "<br>" + i->first + " = " + i->second;
        // }

        // body += "<hr>" + links;

        json_map_response = {{"path", "form-page"}, {"route", "/form"}};
    }
    else if (r->path_ == "/auth")
    {
        // if (r->authentication_given_)
        // {
        //     if (r->username_ == "rene" && r->password_ == "secretGarden")
        //     {
        //         body = "<h1>Successfully authenticated</h1>" + links;
        //     }
        //     else
        //     {
        //         body = "<h1>Wrong username or password</h1>" + links;
        //         r->auth_realm_ = "Private Stuff";
        //     }
        // }
        // else
        // {
        //     r->auth_realm_ = "Private Stuff";
        // }

        json_map_response = {{"path", "auth-page"}, {"route", "/auth"}};
    }
    else if (r->path_ == "/header")
    {
        json_map_response = {{"path", "header-page"}, {"route", "/header"}};
    }
    else
    {
        Handle_404(r);
        return;
    }

    r->answer_ = DataService::mapToString(json_map_response); // Find out how to receive data
}

void Controller::GET_handler(webserver::http_request *r)
{

    std::cout << "GET Handler called" << std::endl;

    Socket s = *(r->s_);

    std::string json_response;
    std::map<std::string, std::string> json_map_response;

    if (r->path_ == "/")
    {
        json_map_response = {{"path", "index"}, {"route", "/"}};
    }
    else if (r->path_ == "/red")
    {

        json_map_response = {{"path", "red-page"}, {"route", "/red"}};
    }
    else if (r->path_ == "/blue")
    {
        json_map_response = {{"path", "blue-page"}, {"route", "/blue"}};
    }
    else if (r->path_ == "/form")
    {
        // title = "Fill a form";

        // body = "<h1>Fill a form</h1>";
        // body += "<form action='/form'>"
        //         "<table>"
        //         "<tr><td>Field 1</td><td><input name=field_1></td></tr>"
        //         "<tr><td>Field 2</td><td><input name=field_2></td></tr>"
        //         "<tr><td>Field 3</td><td><input name=field_3></td></tr>"
        //         "</table>"
        //         "<input type=submit></form>";

        // for (std::map<std::string, std::string>::const_iterator i = r->params_.begin();
        //      i != r->params_.end();
        //      i++)
        // {

        //     body += "<br>" + i->first + " = " + i->second;
        // }

        // body += "<hr>" + links;

        json_map_response = {{"path", "form-page"}, {"route", "/form"}};
    }
    else if (r->path_ == "/auth")
    {
        // if (r->authentication_given_)
        // {
        //     if (r->username_ == "rene" && r->password_ == "secretGarden")
        //     {
        //         body = "<h1>Successfully authenticated</h1>" + links;
        //     }
        //     else
        //     {
        //         body = "<h1>Wrong username or password</h1>" + links;
        //         r->auth_realm_ = "Private Stuff";
        //     }
        // }
        // else
        // {
        //     r->auth_realm_ = "Private Stuff";
        // }

        json_map_response = {{"path", "auth-page"}, {"route", "/auth"}};
    }
    else if (r->path_ == "/header")
    {
        json_map_response = {{"path", "header-page"}, {"route", "/header"}};
    }
    else
    {
        Handle_404(r);
        return;
    }

    r->answer_ = DataService::mapToString(json_map_response); // Find out how to receive data
}

void Controller::PUT_handler(webserver::http_request *r)
{

    std::cout << "PUT Handler called" << std::endl;

    Socket s = *(r->s_);

    std::string json_response;
    std::map<std::string, std::string> json_map_response;

    if (r->path_ == "/")
    {
        json_map_response = {{"path", "index"}, {"route", "/"}};
    }
    else if (r->path_ == "/red")
    {

        json_map_response = {{"path", "red-page"}, {"route", "/red"}};
    }
    else if (r->path_ == "/blue")
    {
        json_map_response = {{"path", "blue-page"}, {"route", "/blue"}};
    }
    else if (r->path_ == "/form")
    {
        // title = "Fill a form";

        // body = "<h1>Fill a form</h1>";
        // body += "<form action='/form'>"
        //         "<table>"
        //         "<tr><td>Field 1</td><td><input name=field_1></td></tr>"
        //         "<tr><td>Field 2</td><td><input name=field_2></td></tr>"
        //         "<tr><td>Field 3</td><td><input name=field_3></td></tr>"
        //         "</table>"
        //         "<input type=submit></form>";

        // for (std::map<std::string, std::string>::const_iterator i = r->params_.begin();
        //      i != r->params_.end();
        //      i++)
        // {

        //     body += "<br>" + i->first + " = " + i->second;
        // }

        // body += "<hr>" + links;

        json_map_response = {{"path", "form-page"}, {"route", "/form"}};
    }
    else if (r->path_ == "/auth")
    {
        // if (r->authentication_given_)
        // {
        //     if (r->username_ == "rene" && r->password_ == "secretGarden")
        //     {
        //         body = "<h1>Successfully authenticated</h1>" + links;
        //     }
        //     else
        //     {
        //         body = "<h1>Wrong username or password</h1>" + links;
        //         r->auth_realm_ = "Private Stuff";
        //     }
        // }
        // else
        // {
        //     r->auth_realm_ = "Private Stuff";
        // }

        json_map_response = {{"path", "auth-page"}, {"route", "/auth"}};
    }
    else if (r->path_ == "/header")
    {
        json_map_response = {{"path", "header-page"}, {"route", "/header"}};
    }
    else
    {
        Handle_404(r);
        return;
    }

    r->answer_ = DataService::mapToString(json_map_response); // Find out how to receive data
}

void Controller::Handle_404(webserver::http_request *r)
{

    std::cout << "404 Handler called" << std::endl;

    std::map<std::string, std::string> json_map_response;

    r->status_ = "404 not found";
    json_map_response = {{"path", "404"}, {"status", "page non existent"}};

    r->answer_ = DataService::mapToString(json_map_response); // Find out how to receive data
}