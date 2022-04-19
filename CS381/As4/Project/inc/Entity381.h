/*
 * Entity381.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <Aspect.h>
#include <vector>

class Aspect;
class Entity381 {
	public:
		Entity381(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~Entity381(void);
		void Tick(float dt);

		unsigned int m_entityID;
		std::string m_entityName;
		Ogre::Vector3 m_position;
		Ogre::Vector3 m_velocity;
		Ogre::SceneNode *m_ogreSceneNode;
		Ogre::Entity *m_ogreEntity;
		float m_speed;
		float m_speedMax;
		float m_speedDesired;
		float m_heading;
		float m_headingDesired;
		float m_acceleration;
		float m_turningRate;
		std::vector<Aspect*> m_aspects;

		void showBoundingBox(bool show);
//		void setVelocity(const Ogre::Vector3 &velocity, bool accumulate = true);
		void changeDesiredSpeed(float amount);
		void changeDesiredHeading(float amount);
		std::pair<float, float> getDesiredHeadingAndSpeed(void) const;


		//Entity381::EntityType
		enum EntityType {
			PolyPlane, CG47, CVN75, TUG, DDG51, CIGARETTE
		};

		friend class AspectPhysics;
		friend class AspectRenderable;
};


class PolyPlane: public Entity381 {
	public:
		PolyPlane(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~PolyPlane(void);

};

class CG47: public Entity381 {
	public:
		CG47(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~CG47(void);

};

class CVN75: public Entity381 {
	public:
		CVN75(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~CVN75(void);

};

class TUG: public Entity381 {
	public:
		TUG(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~TUG(void);

};

class CIGARETTE: public Entity381 {
	public:
		CIGARETTE(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~CIGARETTE(void);

};

class DDG51: public Entity381 {
	public:
		DDG51(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~DDG51(void);

};


#endif /* INC_ENTITY381_H_ */
