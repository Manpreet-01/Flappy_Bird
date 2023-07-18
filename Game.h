#pragma once
#include<SFML/Graphics.hpp>

class Game{
	public:
		Game(sf::RenderWindow& window);		// pass reference
		sf::RenderWindow& win;
		void startGameLoop();
		
	private:
		sf::Texture bg_texture, ground_texture;
		sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
		void draw();
};