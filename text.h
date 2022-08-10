#pragma once
#include <SDL.h>
#include <string>

enum struct Anchor {
	Center, TopLeft
};

class Text {
public:
	~Text();

	void render();
	void setAnchor(Anchor a);
	void setSize(int x);
	void setRenderPoint(SDL_Point point);
	int getWidth();
	int getHeight();

	void operator<<(std::string newText);
	void operator+=(char c);

private:
	void updateTexture();

	int fontSize = 22;
	Anchor anchor = Anchor::Center;
	SDL_Texture* texture = nullptr;
	std::string text;
	SDL_Rect rect;
};

std::string intToString(int n);