//Name: Joshua Insorio
//Email: joshuainsorio@outlook.com

#include "as2.h"
#include <stdlib.h>

bool trackingCam = false;
Ogre::Quaternion oldOrientation;

as2::as2(void): mSurfaceHeight(-3.5), mArrowUPressed(false), mArrowDPressed(false), mArrowRPressed(false), mArrowLPressed(false), mPgUPressed(false), mPgDPressed(false), mCameraVelocity(0.f), m_entity_manager(nullptr)
{
}
 
as2::~as2(void)
{
}
 
void as2::createScene(void)
{
	//Camera initialization
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
	mCamera->setPosition(0, 200, 500);
	Ogre::SceneNode* camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("camNode");
	camNode->attachObject(mCamera);
	//mCamera->lookAt(0, 0, -50);

	//Light initialization
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(Ogre::Vector3(0, 20000, 0));
	light->setDirection(0, 0, 0);

	//Setup entity manager
	m_entity_manager = new EntityMgr(mSceneMgr);

	//Setup entities
	float spacing=200;

	//create 5 PolyPlane
	for (unsigned int i = 0; i < 5; ++i)
		m_entity_manager->CreateEntityOfType(Entity381::PolyPlane, Ogre::Vector3(i * spacing, mSurfaceHeight + 300, -600));

	//create 5 CG47
	for (unsigned int i = 0; i < 5; ++i)
		m_entity_manager->CreateEntityOfType(Entity381::CG47, Ogre::Vector3(i * spacing, mSurfaceHeight + 1, -600));

	//create 5 CVN75
	for (unsigned int i = 0; i < 5; ++i)
		m_entity_manager->CreateEntityOfType(Entity381::CVN75, Ogre::Vector3(i * spacing, mSurfaceHeight + 1, -1000));


//	//PolyPlane
//	Ogre::Entity* planeEntity = mSceneMgr->createEntity("PolyPlane.mesh");
//	Ogre::SceneNode* planeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("planeNode");
//	planeNode->setPosition(0, 0, 0);
//	planeNode->setScale(5, 5, 5);
//	planeNode->attachObject(planeEntity);
//	mObjVelocities = Ogre::Vector3(0.0);
//
	//Create plane and texture as ocean
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ocean", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* oceanEntity = mSceneMgr->createEntity("ocean");
	Ogre::SceneNode* oceanNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();

	//oceanEntity->setMaterialName("Ocean2_Cg");
	oceanEntity->setMaterialName("OceanHLSL_GLSL");
	oceanEntity->setCastShadows(true);
	oceanNode->translate(Ogre::Vector3(0, mSurfaceHeight, 0));
	oceanNode->attachObject(oceanEntity);

	// SkyBox as space
	mSceneMgr->setSkyDome(true, "Examples/CloudySky");

	//Create Island
	Ogre::Entity* island1 = mSceneMgr->createEntity("island1.mesh");
	Ogre::SceneNode *island1_node = mSceneMgr->getRootSceneNode()->createChildSceneNode("island1_mat", Ogre::Vector3(0, -30, -2500));
	island1_node->setScale(10, 10, 10);
	island1_node->attachObject(island1);

	Ogre::Entity* island2 = mSceneMgr->createEntity("island2.mesh");
	Ogre::SceneNode *island2_node = mSceneMgr->getRootSceneNode()->createChildSceneNode("island2_mat", Ogre::Vector3(2000, -45, -3000));
	island2_node->setScale(10, 10, 10);
	island2_node->attachObject(island2);


}

bool as2::frameRenderingQueued(const Ogre::FrameEvent &e) {
	if (!processUnbufferedInput(e))
		return false;

	return BaseApplication::frameRenderingQueued(e);
}


bool as2::processUnbufferedInput(const Ogre::FrameEvent& e)
{
	//Update Objects
	m_entity_manager->Tick(e.timeSinceLastEvent);

	//Move Camera
	mSceneMgr->getSceneNode("camNode")->translate(mCameraVelocity * e.timeSinceLastFrame, Ogre::Node::TS_LOCAL);


	return true;
}

