#ifndef Game_h
#include "Game.h"
#include "GameObject.h"
#include "Map.h"
#include <SDL.h>
#include <SDL_image.h>




GameObject* player;
GameObject* enemy;
Map* map;
SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initialized!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;

		}

		isRunning = true;

		player = new GameObject("assets/player.png", 0, 0);
		enemy = new GameObject("assets/enemyGround.png", 100, 100);
		map = new Map();
		
	}

	
	else {
		isRunning = false;
	}
	
}

void Game::handleEvents() {
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		

		default: 
			break;
		};
}

void Game::update() {
	

	player->Update(78, 58);
	enemy->Update(40, 40);
	
	
}

void Game::render() {
	SDL_RenderClear(renderer);

	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);

	// Where stuffs will be rendered

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Cleaned" << std::endl;
}

#endif