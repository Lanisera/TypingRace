#pragma once

#include "camera/camera.h"
#include "vector/vector2.h"
#include "animation/animation.h"
#include "manager/resources_manager.h"
#include <SDL_render.h>

class Player
{
public:
	enum class Facing
	{
		Up,
		Down,
		Left,
		Right,
		None
	};

public:
	Player(ResourcesManager::AnimTexList tex_list_idle_up, ResourcesManager::AnimTexList tex_list_idle_down, 
			ResourcesManager::AnimTexList tex_list_idle_left, ResourcesManager::AnimTexList tex_list_idle_right,
			ResourcesManager::AnimTexList tex_list_run_up, ResourcesManager::AnimTexList tex_list_run_down,
			ResourcesManager::AnimTexList tex_list_run_left, ResourcesManager::AnimTexList tex_list_run_right);
	
	~Player() = default;

	void on_update(double delta);

	void on_render(const Camera& camera, SDL_Renderer* renderer);

	void set_position(const Vector2& position);
	
	const Vector2& get_position() const;

protected:
	const double SPEED_RUN = 100;

private:
	Vector2 size;
	Vector2 position;
	Vector2 velocity;

	Vector2 pos_target;

	Animation anim_idle_up;
	Animation anim_idle_down;
	Animation anim_idle_left;
	Animation anim_idle_right;
	Animation anim_run_up;
	Animation anim_run_down;
	Animation anim_run_left;
	Animation anim_run_right;
	Animation* current_anim = nullptr;

	Facing facing = Facing::None;

};
