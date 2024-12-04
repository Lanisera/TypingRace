#pragma once

#include "camera/camera.h"
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>

class TextBar
{
public:
	TextBar() = default;

	~TextBar() = default;

	void set_position(int x, int y);

	void on_update(SDL_Renderer* renderer);

	void on_render(const Camera& camera, SDL_Renderer* renderer);

private:
	const SDL_Point offset_shadow = {2, 2};
	const SDL_Color color_text_background = {125, 125, 125, 255};
	const SDL_Color color_text_foreground = {25, 25, 25, 255};
	const SDL_Color color_text_completed = {0, 149, 217, 255};

private:
	SDL_Point position = {0};
	SDL_Point text_size, completed_text_size;
	SDL_Texture* tex_text_background = nullptr;
	SDL_Texture* tex_text_foreground = nullptr;
	SDL_Texture* tex_text_completed = nullptr;
};
