/*
 * EntityMgr.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include <Entity381.h>
#include <vector>

class EntityMgr {

public:
	EntityMgr(Ogre::SceneManager *scene_manager);
	~EntityMgr(void);

	Entity381* CreateEntityOfType(const Entity381::EntityType type, const Ogre::Vector3 &position = Ogre::Vector3(0.f));
	bool selectNextEntity(void);
//	bool setEntityVelocity(const Ogre::Vector3 &velocity, bool accumulate = true);
	bool changeSelectedDesiredSpeed(float amount); //returns false if no selected entity
	bool changeSelectedDesiredHeading(float amount); //returns false if no selected entity
	bool resetSelectedSpeedAndHeading(void); //returns false if no selected entity
	void Tick(float dt);

	std::vector<Entity381*> m_entities;
	int m_selected;
	Ogre::SceneManager *m_scene_manager;

};




#endif /* INC_ENTITYMGR_H_ */
