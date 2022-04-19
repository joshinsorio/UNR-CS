/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include "EntityMgr.h"

EntityMgr::EntityMgr(Ogre::SceneManager *scene_manager) :
	m_selected(-1), m_scene_manager(scene_manager) {
}

EntityMgr::~EntityMgr(void) {
	for (Entity381 *e : m_entities)
		delete e;
}

Entity381* EntityMgr::CreateEntityOfType(const Entity381::EntityType type, const Ogre::Vector3 &position) {
//	switch(type){
//		case Entity381::EntityType::PolyPlane:
//			Entity381 *newEnt = new PolyPlane(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
//			m_entities.push_back(newEnt);
//			break;
//
//		case Entity381::EntityType::CG47:
//			Entity381 *newEnt = new PolyPlane(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
//			m_entities.push_back(newEnt);
//			break;
//
//		case Entity381::EntityType::CVN75:
//			Entity381 *newEnt = new PolyPlane(m_entities.size(), std::to_string(m_entities.size()), m_scene_manager, position, Ogre::Vector3(1, 1, 1), Ogre::Vector3::ZERO);
//			m_entities.push_back(newEnt);
//			break;
//	}
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
	else
		return nullptr; //unknown type

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

bool EntityMgr::setEntityVelocity(const Ogre::Vector3& velocity, bool accumulate) {
	if (m_selected < 0)
		return false;

	m_entities[m_selected]->setVelocity(velocity, accumulate);
	return true;
}

void EntityMgr::Tick(float dt) {
	for (Entity381 *e : m_entities){
//		e->setEntity(e, dt);
		e->Tick(dt);
	}
}


