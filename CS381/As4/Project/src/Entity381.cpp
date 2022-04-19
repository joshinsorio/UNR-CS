/*
 * Entity381.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <Entity381.h>

Entity381::Entity381(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) : m_entityID(id), m_entityName(name), m_position(position), m_velocity(velocity), m_ogreSceneNode(nullptr), m_ogreEntity(nullptr), m_speed(0), m_speedMax(0), m_speedDesired(0), m_heading(0),
m_headingDesired(0), m_acceleration(0), m_turningRate(0){
	m_ogreSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode(m_entityName, position);
	m_ogreSceneNode->scale(scale);
}

Entity381::~Entity381(void) {
	for (Aspect *a : m_aspects)
			delete a;
}

void Entity381::showBoundingBox(bool show) {
	m_ogreSceneNode->showBoundingBox(show);
}

//void Entity381::setVelocity(const Ogre::Vector3 &vel, bool spaceStop) {
//	if (spaceStop)
//		velocity += vel;
//	else
//		velocity = vel;
//}

void Entity381::changeDesiredSpeed(float amount) {
	m_speedDesired += amount;

	if (m_speedDesired < 0)
		m_speedDesired = 0;
	else if (m_speedDesired > m_speedMax)
		m_speedDesired = m_speedMax;
}

void Entity381::changeDesiredHeading(float amount) {
	amount = std::fmod(amount, 360); //account for possibility of use giving more than 1 full rotation
	m_headingDesired += amount;

	if (m_headingDesired < 0)
		m_headingDesired += 360;
	else if (m_headingDesired >= 360)
		m_headingDesired -= 360;
}

std::pair<float, float> Entity381::getDesiredHeadingAndSpeed(void) const {
	return std::make_pair(m_headingDesired, m_speedDesired);
}

void Entity381::Tick(float dt) {
//	this->m_position += this->m_velocity * dt;
//	m_ogreSceneNode->setPosition(m_position);
	for (Aspect *a : m_aspects)
			a->Tick(dt);
}

PolyPlane::PolyPlane(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("PolyPlane.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 150.f;
	m_acceleration = 100.f;
	m_turningRate = 30.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

PolyPlane::~PolyPlane(void) {

}

CG47::CG47(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("cg47.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 200.f;
	m_acceleration = 175.f;
	m_turningRate = 50.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

CG47::~CG47(void) {

}

CVN75::CVN75(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("cvn75.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 50.f;
	m_acceleration = 50.f;
	m_turningRate = 10.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

CVN75::~CVN75(void) {

}

TUG::TUG(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("tug.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 500.f;
	m_acceleration = 200.f;
	m_turningRate = 60.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

TUG::~TUG(void) {

}

CIGARETTE::CIGARETTE(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("cigarette-V2.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 700.f;
	m_acceleration = 250.f;
	m_turningRate = 10.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

CIGARETTE::~CIGARETTE(void) {

}

DDG51::DDG51(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position, const Ogre::Vector3 &scale, const Ogre::Vector3 &velocity) :
	Entity381(id, name, scene_manager, position, scale, velocity) {

	m_ogreEntity = scene_manager->createEntity("ddg51-v2.mesh");
	m_ogreSceneNode->attachObject(m_ogreEntity);

	m_speedMax = 1000.f;
	m_acceleration = 100.f;
	m_turningRate = 35.f;

	m_aspects.push_back(new AspectPhysics(this));
	m_aspects.push_back(new AspectRenderable(this));

}

DDG51::~DDG51(void) {

}




