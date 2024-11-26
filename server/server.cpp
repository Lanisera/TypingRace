#include "thirdparty/httplib.h"
#include <iostream>

int main(int argc, char **argv)
{
	httplib::Server server;

	server.Get("/hello", [&](const httplib::Request& req, httplib::Response& res)
			{
				std::cout << "Hello From Client" << std::endl;

				res.set_content("Hello From Server!", "text/plain");
			});

	server.listen("localhost", 25565);

	return 0;
}
