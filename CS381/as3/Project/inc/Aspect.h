/*
 * aspect.h
 *
 *  Created on: Feb 18, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_ASPECT_H_
#define INC_ASPECT_H_

#include <OgreVector3.h>
#include <OgreEntity.h>
#include <Entity381.h>

class Entity381;

class Aspect {

public:
	Aspect(Entity381 *parent);
	virtual ~Aspect(void);
	virtual void Tick(float dt) = 0;

	Entity381 *m_parent_entity;

	enum aspectType {
		PHYSICS, RENDERABLE
	};

};

class AspectRenderable: public Aspect {

public:
	AspectRenderable(Entity381 *parent);
	virtual ~AspectRenderable(void);
	virtual void Tick(float dt) override final;
};

class AspectPhysics: public Aspect {

public:
	AspectPhysics(Entity381 *parent);
	virtual ~AspectPhysics(void);
	virtual void Tick(float dt) override final;
	float getNewHeading(float current, float desired, float max_change);
	float getNewSpeed(float current, float desired, float max_change);

	Ogre::Vector3 getVelocityInDirectionOfHeading(float heading, float speed);
};


#endif /* INC_ASPECT_H_ */
