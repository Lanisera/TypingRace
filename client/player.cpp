#include "player/player.h"
#include "camera/camera.h"
#include "manager/game_manager.h"
#include "path/path.h"
#include "vector/vector2.h"
#include <iostream>

Player::Player(
			ResourcesManager::AnimTexList tex_list_idle_up, ResourcesManager::AnimTexList tex_list_idle_down, 
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
	current_anim = &anim_idle_right;
}

void Player::on_update(double delta, double progress)
{
	Vector2 move_distance = velocity * delta;
	Vector2 target_distance = pos_target - position;
	position += move_distance < target_distance ? move_distance : target_distance;

	if ((pos_target - position).approx_zero())
	{
		refresh_new_target(progress);

		direction = (pos_target - position).normalize();
	}

	velocity = direction * SPEED_RUN;

	if (direction.approx_zero())
	{
		switch (facing)
		{
			case Player::Facing::Up:
				current_anim = &anim_idle_up;
				break;
			case Player::Facing::Down:
				current_anim = &anim_idle_down;
				break;
			case Player::Facing::Left:
				current_anim = &anim_idle_left;
				break;
			case Player::Facing::Right:
				current_anim = &anim_idle_right;
				break;
		}
	}
	else
	{
		if (abs(velocity.y) >= 0.0001)
			facing = (velocity.y > 0) ? Player::Facing::Down : Player::Facing::Up;
		if (abs(velocity.x) >= 0.0001)
			facing = (velocity.x > 0) ? Player::Facing::Right : Player::Facing::Left;

		switch (facing)
		{
		case Player::Facing::Up:	
			current_anim = &anim_run_up;
			break;
		case Player::Facing::Down:	
			current_anim = &anim_run_down;	
			break;
		case Player::Facing::Left:	
			current_anim = &anim_run_left;	
			break;
		case Player::Facing::Right: 
			current_anim = &anim_run_right; 
			break;
		}
	}

	if (!current_anim) return ;
	current_anim->on_update(delta);
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

void Player::refresh_new_target(double progress)
{
	const Path* path = GameManager::instance()->path;

	int idx_progress = path->get_idx_at_progress(progress);
	if (idx_progress == idx_target)
	{
		pos_target = path->get_position_at_progress(progress);
	}
	else
	{
		pos_target = path->get_point_list()[idx_target];
		idx_target++;
	}
}