bool as2::keyPressed(const OIS::KeyEvent &arg) {
	static const float VELOCITY_CHANGE = 150;

	switch (arg.key) {
		case OIS::KC_Q:
			mShutDown = true;
			break;

		case OIS::KC_DOWN:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(0, 0, VELOCITY_CHANGE));
			break;

		case OIS::KC_UP:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(0, 0, -VELOCITY_CHANGE));
			break;

		case OIS::KC_RIGHT:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(VELOCITY_CHANGE, 0, 0));
			break;

		case OIS::KC_LEFT:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(-VELOCITY_CHANGE, 0, 0));
			break;

		case OIS::KC_PGUP:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(0, VELOCITY_CHANGE, 0));
			break;

		case OIS::KC_PGDOWN:
			m_entity_manager->setEntityVelocity(Ogre::Vector3(0, -VELOCITY_CHANGE, 0));
			break;

		case OIS::KC_SPACE:
			m_entity_manager->setEntityVelocity(Ogre::Vector3::ZERO, false);
			break;

		case OIS::KC_TAB:
			m_entity_manager->selectNextEntity();
			break;

		case OIS::KC_A:
			if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
				mSceneMgr->getSceneNode("camNode")->yaw(Ogre::Degree(5));
			else
				mCameraVelocity.x -= 600;
			break;

		case OIS::KC_D:
			if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
				mSceneMgr->getSceneNode("camNode")->yaw(Ogre::Degree(-5));
			else
				mCameraVelocity.x += 600;
			break;

		case OIS::KC_W:
			if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
				mSceneMgr->getSceneNode("camNode")->pitch(Ogre::Degree(5));
			else
				mCameraVelocity.z -= 600;
			break;

		case OIS::KC_S:
			if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
				mSceneMgr->getSceneNode("camNode")->pitch(Ogre::Degree(-5));
			else
				mCameraVelocity.z += 600;
			break;

		case OIS::KC_E:
			mCameraVelocity.y += 600;
			break;

		case OIS::KC_F:
			mCameraVelocity.y -= 600;
			break;

		default:
			break;
		}

	return BaseApplication::keyPressed(arg);
}

bool as2::keyReleased(const OIS::KeyEvent &arg) {
	switch (arg.key) {
	case OIS::KC_DOWN:
			mArrowUPressed = false;
			break;

		case OIS::KC_UP:
			mArrowDPressed = false;
			break;

		case OIS::KC_RIGHT:
			mArrowRPressed = false;
			break;

		case OIS::KC_LEFT:
			mArrowLPressed = false;
			break;

		case OIS::KC_PGUP:
			mPgUPressed = false;
			break;

		case OIS::KC_PGDOWN:
			mPgDPressed = false;
			break;

	case OIS::KC_A:
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		{}
		else
			mCameraVelocity.x += 600;
		break;

	case OIS::KC_D:
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		{}
		else
			mCameraVelocity.x -= 600;
		break;

	case OIS::KC_W:
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		{}
		else
			mCameraVelocity.z += 600;
		break;

	case OIS::KC_S:
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		{}
		else
			mCameraVelocity.z -= 600;
		break;

	case OIS::KC_E:
		mCameraVelocity.y -= 600;
		break;

	case OIS::KC_F:
		mCameraVelocity.y += 600;
		break;

	default:
		break;
	}

	return BaseApplication::keyReleased(arg);
}
 
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif
 
#ifdef __cplusplus
extern "C" {
#endif
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
	// Create application object
	as2 app;
 
	try {
	    app.go();
	} catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	    MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
	    std::cerr << "An exception has occurred: " <<
		e.getFullDescription().c_str() << std::endl;
#endif
	}
 
	return 0;
    }
 
#ifdef __cplusplus
}
#endif
