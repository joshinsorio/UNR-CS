/*
 * aspect.cpp
 *
 *  Created on: Feb 18, 2022
 *      Author: joshua insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <Aspect.h>

Aspect::Aspect(Entity381 *parent) :
	m_parentEntity(parent) {
}

Aspect::~Aspect(void) {
}


AspectRenderable::AspectRenderable(Entity381 *parent) :
	Aspect(parent) {
}

AspectRenderable::~AspectRenderable(void) {

}

void AspectRenderable::Tick(float dt) {
	m_parentEntity->m_ogreSceneNode->setPosition(m_parentEntity->m_position);

	float yaw = m_parentEntity->m_ogreSceneNode->getOrientation().getYaw().valueDegrees(); //get current yaw (-180,180)
	if (yaw < 0)
		yaw += 360; //get into range [0, 360)
	yaw = m_parentEntity->m_heading - yaw;

	m_parentEntity->m_ogreSceneNode->yaw(Ogre::Degree(yaw), Ogre::Node::TransformSpace::TS_WORLD);
}


AspectPhysics::AspectPhysics(Entity381 *parent) :
	Aspect(parent) {
}

AspectPhysics::~AspectPhysics(void) {

}

void AspectPhysics::Tick(float dt) {
	m_parentEntity->m_heading = getNewHeading(m_parentEntity->m_heading, m_parentEntity->m_headingDesired, m_parentEntity->m_turningRate * dt);
	m_parentEntity->m_speed = getNewSpeed(m_parentEntity->m_speed, m_parentEntity->m_speedDesired, m_parentEntity->m_acceleration * dt);
	m_parentEntity->m_velocity = getVelocityInDirectionOfHeading(m_parentEntity->m_heading, m_parentEntity->m_speed);
	m_parentEntity->m_position += m_parentEntity->m_velocity * dt;
}

float AspectPhysics::getNewHeading(float current, float desired, float max_change) {
	float new_heading;
	float checker = desired - current;

	//Fix jitter
	if(abs(checker) < 1)
		return current;

	// Turning clockwise
	if(desired > current){
		if(desired - current > 180){
			new_heading = current - max_change;
		}
		else{
			new_heading = current + max_change;
		}
	}

	// Counter-clockwise
	else if (desired < current){
		if(desired - current < -180){
			new_heading = current + max_change;
		}
		else{
			new_heading = current - max_change;
		}
	}

	// Fix angle being < 0 or > 360
	new_heading = new_heading > 0 ? new_heading < 360 ? new_heading : new_heading - 360 : new_heading + 360;

	return new_heading;
}

float AspectPhysics::getNewSpeed(float current, float desired, float max_change) {

	float new_speed = 0.f;
	if (current < desired)
		{
		new_speed = current + max_change;

		}
	else if (current > desired)
		{
		new_speed = current - max_change;

		}

	return new_speed;
}

Ogre::Vector3 AspectPhysics::getVelocityInDirectionOfHeading(float heading, float speed) {
	Ogre::Vector3 velocity(0.f);

	velocity.z = -std::sin(heading * M_PI / 180) * speed;
	velocity.x = std::cos(heading * M_PI / 180) * speed;

	return velocity;
}



