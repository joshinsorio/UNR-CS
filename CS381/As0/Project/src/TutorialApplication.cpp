//Name: Joshua Insorio
//Email: joshuainsorio@outlook.com

#include "TutorialApplication.h"
#include <stdlib.h>
 
TutorialApplication::TutorialApplication(void)
{
}
 
TutorialApplication::~TutorialApplication(void)
{
}
 
void TutorialApplication::createScene(void)
{
	//Camera initialization
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	mCamera->setPosition(0, 120, 500);
	mCamera->lookAt(0, 0, -300);

	//Light initialization
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(20.0, 80.0, 50.0);

	//cg47 entity initialization
	Ogre::Entity* cg47Entity = mSceneMgr->createEntity("cg47.mesh");
	Ogre::Entity* cg47Entity2 = mSceneMgr->createEntity("cg47.mesh");
	Ogre::Entity* cg47Entity3 = mSceneMgr->createEntity("cg47.mesh");
	Ogre::Entity* cg47Entity4 = mSceneMgr->createEntity("cg47.mesh");
	Ogre::Entity* cg47Entity5 = mSceneMgr->createEntity("cg47.mesh");
	//Ogre::Entity* cg47Entity6 = mSceneMgr->createEntity("cg47.mesh");


	//First cg47
	Ogre::SceneNode* cg47Node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cg47Node->attachObject(cg47Entity);
	cg47Node->showBoundingBox(true);

	//Second cg47
	Ogre::SceneNode* cg47Node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cg47Node2->setPosition(-200,0,0);
	cg47Node2->yaw(Ogre::Degree(90));
	cg47Node2->showBoundingBox(true);
	cg47Node2->attachObject(cg47Entity2);

	//Third cg47
	Ogre::SceneNode* cg47Node3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cg47Node3->setPosition(200,0,0);
	cg47Node3->yaw(Ogre::Degree(-90));
	cg47Node3->showBoundingBox(true);
	cg47Node3->attachObject(cg47Entity3);

	//fourth cg47
	Ogre::SceneNode* cg47Node4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cg47Node4->setPosition(-100, 100, 0);
	cg47Node4->yaw(Ogre::Degree(180));
	cg47Node4->scale(1, -1, 1);
	cg47Node4->showBoundingBox(true);
	cg47Node4->attachObject(cg47Entity4);

	//Fifth cg47
	Ogre::SceneNode* cg47Node5 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cg47Node5->setPosition(100, 100, 0);
	cg47Node5->yaw(Ogre::Degree(270));
	cg47Node5->scale(1, 2, 1);
	cg47Node5->showBoundingBox(true);
	cg47Node5->attachObject(cg47Entity5);

	//Create plane and texture as grass
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -100);
	Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setMaterialName("Examples/GrassFloor");
	groundEntity->setCastShadows(false);

	// SkyBox as space
	mSceneMgr->setSkyBox(true, "SpaceSkyBox");

	//Rotate ships

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
	TutorialApplication app;
 
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
