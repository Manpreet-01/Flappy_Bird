#include "Game.h"
#include "Globals.h"

const int ground_y = 578;

Game::Game(sf::RenderWindow& window): win(window),
is_enter_pressed(false),
run_game(true),
pipe_counter(71),
pipe_spawn_time(70)
{
	win.setFramerateLimit(60);
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);   // x,y direction
	bg_sprite.setPosition(0.f, -250.f);   // x,y
	
	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);
	
	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);
	
	ground_sprite1.setPosition(0, ground_y);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, ground_y);
	
	Pipe::loadTextures();
}

void Game::doProcessing(sf::Time& dt){
	if(is_enter_pressed){
		moveGround(dt);
		if(pipe_counter > pipe_spawn_time){
			pipes.push_back(Pipe(dist(rd)));    //push random no.
			pipe_counter = 0;
		}
		
		pipe_counter++;
		
		for(int i=0; i<pipes.size(); i++){
			pipes[i].update(dt);
			if(pipes[i].getRightBound() < 0){
				pipes.erase(pipes.begin() + i);     // erase ith index pipe
			}
		}
	}
	
	bird.update(dt);
}

void Game::startGameLoop(){
	sf::Clock clock;
	// game loop
	while(win.isOpen()){
		sf::Time dt = clock.restart();  // return last frame consumed time and set new time to 0
		sf::Event event;
		
		// event loop
		while(win.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				// win.close();
			}
			if(event.type == sf::Event::KeyPressed && run_game){
				if(event.key.code == sf::Keyboard::Enter && !is_enter_pressed){
					is_enter_pressed = true;
					bird.setShouldFly(true);
				}
				if(event.key.code == sf::Keyboard::Space && is_enter_pressed){
					bird.flapBird(dt);
				}
			}
		}
		
		doProcessing(dt);
		draw();
		win.display();
	}
}


void Game::draw(){
	win.draw(bg_sprite);
	for(Pipe& pipe : pipes){
		win.draw(pipe.sprite_down);
		win.draw(pipe.sprite_up);
	}
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
	win.draw(bird.bird_sprite);			// because inside bird object of class Bird
}

void Game::moveGround(sf::Time& dt){
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);
	
	if(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0){
		int posx = ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width;
		ground_sprite1.setPosition(posx, ground_y);
	}
	
	if(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0){
		int posx = ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width;
		ground_sprite2.setPosition(posx, ground_y);
	}
}







