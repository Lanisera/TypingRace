#include "thirdparty/httplib.h"
#include "manager/game_manager.h"
#include <iostream>

int test();

int main(int argc, char **argv)
{
	return GameManager::instance()->run(argc, argv);
}

int test()
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
