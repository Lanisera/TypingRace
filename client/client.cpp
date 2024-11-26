#include "thirdparty/httplib.h"
#include <iostream>

int main(int argc, char **argv)
{
	httplib::Client client("localhost:25565");

	httplib::Result result = client.Get("/hello");
	if (!result || result->status != 200)
	{
		std::cout << "Hello Failed!" << std::endl;

		return -1;
	}

	std::cout << result->body << std::endl;

	return 0;
}
