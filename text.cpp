#include <SDL.h>
#include <string>
#include <sstream>
#include <SDL_ttf.h>

#include "text.h"
#include "render.h"

using namespace std;

string fontPath = "assets\\fonts\\font.ttf";

string intToString(int n) {
	stringstream out;
	out << n;
	return out.str();
}

Text::~Text() {
	SDL_DestroyTexture(texture);
}

void Text::render() {
	SDL_RenderCopy(getRenderer(), texture, nullptr, &rect);
}

void Text::setAnchor(Anchor a) {
	anchor = a;
}

void Text::setSize(int x) {
	fontSize = x;
	updateTexture();
}

void Text::operator<<(std::string newText) {
	text = newText;
	updateTexture();
}

void Text::operator+=(char c) {
	text += c;
	updateTexture();
}

void Text::setRenderPoint(SDL_Point point) {
	if (anchor == Anchor::TopLeft) {
		rect.x = point.x;
		rect.y = point.y;
	}
	else if (anchor == Anchor::Center) {
		rect.x = point.x - rect.w / 2;
		rect.y = point.y - rect.h / 2;
	}
}

int Text::getWidth() {
	return rect.w;
}

int Text::getHeight() {
	return rect.h;
}

void Text::updateTexture() {
	SDL_Surface* loadingSurface;
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);

	if (texture != nullptr)
		SDL_DestroyTexture(texture);

	loadingSurface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), { 0xFF, 0xFF, 0xFF, 0xFF }, 600);
	texture = SDL_CreateTextureFromSurface(getRenderer(), loadingSurface);
	
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

	SDL_FreeSurface(loadingSurface);
	TTF_CloseFont(font);
}
