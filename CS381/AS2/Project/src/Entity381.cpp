/*
 * Entity381.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include "Entity381.h"

Entity381::Entity381(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :entityID(id), entityName(name), position(position), velocity(velocity), ogreSceneNode(nullptr), ogreEntity(nullptr){

	ogreSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode(entityName, position);
	ogreSceneNode->scale(scale);
}

Entity381::~Entity381(void) {
}

void Entity381::showBoundingBox(bool show) {
	ogreSceneNode->showBoundingBox(show);
}

void Entity381::setVelocity(const Ogre::Vector3 &vel, bool spaceStop) {
	if (spaceStop)
		velocity += vel;
	else
		velocity = vel;
}

void Entity381::Tick(float dt) {
	this->position += this->velocity * dt;
	ogreSceneNode->setPosition(position);
}

PolyPlane::PolyPlane(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	ogreEntity = scene_manager->createEntity("PolyPlane.mesh");
	ogreSceneNode->attachObject(ogreEntity);

}

PolyPlane::~PolyPlane(void) {

}

CG47::CG47(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	ogreEntity = scene_manager->createEntity("cg47.mesh");
	ogreSceneNode->attachObject(ogreEntity);

}

CG47::~CG47(void) {

}

CVN75::CVN75(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	ogreEntity = scene_manager->createEntity("cvn75.mesh");
	ogreSceneNode->attachObject(ogreEntity);

}

CVN75::~CVN75(void) {

}


