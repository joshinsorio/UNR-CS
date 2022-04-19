/*
 * InputMgr.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <InputMgr.h>
#include <Engine.h>
#include <GfxMgr.h>
#include <GameMgr.h>
#include <OgreRenderWindow.h>

InputMgr::InputMgr(Engine *engine) :
	Mgr(engine), m_graphicsWindow(nullptr), m_inputMgr(nullptr), m_keyboard(nullptr), m_entityMgr(nullptr), m_SceneMgr(nullptr){
}

InputMgr::~InputMgr(void) {

}

void InputMgr::Init(void) {
	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
	OIS::ParamList pl;
	std::size_t window_handle = 0;
	std::ostringstream window_handle_str;

	m_entityMgr = engine->entityMgr;
	m_graphicsWindow = engine->gfxMgr->getRenderWindow();

	m_graphicsWindow->getCustomAttribute("WINDOW", &window_handle);
	window_handle_str << window_handle;
	m_SceneMgr = engine->gfxMgr->getSceneManger();

	pl.insert(std::make_pair(std::string("WINDOW"), window_handle_str.str()));
	#if defined OIS_WIN32_PLATFORM
		pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
		pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
	#elif defined OIS_LINUX_PLATFORM
		pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
		pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
		pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
		pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
	#endif
		m_inputMgr = OIS::InputManager::createInputSystem(pl);

	Ogre::LogManager::getSingletonPtr()->logMessage("*** OIS Initialized ***");
}

void InputMgr::LoadLevel(void) {
	//True because original implementation is buffered
	m_keyboard = static_cast<OIS::Keyboard*>(m_inputMgr->createInputObject(OIS::OISKeyboard, true));

	m_keyboard->setEventCallback(this);

	windowResized(m_graphicsWindow);
	Ogre::WindowEventUtilities::addWindowEventListener(m_graphicsWindow, this);
}

void InputMgr::Tick(float dt) {
	m_keyboard->capture();
	m_SceneMgr->getSceneNode("camNode")->translate(m_CameraVelocity * dt, Ogre::Node::TS_LOCAL);
}

void InputMgr::Stop(void) {
	windowClosed(m_graphicsWindow);
}

bool InputMgr::IsKeyPressed(const OIS::KeyCode &key) const {
	return m_keyboard->isKeyDown(key);
}

bool InputMgr::keyPressed(const OIS::KeyEvent &arg) {
	const float VELOCITY_CHANGE = 25;
	const float HEADING_CHANGE = 20;

		switch (arg.key) {
			case OIS::KC_Q:
				engine->keepRunning = false;
				break;

			case OIS::KC_DOWN:
				m_entityMgr->changeSelectedDesiredSpeed(-VELOCITY_CHANGE);
				break;

			case OIS::KC_UP:
				m_entityMgr->changeSelectedDesiredSpeed(VELOCITY_CHANGE);
				break;

			case OIS::KC_RIGHT:
				m_entityMgr->changeSelectedDesiredHeading(-HEADING_CHANGE);
				break;

			case OIS::KC_LEFT:
				m_entityMgr->changeSelectedDesiredHeading(HEADING_CHANGE);
				break;

			case OIS::KC_TAB:
				m_entityMgr->selectNextEntity();
				break;

			case OIS::KC_A:
				if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
					m_SceneMgr->getSceneNode("camNode")->yaw(Ogre::Degree(5));
				else
					m_CameraVelocity.x -= 600;
				break;

			case OIS::KC_D:
				if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
					m_SceneMgr->getSceneNode("camNode")->yaw(Ogre::Degree(-5));
				else
					m_CameraVelocity.x += 600;
				break;

			case OIS::KC_W:
				if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
					m_SceneMgr->getSceneNode("camNode")->pitch(Ogre::Degree(5));
				else
					m_CameraVelocity.z -= 600;
				break;

			case OIS::KC_S:
				if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
					m_SceneMgr->getSceneNode("camNode")->pitch(Ogre::Degree(-5));
				else
					m_CameraVelocity.z += 600;
				break;

			case OIS::KC_E:
				m_CameraVelocity.y += 600;
				break;

			case OIS::KC_F:
				m_CameraVelocity.y -= 600;
				break;

			default:
				break;
			}

	return true;
}

bool InputMgr::keyReleased(const OIS::KeyEvent &arg) {
	switch (arg.key) {

		case OIS::KC_A:
			if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
			{}
			else
				m_CameraVelocity.x += 600;
			break;

		case OIS::KC_D:
			if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
			{}
			else
				m_CameraVelocity.x -= 600;
			break;

		case OIS::KC_W:
			if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
			{}
			else
				m_CameraVelocity.z += 600;
			break;

		case OIS::KC_S:
			if (m_keyboard->isKeyDown(OIS::KC_LSHIFT))
			{}
			else
				m_CameraVelocity.z -= 600;
			break;

		case OIS::KC_E:
			m_CameraVelocity.y -= 600;
			break;

		case OIS::KC_F:
			m_CameraVelocity.y += 600;
			break;

		default:
			break;
		}
	return true;
}

void InputMgr::windowResized(Ogre::RenderWindow *rw) {
	int left, top;
	unsigned int width, height, depth;

	rw->getMetrics(width, height, depth, left, top);
}

void InputMgr::windowClosed(Ogre::RenderWindow *rw) {
	if (rw == m_graphicsWindow) {
		if (m_inputMgr) {
			m_inputMgr->destroyInputObject(m_keyboard);

			OIS::InputManager::destroyInputSystem(m_inputMgr);
			m_inputMgr = nullptr;
			m_keyboard = nullptr;
		}
	}
}


