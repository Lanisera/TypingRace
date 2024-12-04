#include "manager/game_manager.h"
#include "manager/resources_manager.h"
#include "thirdparty/httplib.h"
#include "vector/vector2.h"
#include <SDL.h>
#include <SDL_events.h>
#include <SDL_hints.h>
#include <SDL_image.h>
#include <SDL_messagebox.h>
#include <SDL_mixer.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

GameManager::GameManager()
{
	init_assert(!SDL_Init(SDL_INIT_EVERYTHING), u8"SOL2 初始化失败");
	init_assert(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG), u8"SDL_image 初始化失败");
	init_assert(Mix_Init(MIX_INIT_MP3), u8"SDL_mixer 初始化失败");
	init_assert(!TTF_Init(), u8"SLD_ttf 初始化失败");

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	SDL_SetHint(SDL_HINT_IME_SHOW_UI, "-1");

	window = SDL_CreateWindow("TypingRace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	init_assert(window, u8"窗口创建失败");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	init_assert(renderer, u8"渲染器创建失败");

	init_assert(ResourcesManager::instance()->load_resources_from_file(renderer), u8"游戏基本资源加载失败");

}

void GameManager::init_assert(bool flag, const char *err_msg)
{
	if (flag) return ;

	std::cout << err_msg << std::endl;
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, u8"游戏启动失败", err_msg, window);
	exit(-1);
}

void GameManager::login_to_server()
{
	client = new httplib::Client(str_address);
	client->set_keep_alive(true);

	httplib::Result result = client->Post("/login");
	if (!result || result->status != 200)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "无法连接到服务器！", u8"启动失败", window);
		exit(-1);
	}

	player_id = std::stoi(result->body);
	if (player_id <= 0)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "比赛已经开始了！", "拒绝加入！", window);
		exit(-1);
	}

	(player_id == 1) ? (progress_1 = 0) : (progress_2 = 0);

	str_text = client->Post("/query_text")->body;

	std::stringstream str_stream(str_text);
	std::string str_line;
	while (std::getline(str_stream, str_line))
	{
		str_line_list.push_back(str_line);
		num_total_char += (int)str_line.length();
	}
	
	std::thread([&]()
			{
				while (true)
				{
					using namespace std::chrono;

					std::string route = (player_id == 1) ? "/update1" : "/update2";
					std::string body = std::to_string(player_id == 1 ? progress_1 : progress_2);
					httplib::Result result = client->Post(route, body, "text/plain");

					if (result && result->status == 200)
					{
						int progress = std::stoi(result->body);
						(player_id == 1) ? (progress_2 = progress) : (progress_1 = progress); 
					}

					std::this_thread::sleep_for(nanoseconds(1000000000 / 10));

				}
			}).detach();
}

int GameManager::run(int argc, char **argv)
{
	Mix_FadeInMusic(ResourcesManager::instance()->get_music_pool().find(ResID::Music_BGM)->second, -1, 1500);

	Uint64 last_counter = SDL_GetPerformanceCounter();
	Uint64 counter_freq = SDL_GetPerformanceFrequency();


	while (!is_quit)
	{
		
		while (SDL_PollEvent(&event))
			on_input();

		Uint64 cur_counter = SDL_GetPerformanceCounter();
		double delta = (double)(cur_counter - last_counter) / counter_freq;
		last_counter = cur_counter;
		if (delta * 1000.0 < 1000.0 / 60)
			SDL_Delay((Uint32)(1000.0 / 60) - delta * 1000);

		on_update(delta);

		on_render();
	}

	return 0;
}

void GameManager::on_input()
{
	switch (event.type)
	{
	case SDL_QUIT:
		is_quit = true;
		break;
	}

}

void GameManager::on_update(double delta)
{

}

void GameManager::on_render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	camera_scene.set_position(Vector2(0, 0));
	static SDL_Rect rect_src = {842, 842, 1280, 720};
	static SDL_Rect rect_dst = {0, 0, 1280, 720};
	SDL_RenderCopy(renderer, ResourcesManager::instance()->get_texture_pool().find(ResID::Tex_Background)->second, &rect_src, &rect_dst);

	SDL_RenderPresent(renderer);
}
