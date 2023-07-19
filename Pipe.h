#pragma once

#include <SFML/Graphics.hpp>

class Pipe{
		public:
			Pipe(int);
			sf::Sprite sprite_up, sprite_down;
			void update(sf::Time&);
			float getRightBound();
			static void loadTextures();						// static
			
		private:
			static sf::Texture texture_up, texture_down;		//static
			static int pipe_distance, move_speed;						//static
};