#include "animation/animation.h"
#include "camera/camera.h"
#include "manager/resources_manager.h"
#include <SDL_render.h>
#include <bits/types/wint_t.h>

Animation::Animation()
{
	timer.set_one_shot(false);
	timer.set_on_timeout([&]()
			{
				idx_frame++;
				if (idx_frame >= anim_tex_list.size())
				{
					idx_frame = is_loop ? 0 : anim_tex_list.size() - 1;
					if (!is_loop && on_finished)
						on_finished();
				}
			});

	height_frame = 96, width_frame = 96;
}

void Animation::reset()
{
	idx_frame = 0;
	timer.restart();
}

void Animation::set_anim_tex_list(const ResourcesManager::AnimTexList& anim_tex_list)
{
	this->anim_tex_list = anim_tex_list;
}

void Animation::set_loop(bool flag)
{
	is_loop = flag;
}

void Animation::set_interval(double interval)
{
	timer.set_wait_time(interval);
}

void Animation::set_on_finished(PlayCallBack on_finished)
{
	this->on_finished = on_finished;
}

void Animation::on_update(double delta)
{
	timer.on_update(delta);
}

void Animation::on_render(const Camera& camera, SDL_Renderer* renderer, const SDL_Point& pos_dst, double angle) const
{
	static SDL_Rect rect_dst;
	static SDL_Point camera_pos;

	camera_pos.x = camera.get_position().x;
	camera_pos.y = camera.get_position().y;

	rect_dst.x = pos_dst.x - camera_pos.x;
	rect_dst.y = pos_dst.y - camera_pos.y;
	rect_dst.w = width_frame, rect_dst.h = height_frame;

	SDL_RenderCopyEx(renderer, anim_tex_list[idx_frame], nullptr, &rect_dst, angle, nullptr, SDL_FLIP_NONE);
}
