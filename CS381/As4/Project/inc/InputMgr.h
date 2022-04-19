/*
 * InputMgr.h
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_

#include <Mgr.h>
#include <EntityMgr.h>
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>

//#include <OISMouse.h>

class InputMgr: public Mgr, public Ogre::WindowEventListener, public OIS::KeyListener{

	public:
		InputMgr(Engine *engine);
		virtual ~InputMgr(void);
		virtual void Init(void) override final;
		virtual void LoadLevel(void) override final;
		virtual void Tick(float dt) override final;
		virtual void Stop(void) override final;
		bool IsKeyPressed(const OIS::KeyCode &key) const;
		virtual bool keyPressed(const OIS::KeyEvent &arg) override final;
		virtual bool keyReleased(const OIS::KeyEvent &arg) override final;
		virtual void windowResized(Ogre::RenderWindow *rw) override final;
		virtual void windowClosed(Ogre::RenderWindow *rw) override final;

		Ogre::RenderWindow *m_graphicsWindow;
		OIS::InputManager *m_inputMgr;
		OIS::Keyboard *m_keyboard;
		Ogre::Vector3 m_CameraVelocity;
		EntityMgr *m_entityMgr;
		Ogre::SceneManager *m_SceneMgr;
};



#endif /* INC_INPUTMGR_H_ */
