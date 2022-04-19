/*
 * GameMgr.h
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_

#include <Mgr.h>
#include <OgreRoot.h>
//#include "CameraController.h"
//#include <OISMouse.h>

class EntityMgr;

class GameMgr: public Mgr {

public:
	GameMgr(Engine *engine);
	virtual ~GameMgr(void);
	virtual void Init(void) override final;
	virtual void LoadLevel(void) override final;
	virtual void Tick(float dt) override final;
	virtual void Stop(void) override final;
	void SetupSky(void);
	void SetupOcean(void);
	void SetupShips(void);
	void UpdateSelectedEntities(float dt);
	Ogre::SceneManager *m_graphics_scene_manager;
	EntityMgr *m_entity_mgr;
	float m_velocity_update_cooldown;
	int mSurfaceHeight;
};


#endif /* INC_GAMEMGR_H_ */
