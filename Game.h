#pragma once
#include<SFML/Graphics.hpp>

class Game{
	public:
		Game(sf::RenderWindow& window);		// pass reference
		sf::RenderWindow& win;
		void startGameLoop();
		
	private:
		sf::Texture bg_texture;
		sf::Sprite bg_sprite;
		void draw();
};