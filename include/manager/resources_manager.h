#pragma once

#include "manager/manager.h"
#include <SDL_render.h>
#include <unordered_map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

enum class ResID
{
	Font_Main,

	Sound_Hajimi_Win,
	Sound_Manbo_Win,
	Sound_UI_1,
	Sound_UI_2,
	Sound_UI_3,
	Sound_UI_Fight,

	Music_BGM,

	Tex_Background,
	Tex_UI_1,
	Tex_UI_2,
	Tex_UI_3,
	Tex_UI_Fight,

	Anim_Hajimi_Idle_Up,
	Anim_Hajimi_Idle_Down,
	Anim_Hajimi_Idle_Left,
	Anim_Hajimi_Idle_Right,
	Anim_Hajimi_Run_Up,
	Anim_Hajimi_Run_Down,
	Anim_Hajimi_Run_Left,
	Anim_Hajimi_Run_Right,
	Anim_Manbo_Idle_Up,
	Anim_Manbo_Idle_Down,
	Anim_Manbo_Idle_Left,
	Anim_Manbo_Idle_Right,
	Anim_Manbo_Run_Up,
	Anim_Manbo_Run_Down,
	Anim_Manbo_Run_Left,
	Anim_Manbo_Run_Right,
};

class ResourcesManager : public Manager<ResourcesManager>
{
	friend class Manager<ResourcesManager>;
public:
	using AnimTexList = std::vector<SDL_Texture*>;
	using FontPool = std::unordered_map<ResID, TTF_Font*>;
	using SoundPool = std::unordered_map<ResID, Mix_Chunk*>;
	using MusicPool = std::unordered_map<ResID, Mix_Music*>;
	using TexturePool = std::unordered_map<ResID, SDL_Texture*>;
	using AnimTexListPool = std::unordered_map<ResID, AnimTexList>;

public:
	bool load_resources_from_file(SDL_Renderer* renderer);

	const FontPool& get_font_pool() const;

	const SoundPool& get_sound_pool() const;

	const MusicPool& get_music_pool() const;

	const TexturePool& get_texture_pool() const;

	const AnimTexListPool& get_anim_tex_list_pool() const;

protected:
	ResourcesManager() = default;

	~ResourcesManager() = default;

private:
	FontPool font_pool;
	SoundPool sound_pool;
	MusicPool music_pool;
	TexturePool texture_pool;
	AnimTexListPool anim_tex_list_pool;
};
