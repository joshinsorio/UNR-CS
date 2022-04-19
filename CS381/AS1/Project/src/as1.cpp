//Name: Joshua Insorio
//Email: joshuainsorio@outlook.com

#include <as1.h>
#include <stdlib.h>

bool trackingCam = false;
Ogre::Quaternion oldOrientation;

as1::as1(void): mSurfaceHeight(-3.5), mArrowUPressed(false), mArrowDPressed(false), mArrowRPressed(false), mArrowLPressed(false), mPgUPressed(false), mPgDPressed(false), mCameraVelocity(0.f)
{
}
 
as1::~as1(void)
{
}
 
void as1::createScene(void)
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

	//PolyPlane
	Ogre::Entity* planeEntity = mSceneMgr->createEntity("PolyPlane.mesh");
	Ogre::SceneNode* planeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("planeNode");
	planeNode->setPosition(0, 0, 0);
	planeNode->setScale(5, 5, 5);
	planeNode->attachObject(planeEntity);
	mObjVelocities = Ogre::Vector3(0.0);

	//Create plane and texture as grass
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	Ogre::SceneNode* groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	groundEntity->setMaterialName("381/Grass");
	groundEntity->setCastShadows(true);
	groundNode->translate(Ogre::Vector3(0, mSurfaceHeight, 0));
	groundNode->attachObject(groundEntity);

	// SkyBox as space
	mSceneMgr->setSkyDome(true, "Examples/CloudySky");

	//Extra Credit - Decorations
	//Runway
	Ogre::MeshManager::getSingleton().createPlane("ground2", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 5000, 200, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* runwayEntity = mSceneMgr->createEntity("ground2");
	Ogre::SceneNode* runwayNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	runwayEntity->setMaterialName("381/Runway");
	runwayEntity->setCastShadows(true);
	runwayNode->setPosition(0, -2, 0);
	runwayNode->attachObject(runwayEntity);

	//Trees
	Ogre::Entity* treeEntity1 = mSceneMgr->createEntity("TreePineA.mesh");
	Ogre::SceneNode* treeNode1 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	treeNode1->setPosition(-300, 5, 300);
	treeNode1->setScale(50, 50, 50);
	treeNode1->attachObject(treeEntity1);

	Ogre::Entity* treeEntity2 = mSceneMgr->createEntity("TreeRoundA.mesh");
	Ogre::SceneNode* treeNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	treeNode2->setPosition(300, 5, -300);
	treeNode2->setScale(50, 50, 50);
	treeNode2->attachObject(treeEntity2);

	//Hangar
	Ogre::Entity* hangarEntity = mSceneMgr->createEntity("hangar.mesh");
	Ogre::SceneNode* hangarNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	hangarNode->setPosition(3000, 0, 0);
	hangarNode->yaw(Ogre::Degree(90));
	hangarNode->setScale(300, 300, 300);
	hangarNode->attachObject(hangarEntity);



}

bool as1::frameRenderingQueued(const Ogre::FrameEvent &e) {
	if (!processUnbufferedInput(e))
		return false;

	return BaseApplication::frameRenderingQueued(e);
}


bool as1::processUnbufferedInput(const Ogre::FrameEvent& e)
{
	//Move Plane
	mSceneMgr->getSceneNode("planeNode")->translate(mObjVelocities * e.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

	//Move Camera
	mSceneMgr->getSceneNode("camNode")->translate(mCameraVelocity * e.timeSinceLastFrame, Ogre::Node::TS_LOCAL);


	return true;
}

bool as1::keyPressed(const OIS::KeyEvent &arg) {
	static const float VELOCITY_CHANGE = 150;

	switch (arg.key) {

	case OIS::KC_Q:
	    mShutDown = true;
	    break;

	case OIS::KC_DOWN:
		mObjVelocities.z += VELOCITY_CHANGE;
		break;

	case OIS::KC_UP:
		mObjVelocities.z -= VELOCITY_CHANGE;
		break;

	case OIS::KC_RIGHT:
		mObjVelocities.x += VELOCITY_CHANGE;
		break;

	case OIS::KC_LEFT:
		mObjVelocities.x -= VELOCITY_CHANGE;
		break;

	case OIS::KC_PGUP:
		mObjVelocities.y += VELOCITY_CHANGE;
		break;

	case OIS::KC_PGDOWN:
		mObjVelocities.y -= VELOCITY_CHANGE;
		break;

	case OIS::KC_SPACE:
		mObjVelocities = Ogre::Vector3(0.0);
		break;

	case OIS::KC_Z:
		if(trackingCam == false){
			mSceneMgr->getSceneNode("camNode")->setAutoTracking(true, mSceneMgr->getSceneNode("planeNode"));
			oldOrientation = mSceneMgr->getSceneNode("camNode")->getOrientation();
			trackingCam = true;
		}
		else{
			mSceneMgr->getSceneNode("camNode")->setAutoTracking(false);
			mSceneMgr->getSceneNode("camNode")->setOrientation(oldOrientation);
			trackingCam = false;
		}
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

bool as1::keyReleased(const OIS::KeyEvent &arg) {
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
	as1 app;
 
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
