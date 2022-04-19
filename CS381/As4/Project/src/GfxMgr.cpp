/*
 * GfxMgr.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <GfxMgr.h>
#include <Engine.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <assert.h>

GfxMgr::GfxMgr(Engine *engine) :
	Mgr(engine), m_windowName("Main_Window"), m_root(nullptr), m_resources("resources.cfg"), m_plugins("plugins.cfg"), m_window(nullptr),
	m_SceneMgr(nullptr), m_Camera(nullptr) {
}

GfxMgr::~GfxMgr(void) {
}

void GfxMgr::Init(void) {
	m_root = new Ogre::Root(m_plugins);

	setupResources();

	assert(m_root->restoreConfig() || m_root->showConfigDialog());

	m_window = m_root->initialise(true, m_windowName);

	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	m_SceneMgr = m_root->createSceneManager(Ogre::ST_GENERIC);
}

void GfxMgr::LoadLevel(void) {
	//Camera initialization
	m_Camera = m_SceneMgr->createCamera("camera");
	m_Camera->setPosition(0, 200, 500);
	Ogre::SceneNode* camNode = m_SceneMgr->getRootSceneNode()->createChildSceneNode("camNode");
	camNode->attachObject(m_Camera);
	m_Camera->setNearClipDistance(5);

	Ogre::Viewport *vp = m_window->addViewport(m_Camera);
	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
	m_Camera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

	//Light initialization
	Ogre::Light* light = m_SceneMgr->createLight("MainLight");
	m_SceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	m_SceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
	light->setPosition(Ogre::Vector3(0, 20000, 0));
	light->setDirection(0, 0, 0);
}

void GfxMgr::Tick(float dt) {
	Ogre::WindowEventUtilities::messagePump();
	if (m_window->isClosed() || !m_root->renderOneFrame()) //Render frame to ogre. Shutdown if it fails
		engine->keepRunning = false;
}

void GfxMgr::Stop(void) {
	delete m_root;
	m_root = nullptr;
}

Ogre::RenderWindow* GfxMgr::getRenderWindow(void) {
	return m_window;
}

Ogre::SceneManager* GfxMgr::getSceneManger(void) {
	return m_SceneMgr;
}

Ogre::Camera* GfxMgr::getCamera(void) {
	return m_Camera;
}

void GfxMgr::setupResources(void) {
	Ogre::String name, locType;
	Ogre::ConfigFile cf;
	cf.load(m_resources); // Load resource paths from config file

	// Go through all sections & settings in the file
	Ogre::ConfigFile::SectionIterator sec_iter = cf.getSectionIterator();
	while (sec_iter.hasMoreElements()) {
		Ogre::String sec_name = sec_iter.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = sec_iter.getNext();

		for (auto it = settings->begin(); it != settings->end(); ++it)
		  {
			locType = it->first;
			name = it->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
		  }
	}
}


