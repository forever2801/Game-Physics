/******************************************** 
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/2020
ID and Name #1 : 1151104798 Ch'ng Hao Yuan 
Contacts	#1 : 0164966076 haoyuan2801@gmail.com 
********************************************/

#ifndef MAIN_H
#define MAIN_H

//pre-defined headers
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
//mydefined headers
#include "Level.h"
#include "World.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32; 
const int gameTime = 10;
const int RATIO = 30;

extern sf::RenderWindow App;

#endif