/*
 * GfxMgr.h
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */


#ifndef GFXMGR_H_
#define GFXMGR_H_

#include <Mgr.h>
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

class GfxMgr: public Mgr {

	public:
		GfxMgr(Engine *engine);
		virtual ~GfxMgr(void);
		virtual void Init(void) override final;
		virtual void LoadLevel(void) override final;
		virtual void Tick(float dt) override final;
		virtual void Stop(void) override final;
		void setupResources(void);

		Ogre::RenderWindow* getRenderWindow(void);
		Ogre::SceneManager* getSceneManger(void);
		Ogre::Camera* getCamera(void);
		std::string m_windowName;
		Ogre::Root *m_root;
		std::string m_resources;
		std::string m_plugins;
		Ogre::RenderWindow *m_window;
		Ogre::SceneManager *m_SceneMgr;
		Ogre::Camera *m_Camera;
};

#endif
