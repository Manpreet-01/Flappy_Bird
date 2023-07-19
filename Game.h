#pragma once
#include<SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Bird.h"
#include "Pipe.h"

class Game{
	public:
		Game(sf::RenderWindow&);		// pass reference
		sf::RenderWindow& win;
		void startGameLoop();
		
	private:
		sf::Texture bg_texture, ground_texture;
		sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
		Bird bird;
		bool is_enter_pressed, run_game, start_monitoring;
		const int move_speed=270;
		void draw();
		void moveGround(sf::Time&);
		void doProcessing(sf::Time& dt);
		void checkCollisions();
		void restartGame();
		void checkScores();
		int pipe_counter, pipe_spawn_time, score;
		std::vector<Pipe> pipes;
		std::string toString(int);
		sf::Font font;
		sf::Text restart_text, score_text;
		
		std::random_device rd;															// seed for random no.
		std::uniform_int_distribution<int> dist{250, 550};  // random no. generator
};