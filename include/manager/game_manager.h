#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <atomic>
#include <string>
#include <vector>
#include "camera/camera.h"
#include "player/player.h"
#include "manager/manager.h"
#include "thirdparty/httplib.h"
#include "timer/timer.h"

class GameManager : public Manager<GameManager>
{
	friend class Manager<GameManager>;
public:
	enum class Stage
	{
		Waiting,
		Ready,
		Racing
	};

public:
	int run(int argc, char **argv);

protected:
	GameManager(); 

	~GameManager() = default;

private:
	void init_assert(bool flag, const char *err_msg);

	void login_to_server();

	void on_input();

	void on_update(double delta);

	void on_render();

private:
	int idx_line = 0;
	int idx_char = 0;
	std::string str_text;
	std::vector<std::string> str_line_list;

	std::string str_address;
	httplib::Client* client = nullptr;

	int val_countdown = 4;
	Stage stage = Stage::Waiting;

	int player_id = 0;
	std::atomic<int> progress_1 = -1;
	std::atomic<int> progress_2 = -1;
	int num_total_char = 0;

	Timer timer_countdown;
	Player* player_1 = nullptr;
	Player* player_2 = nullptr;
	Camera camera_ui, camera_scene;

	SDL_Event event;
	bool is_quit = false;

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
};
