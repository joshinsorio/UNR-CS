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
#include <Engine.h>
#include <GfxMgr.h>
#include <Mgr.h>
#include <vector>

class EntityMgr: public Mgr {

public:
	EntityMgr(Engine *engine);
	virtual ~EntityMgr(void);

	virtual void Init(void) override final;
	virtual void LoadLevel(void) override final;
	virtual void Stop(void) override final;
	Entity381* CreateEntityOfType(const Entity381::EntityType type, const Ogre::Vector3 &position = Ogre::Vector3(0.f));
	bool selectNextEntity(void);
	bool changeSelectedDesiredSpeed(float amount); //returns false if no selected entity
	bool changeSelectedDesiredHeading(float amount); //returns false if no selected entity
	bool resetSelectedSpeedAndHeading(void); //returns false if no selected entity
	void Tick(float dt);

	std::vector<Entity381*> m_entities;
	int m_selected;
	Ogre::SceneManager *m_scene_manager;


};




#endif /* INC_ENTITYMGR_H_ */
