/*
 * GameMgr.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <GameMgr.h>
#include <Engine.h>
#include <GfxMgr.h>
#include <InputMgr.h>
#include <EntityMgr.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreRenderWindow.h>

GameMgr::GameMgr(Engine *engine) :
	Mgr(engine), m_graphics_scene_manager(nullptr), m_entity_mgr(nullptr), m_velocity_update_cooldown(0), mSurfaceHeight(-3.5) {
}

GameMgr::~GameMgr(void) {

}

void GameMgr::Init(void) {
	m_entity_mgr = engine->entityMgr;
}

void GameMgr::LoadLevel(void) {
	m_graphics_scene_manager = engine->gfxMgr->getSceneManger();
	SetupSky();
	SetupOcean();
	SetupShips();
}

void GameMgr::Tick(float dt) {

}

void GameMgr::Stop(void) {

}

void GameMgr::SetupSky(void) {
	// SkyDome as space
	m_graphics_scene_manager->setSkyDome(true, "Examples/CloudySky");
}

void GameMgr::SetupOcean(void) {
	//Create plane and texture as ocean
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ocean", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* oceanEntity = m_graphics_scene_manager->createEntity("ocean");
	Ogre::SceneNode* oceanNode = m_graphics_scene_manager->getRootSceneNode()->createChildSceneNode();
	oceanEntity->setMaterialName("OceanHLSL_GLSL");
	oceanEntity->setCastShadows(true);
	oceanNode->translate(Ogre::Vector3(0, mSurfaceHeight, 0));
	oceanNode->attachObject(oceanEntity);

	//Create Island
	Ogre::Entity* island1 = m_graphics_scene_manager->createEntity("island1.mesh");
	Ogre::SceneNode *island1_node = m_graphics_scene_manager->getRootSceneNode()->createChildSceneNode("island1_mat", Ogre::Vector3(0, -30, -2500));
	island1_node->setScale(10, 10, 10);
	island1_node->attachObject(island1);

	Ogre::Entity* island2 = m_graphics_scene_manager->createEntity("island2.mesh");
	Ogre::SceneNode *island2_node = m_graphics_scene_manager->getRootSceneNode()->createChildSceneNode("island2_mat", Ogre::Vector3(2000, -45, -3000));
	island2_node->setScale(10, 10, 10);
	island2_node->attachObject(island2);
}

void GameMgr::SetupShips(void) {
	//Setup entities
		float spacing = 250;

		//create 5 PolyPlane
		for (unsigned int i = 0; i < 5; ++i)
			m_entity_mgr->CreateEntityOfType(Entity381::PolyPlane, Ogre::Vector3(i * spacing, mSurfaceHeight + 300, -600));

		//create CG47
		m_entity_mgr->CreateEntityOfType(Entity381::CG47, Ogre::Vector3(0 * spacing, mSurfaceHeight + 1, -600));

		//create CVN75
		m_entity_mgr->CreateEntityOfType(Entity381::CVN75, Ogre::Vector3(1 * spacing, mSurfaceHeight + 1, -600));

		//create TUG
		m_entity_mgr->CreateEntityOfType(Entity381::TUG, Ogre::Vector3(2 * spacing, mSurfaceHeight + 1, -600));

		//create DDG51
		m_entity_mgr->CreateEntityOfType(Entity381::DDG51, Ogre::Vector3(3 * spacing, mSurfaceHeight + 1, -600));

		//create CIGARETTE
		m_entity_mgr->CreateEntityOfType(Entity381::CIGARETTE, Ogre::Vector3(4 * spacing, mSurfaceHeight + 1, -600));
}

