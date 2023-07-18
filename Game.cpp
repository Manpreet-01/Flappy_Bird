#include "Game.h"

Game::Game(sf::RenderWindow& window): win(window)
{
	
}

	
void Game::startGameLoop(){
	// game loop
	while(win.isOpen()){
		sf::Event event;
		
		// event loop
		while(win.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				win.close();
			}
		}
		
		win.display();
	}
}