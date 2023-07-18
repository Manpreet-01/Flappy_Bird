#include "Game.h"
#include "Globals.h"


Game::Game(sf::RenderWindow& window): win(window)
{
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);   // x,y direction
	bg_sprite.setPosition(0.f, -250.f);   // x,y
	
	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);
	
	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);
	
	ground_sprite1.setPosition(0, 578);
	ground_sprite1.setPosition(ground_sprite1.getGlobalBounds().width, 578);
	
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
		
		draw();
		win.display();
	}
}


void Game::draw(){
	win.draw(bg_sprite);
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
}