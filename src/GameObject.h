#pragma once
#include <SDL.h> // Necessário para o uso de SDL_Texture e SDL_Rect

class GameObject {

public:
    GameObject(const char* textureSheet, int x, int y);  // Passa SDL_Renderer por argumento
    ~GameObject();

    void Update(int h, int w);
    void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    
};
