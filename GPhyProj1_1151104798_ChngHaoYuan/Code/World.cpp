/******************************************** 
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/2020
ID and Name #1 : 1151104798 Ch'ng Hao Yuan 
Contacts	#1 : 0164966076 haoyuan2801@gmail.com 
********************************************/

#include "World.h"
#include <Box2D\Box2D.h>

//constructor
World::World() {
	gravity = b2Vec2(0.f, 9.8f);
	world = new b2World(gravity);
	timeStep = 1.0f / 180.0f;
    velocityIterations = 8;
    positionIterations = 3;
	//set resources
	res[0].img_background.loadFromFile("../res/hmm.jpg");
	res[0].img_player.loadFromFile("../res/player.png");
}

//mutators
void World::setWorld(b2World aWorld) {
//	world = aWorld;
}

//accessors
b2World *World::getb2World() {
	return world;
}

float World::getTimeStep() {
	return timeStep;
}

int World::getVIterations() {
	return velocityIterations;
}

int World::getPIterations() {
	return positionIterations;
}

LevelResources &World::getRes(int index) {
	return res[index];
}

//destructor
World::~World() {
	world = NULL;
	delete world;
	//delete res;
}
