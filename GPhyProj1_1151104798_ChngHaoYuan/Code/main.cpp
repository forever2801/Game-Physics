/******************************************** 
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/2020
ID and Name #1 : 1151104798 Ch'ng Hao Yuan 
Contacts	#1 : 0164966076 haoyuan2801@gmail.com 
********************************************/

#include "main.h"

sf::RenderWindow App;
bool g_fullscreen;

int main() {
	g_fullscreen = false;
	//create the window
	App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), 
		             "10 Seconds Escape", !sf::Style::Resize | sf::Style::Close);
	World *game = new World();
	Player player = Player(game->getb2World(), game->getRes(0).img_player);
	Level level1(game->getb2World(), &player, game->getRes(0).img_background);

	//this is the start of the main game loop
	while (App.isOpen()) {
		game->getb2World()->Step(game->getTimeStep(), game->getVIterations(), game->getPIterations());
		//process any events
		sf::Event events;
		while (App.pollEvent(events)) {
			level1.input(events);
			switch (events.type) {
			case sf::Event::Closed:
				App.close(); //close application
				break;				
			case sf::Event::KeyPressed:
				//exit with escape
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					App.close();
				//fullscreen wih F11
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
					if (g_fullscreen == false) {
						App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "10Seconds", sf::Style::Fullscreen);
						g_fullscreen = true;
					} else {
						App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "10Seconds", !sf::Style::Resize | sf::Style::Close);
						g_fullscreen = false;
					}
				}
			}
		}
		App.clear(sf::Color(000,200,200));  //no color = black
		level1.update();
		level1.draw();
		//level1.update();
		App.display();//display window contents
	}
	delete game;
	return 0;
}
