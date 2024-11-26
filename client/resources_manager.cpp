#include "manager/resources_manager.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <utility>

bool ResourcesManager::load_resources_from_file(SDL_Renderer* renderer)
{
	texture_pool[ResID::Tex_Background] = IMG_LoadTexture(renderer, "../resources/background.png");
	texture_pool[ResID::Tex_UI_1] = IMG_LoadTexture(renderer, "../resources/ui_1.png");
	texture_pool[ResID::Tex_UI_2] = IMG_LoadTexture(renderer, "../resources/ui_2.png");
	texture_pool[ResID::Tex_UI_3] = IMG_LoadTexture(renderer, "../resources/ui_3.png");
	texture_pool[ResID::Tex_UI_Fight] = IMG_LoadTexture(renderer, "../resources/ui_fight.png");

	for (const auto& pair : texture_pool)
		if (pair.second == nullptr)
			return false;

	AnimTexList hajimi_idle_back(4);
	hajimi_idle_back[0] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_back_1.png");
	hajimi_idle_back[1] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_back_2.png");
	hajimi_idle_back[2] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_back_3.png");
	hajimi_idle_back[3] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_back_4.png");
	
	for (const auto& x : hajimi_idle_back)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Idle_Up] = std::move(hajimi_idle_back);

	AnimTexList hajimi_idle_front(4);
	hajimi_idle_front[0] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_front_1.png");
	hajimi_idle_front[1] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_front_2.png");
	hajimi_idle_front[2] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_front_3.png");
	hajimi_idle_front[3] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_front_4.png");
	
	for (const auto& x : hajimi_idle_front)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Idle_Down] = std::move(hajimi_idle_front);

	AnimTexList hajimi_idle_left(4);
	hajimi_idle_left[0] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_left_1.png");
	hajimi_idle_left[1] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_left_2.png");
	hajimi_idle_left[2] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_left_3.png");
	hajimi_idle_left[3] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_left_4.png");
	
	for (const auto& x : hajimi_idle_left)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Idle_Left] = std::move(hajimi_idle_left);

	AnimTexList hajimi_idle_right(4);
	hajimi_idle_right[0] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_right_1.png");
	hajimi_idle_right[1] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_right_2.png");
	hajimi_idle_right[2] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_right_3.png");
	hajimi_idle_right[3] = IMG_LoadTexture(renderer, "../resources/hajimi_idle_right_4.png");
	
	for (const auto& x : hajimi_idle_right)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Idle_Right] = std::move(hajimi_idle_right);

	AnimTexList hajimi_run_back(4);
	hajimi_run_back[0] = IMG_LoadTexture(renderer, "../resources/hajimi_run_back_1.png");
	hajimi_run_back[1] = IMG_LoadTexture(renderer, "../resources/hajimi_run_back_2.png");
	hajimi_run_back[2] = IMG_LoadTexture(renderer, "../resources/hajimi_run_back_3.png");
	hajimi_run_back[3] = IMG_LoadTexture(renderer, "../resources/hajimi_run_back_4.png");
	
	for (const auto& x : hajimi_run_back)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Run_Up] = std::move(hajimi_run_back);

	AnimTexList hajimi_run_front(4);
	hajimi_run_front[0] = IMG_LoadTexture(renderer, "../resources/hajimi_run_front_1.png");
	hajimi_run_front[1] = IMG_LoadTexture(renderer, "../resources/hajimi_run_front_2.png");
	hajimi_run_front[2] = IMG_LoadTexture(renderer, "../resources/hajimi_run_front_3.png");
	hajimi_run_front[3] = IMG_LoadTexture(renderer, "../resources/hajimi_run_front_4.png");
	
	for (const auto& x : hajimi_run_front)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Run_Down] = std::move(hajimi_run_front);

	AnimTexList hajimi_run_left(4);
	hajimi_run_left[0] = IMG_LoadTexture(renderer, "../resources/hajimi_run_left_1.png");
	hajimi_run_left[1] = IMG_LoadTexture(renderer, "../resources/hajimi_run_left_2.png");
	hajimi_run_left[2] = IMG_LoadTexture(renderer, "../resources/hajimi_run_left_3.png");
	hajimi_run_left[3] = IMG_LoadTexture(renderer, "../resources/hajimi_run_left_4.png");
	
	for (const auto& x : hajimi_run_left)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Run_Left] = std::move(hajimi_run_left);

	AnimTexList hajimi_run_right(4);
	hajimi_run_right[0] = IMG_LoadTexture(renderer, "../resources/hajimi_run_right_1.png");
	hajimi_run_right[1] = IMG_LoadTexture(renderer, "../resources/hajimi_run_right_2.png");
	hajimi_run_right[2] = IMG_LoadTexture(renderer, "../resources/hajimi_run_right_3.png");
	hajimi_run_right[3] = IMG_LoadTexture(renderer, "../resources/hajimi_run_right_4.png");
	
	for (const auto& x : hajimi_run_right)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Hajimi_Run_Right] = std::move(hajimi_run_right);

	AnimTexList manbo_idle_back(4);
	manbo_idle_back[0] = IMG_LoadTexture(renderer, "../resources/manbo_idle_back_1.png");
	manbo_idle_back[1] = IMG_LoadTexture(renderer, "../resources/manbo_idle_back_2.png");
	manbo_idle_back[2] = IMG_LoadTexture(renderer, "../resources/manbo_idle_back_3.png");
	manbo_idle_back[3] = IMG_LoadTexture(renderer, "../resources/manbo_idle_back_4.png");
	
	for (const auto& x : manbo_idle_back)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Idle_Up] = std::move(manbo_idle_back);

	AnimTexList manbo_idle_front(4);
	manbo_idle_front[0] = IMG_LoadTexture(renderer, "../resources/manbo_idle_front_1.png");
	manbo_idle_front[1] = IMG_LoadTexture(renderer, "../resources/manbo_idle_front_2.png");
	manbo_idle_front[2] = IMG_LoadTexture(renderer, "../resources/manbo_idle_front_3.png");
	manbo_idle_front[3] = IMG_LoadTexture(renderer, "../resources/manbo_idle_front_4.png");
	
	for (const auto& x : manbo_idle_front)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Idle_Down] = std::move(manbo_idle_front);

	AnimTexList manbo_idle_left(4);
	manbo_idle_left[0] = IMG_LoadTexture(renderer, "../resources/manbo_idle_left_1.png");
	manbo_idle_left[1] = IMG_LoadTexture(renderer, "../resources/manbo_idle_left_2.png");
	manbo_idle_left[2] = IMG_LoadTexture(renderer, "../resources/manbo_idle_left_3.png");
	manbo_idle_left[3] = IMG_LoadTexture(renderer, "../resources/manbo_idle_left_4.png");
	
	for (const auto& x : manbo_idle_left)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Idle_Left] = std::move(manbo_idle_left);

	AnimTexList manbo_idle_right(4);
	manbo_idle_right[0] = IMG_LoadTexture(renderer, "../resources/manbo_idle_right_1.png");
	manbo_idle_right[1] = IMG_LoadTexture(renderer, "../resources/manbo_idle_right_2.png");
	manbo_idle_right[2] = IMG_LoadTexture(renderer, "../resources/manbo_idle_right_3.png");
	manbo_idle_right[3] = IMG_LoadTexture(renderer, "../resources/manbo_idle_right_4.png");
	
	for (const auto& x : manbo_idle_right)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Idle_Right] = std::move(manbo_idle_right);

	AnimTexList manbo_run_back(4);
	manbo_run_back[0] = IMG_LoadTexture(renderer, "../resources/manbo_run_back_1.png");
	manbo_run_back[1] = IMG_LoadTexture(renderer, "../resources/manbo_run_back_2.png");
	manbo_run_back[2] = IMG_LoadTexture(renderer, "../resources/manbo_run_back_3.png");
	manbo_run_back[3] = IMG_LoadTexture(renderer, "../resources/manbo_run_back_4.png");
	
	for (const auto& x : manbo_run_back)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Run_Up] = std::move(manbo_run_back);

	AnimTexList manbo_run_front(4);
	manbo_run_front[0] = IMG_LoadTexture(renderer, "../resources/manbo_run_front_1.png");
	manbo_run_front[1] = IMG_LoadTexture(renderer, "../resources/manbo_run_front_2.png");
	manbo_run_front[2] = IMG_LoadTexture(renderer, "../resources/manbo_run_front_3.png");
	manbo_run_front[3] = IMG_LoadTexture(renderer, "../resources/manbo_run_front_4.png");
	
	for (const auto& x : manbo_run_front)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Run_Down] = std::move(manbo_run_front);

	AnimTexList manbo_run_left(4);
	manbo_run_left[0] = IMG_LoadTexture(renderer, "../resources/manbo_run_left_1.png");
	manbo_run_left[1] = IMG_LoadTexture(renderer, "../resources/manbo_run_left_2.png");
	manbo_run_left[2] = IMG_LoadTexture(renderer, "../resources/manbo_run_left_3.png");
	manbo_run_left[3] = IMG_LoadTexture(renderer, "../resources/manbo_run_left_4.png");
	
	for (const auto& x : manbo_run_left)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Run_Left] = std::move(manbo_run_left);

	AnimTexList manbo_run_right(4);
	manbo_run_right[0] = IMG_LoadTexture(renderer, "../resources/manbo_run_right_1.png");
	manbo_run_right[1] = IMG_LoadTexture(renderer, "../resources/manbo_run_right_2.png");
	manbo_run_right[2] = IMG_LoadTexture(renderer, "../resources/manbo_run_right_3.png");
	manbo_run_right[3] = IMG_LoadTexture(renderer, "../resources/manbo_run_right_4.png");
	
	for (const auto& x : manbo_run_right)
		if (x == nullptr)
			return false;

	anim_tex_list_pool[ResID::Anim_Manbo_Run_Right] = std::move(manbo_run_right);

	sound_pool[ResID::Sound_Hajimi_Win] = Mix_LoadWAV("../resources/1p_win.wav");
	sound_pool[ResID::Sound_Manbo_Win] = Mix_LoadWAV("../resources/2p_win.wav");
	sound_pool[ResID::Sound_UI_1] = Mix_LoadWAV("../resources/ui_1.wav");
	sound_pool[ResID::Sound_UI_2] = Mix_LoadWAV("../resources/ui_2.wav");
	sound_pool[ResID::Sound_UI_3] = Mix_LoadWAV("../resources/ui_3.wav");
	sound_pool[ResID::Sound_UI_Fight] = Mix_LoadWAV("../resources/ui_fight.wav");

	for (const auto& pair : sound_pool)
		if (pair.second == nullptr)
			return false;

	music_pool[ResID::Music_BGM] = Mix_LoadMUS("../resources/bgm.mp3");

	for (const auto& pair : music_pool)
		if (pair.second == nullptr)
			return false;

	font_pool[ResID::Font_Main] = TTF_OpenFont("../resources/IPix.ttf", 32);

	for (const auto& pair : font_pool)
		if (pair.second == nullptr)
			return false;

	return true;
}

const ResourcesManager::FontPool& ResourcesManager::get_font_pool() const
{
	return font_pool;
}

const ResourcesManager::SoundPool& ResourcesManager::get_sound_pool() const
{
	return sound_pool;
}

const ResourcesManager::MusicPool& ResourcesManager::get_music_pool() const
{
	return music_pool;
}

const ResourcesManager::TexturePool& ResourcesManager::get_texture_pool() const
{
	return texture_pool;
}

const ResourcesManager::AnimTexListPool& ResourcesManager::get_anim_tex_list_pool() const
{
	return anim_tex_list_pool;
}
