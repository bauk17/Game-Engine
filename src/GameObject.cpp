#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
#include "Game.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {

	
	objTexture = TextureManager::LoadTexture(textureSheet);


	if (objTexture == nullptr) {
		std::cerr << "Failed to load texture: " << textureSheet << std::endl;
	}
	xpos = x;
	ypos = y;

}


void GameObject::Update(int h, int w) {
	
	xpos++;
	ypos++;

	srcRect.h = h;
	srcRect.w = w;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;


}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}