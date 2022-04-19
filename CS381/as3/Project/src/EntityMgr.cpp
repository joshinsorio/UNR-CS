/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: Joshua Insorio
 *      Email: joshuainsorio@outlook.com
 */

#include <EntityMgr.h>

EntityMgr::EntityMgr(Ogre::SceneManager *scene_manager) :
	m_selected(-1), m_scene_manager(scene_manager) {
}

EntityMgr::~EntityMgr(void) {
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

//bool EntityMgr::setEntityVelocity(const Ogre::Vector3& velocity, bool accumulate) {
//	if (m_selected < 0)
//		return false;
//
//	m_entities[m_selected]->setVelocity(velocity, accumulate);
//	return true;
//}

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

bool EntityMgr::resetSelectedSpeedAndHeading(void) {
	if (m_selected < 0)
		return false;

	std::pair<float, float> heading_speed = m_entities[m_selected]->getDesiredHeadingAndSpeed();
	m_entities[m_selected]->changeDesiredHeading(-heading_speed.first);
	m_entities[m_selected]->changeDesiredSpeed(-heading_speed.second);
	return true;
}

void EntityMgr::Tick(float dt) {
	for (Entity381 *e : m_entities){
//		e->setEntity(e, dt);
		e->Tick(dt);
	}
}


