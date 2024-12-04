#include "ui/text_bar.h"
#include "manager/game_manager.h"
#include "manager/resources_manager.h"
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_ttf.h>
#include <vector>

void TextBar::set_position(int x, int y)
{
	position.x = x, position.y = y;
}

void TextBar::on_update(SDL_Renderer* renderer)
{
	static TTF_Font* font = ResourcesManager::instance()->get_font_pool().find(ResID::Font_Main)->second;
	
	static const int& idx_line = GameManager::instance()->idx_line;
	static const int& idx_char = GameManager::instance()->idx_char;
	static const std::vector<std::string>& str_line_list = GameManager::instance()->str_line_list;

	SDL_DestroyTexture(tex_text_background);
	tex_text_background = nullptr;
	SDL_DestroyTexture(tex_text_foreground);
	tex_text_foreground = nullptr;
	SDL_DestroyTexture(tex_text_completed);
	tex_text_completed = nullptr;

	std::string str_line = str_line_list[idx_line];
	SDL_Surface* suf_text_background = TTF_RenderText_Blended(font, str_line.c_str(), color_text_background);
	SDL_Surface* suf_text_foreground = TTF_RenderText_Blended(font, str_line.c_str(), color_text_foreground);
	SDL_Surface* suf_text_completed = TTF_RenderText_Blended(font, str_line.substr(0, idx_char).c_str(), color_text_completed);

	text_size.x = suf_text_background->w, text_size.y = suf_text_foreground->h;
	completed_text_size.x = suf_text_completed->w, completed_text_size.y = suf_text_completed->h;

	tex_text_background = SDL_CreateTextureFromSurface(renderer, suf_text_background);
	tex_text_foreground = SDL_CreateTextureFromSurface(renderer, suf_text_foreground);
	tex_text_completed = SDL_CreateTextureFromSurface(renderer, suf_text_completed);

	SDL_FreeSurface(suf_text_background);
	SDL_FreeSurface(suf_text_foreground);
	SDL_FreeSurface(suf_text_completed);
}

void TextBar::on_render(SDL_Renderer* renderer)
{
	static SDL_Rect rect_dst;

	rect_dst.x = position.x ,rect_dst.y = position.y;
	rect_dst.w = 1280, rect_dst.h = 120;
	SDL_RenderCopy(renderer, ResourcesManager::instance()->get_texture_pool().find(ResID::Tex_UI_Textbox)->second, nullptr, &rect_dst);

	rect_dst.x += 187, rect_dst.y += 67;
	rect_dst.w = text_size.x, rect_dst.h = text_size.y;
	SDL_RenderCopy(renderer, tex_text_background, nullptr, &rect_dst);

	rect_dst.x -= offset_shadow.x, rect_dst.y -= offset_shadow.y;
	SDL_RenderCopy(renderer, tex_text_foreground, nullptr, &rect_dst);
	
	rect_dst.w = completed_text_size.x, rect_dst.h = completed_text_size.y;
	SDL_RenderCopy(renderer, tex_text_completed, nullptr, &rect_dst);
}
