#pragma once

#include "timer/timer.h"
#include "camera/camera.h"
#include "manager/resources_manager.h"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <functional>

class Animation
{
public:
	using PlayCallBack = std::function<void()>;

public:
	Animation();

	~Animation() = default;

	void reset();

	void set_anim_tex_list(const ResourcesManager::AnimTexList& anim_tex_list);

	void set_loop(bool flag);

	void set_interval(double interval);

	void set_on_finished(PlayCallBack on_finished);

	void on_update(double delta);

	void on_render(const Camera& camera, SDL_Renderer* renderer, const SDL_Point& pos_dst, double angle = 0) const;

private:
	Timer timer;
	bool is_loop = true;
	PlayCallBack on_finished;
	size_t idx_frame = 0;
	ResourcesManager::AnimTexList anim_tex_list;
	int height_frame, width_frame;
};
