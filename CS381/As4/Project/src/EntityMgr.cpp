/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <EntityMgr.h>

EntityMgr::EntityMgr(Engine *engine) :
	Mgr(engine), m_selected(-1), m_scene_manager(nullptr) {
}

EntityMgr::~EntityMgr(void) {

}

void EntityMgr::Init(void) {
	m_selected = -1;
	m_entities.clear();
}

void EntityMgr::LoadLevel(void) {
	m_scene_manager = engine->gfxMgr->getSceneManger();
}

void EntityMgr::Stop(void) {
	for (Entity381 *e : m_entities)
		delete e;
}

Entity381* EntityMgr::CreateEntityOfType(const Entity381::EntityType type, const Ogre::Vector3 &position) {
	if (type == Entity381::EntityType::PolyPlane){
		Entity381 *newEnt = new PolyPlane(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
	}
	else if (type == Entity381::EntityType::CG47){
		Entity381 *newEnt = new CG47(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
	}
	else if (type == Entity381::EntityType::CVN75){
		Entity381 *newEnt = new CVN75(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(0.5, 0.5, 0.5), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
		}
	else if (type == Entity381::EntityType::TUG){
		Entity381 *newEnt = new TUG(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(3, 3, 3), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
		}
	else if (type == Entity381::EntityType::CIGARETTE){
		Entity381 *newEnt = new CIGARETTE(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(2, 2, 2), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
		}
	else if (type == Entity381::EntityType::DDG51){
		Entity381 *newEnt = new DDG51(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
		m_entities.push_back(newEnt);
		}
	else
		return nullptr;

	return m_entities.back();
}

bool EntityMgr::selectNextEntity(void) {
	if (m_selected >= 0){
		m_entities[m_selected]->showBoundingBox(false);
	}

	++m_selected %= m_entities.size();
	m_entities[m_selected]->showBoundingBox(true);
	return true;
}

bool EntityMgr::changeSelectedDesiredSpeed(float amount) {
	if (m_selected < 0)
		return false;

	m_entities[m_selected]->changeDesiredSpeed(amount);
	return true;
}

bool EntityMgr::changeSelectedDesiredHeading(float amount) {
	if (m_selected < 0)
		return false;

	m_entities[m_selected]->changeDesiredHeading(amount);
	return true;
}

void EntityMgr::Tick(float dt) {
	for (Entity381 *e : m_entities){
		e->Tick(dt);
	}
}


