#include "player/player.h"
#include "camera/camera.h"
#include "vector/vector2.h"

Player::Player(ResourcesManager::AnimTexList tex_list_idle_up, ResourcesManager::AnimTexList tex_list_idle_down, 
			ResourcesManager::AnimTexList tex_list_idle_left, ResourcesManager::AnimTexList tex_list_idle_right,
			ResourcesManager::AnimTexList tex_list_run_up, ResourcesManager::AnimTexList tex_list_run_down,
			ResourcesManager::AnimTexList tex_list_run_left, ResourcesManager::AnimTexList tex_list_run_right)
{
	anim_idle_up.set_loop(true);
	anim_idle_up.set_interval(0.1);
	anim_idle_up.set_anim_tex_list(tex_list_idle_up);

	anim_idle_down.set_loop(true);
	anim_idle_down.set_interval(0.1);
	anim_idle_down.set_anim_tex_list(tex_list_idle_down);

	anim_idle_left.set_loop(true);
	anim_idle_left.set_interval(0.1);
	anim_idle_left.set_anim_tex_list(tex_list_idle_left);

	anim_idle_right.set_loop(true);
	anim_idle_right.set_interval(0.1);
	anim_idle_right.set_anim_tex_list(tex_list_idle_right);

	anim_run_up.set_loop(true);
	anim_run_up.set_interval(0.1);
	anim_run_up.set_anim_tex_list(tex_list_run_up);

	anim_run_down.set_loop(true);
	anim_run_down.set_interval(0.1);
	anim_run_down.set_anim_tex_list(tex_list_run_down);

	anim_run_left.set_loop(true);
	anim_run_left.set_interval(0.1);
	anim_run_left.set_anim_tex_list(tex_list_run_left);

	anim_run_right.set_loop(true);
	anim_run_right.set_interval(0.1);
	anim_run_right.set_anim_tex_list(tex_list_run_right);

	size.x = 96, size.y = 96;
}

void Player::on_update(double delta)
{

}

void Player::on_render(const Camera& camera, SDL_Renderer* renderer)
{
	if (current_anim == nullptr) return ;
	
	static SDL_Point pos_dst;
	
	pos_dst.x = (int)(position.x - size.x / 2);
	pos_dst.y = (int)(position.y - size.y / 2);

	current_anim->on_render(camera, renderer, pos_dst);
}

void Player::set_position(const Vector2& position)
{
	this->position = position;
}

const Vector2& Player::get_position() const
{
	return position;
}
