/*
 * Entity381.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include "OgreEntity.h"
#include "OgreSceneManager.h"
#include <vector>

class Entity381 {
	public:
//		Entity381(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
		Entity381(unsigned int id, const std::string &name, Ogre::SceneManager *scene_manager, const Ogre::Vector3 &position = Ogre::Vector3(0.f), const Ogre::Vector3 &scale = Ogre::Vector3(1.f), const Ogre::Vector3 &velocity = Ogre::Vector3(0.f));
		virtual ~Entity381(void);
		void Tick(float dt);

		unsigned int entityID;
		std::string entityName;
		Ogre::Vector3 position;
		Ogre::Vector3 velocity;
		Ogre::SceneNode *ogreSceneNode;
		Ogre::Entity *ogreEntity;
		void showBoundingBox(bool show);
		void setVelocity(const Ogre::Vector3 &velocity, bool accumulate = true);


		//Entity381::EntityType
		enum EntityType {
			PolyPlane, CG47, CVN75
		};


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


#endif /* INC_ENTITY381_H_ */
