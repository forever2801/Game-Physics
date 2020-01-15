/******************************************** 
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/2020
ID and Name #1 : 1151104798 Ch'ng Hao Yuan 
Contacts	#1 : 0164966076 haoyuan2801@gmail.com 
********************************************/


#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

//namespace Game {
class Player {
	
private:
	bool right, left, down, up;
	
	float offset;
	
	aBody playerBody;
	
	b2World *world; 
	
	sf::Texture selfImage; //load from World
	
	float xpos;
	
	float ypos;
	
	float xorigin;
	
	float yorigin;
	
	sf::Color fill;
	
public:
	//con/destructors
	Player(b2World *aWorld, sf::Image &image); 
	~Player(); 
	//mutators
	
	void setup(b2World &aworld);
	//enacse the player with Box2D Dynamics
	
	void setSelfBox();
	
	void playerbump(); //bump off wall
	
	void input(sf::Event events); //move
	
	void draw();
	
	void SetPosition(float x, float y);
	
	void update();
	
	void jump(int dir);
	//accessors
};
//}

#endif