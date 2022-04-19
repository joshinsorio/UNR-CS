#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_
 
#include "BaseApplication.h"
#include "EntityMgr.h"
#include <unordered_map>
 
class as2 : public BaseApplication
{
public:
  as2();
  virtual ~as2();
 
protected:
	virtual void createScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent &e);
	virtual bool keyPressed(const OIS::KeyEvent& ke);
	virtual bool keyReleased(const OIS::KeyEvent& ke);

private:
	bool processUnbufferedInput(const Ogre::FrameEvent &e);
	int mSurfaceHeight;
	bool mArrowUPressed;
	bool mArrowDPressed;
	bool mArrowRPressed;
	bool mArrowLPressed;
	bool mPgUPressed;
	bool mPgDPressed;
	Ogre::Vector3 mCameraVelocity;
	EntityMgr *m_entity_manager;

};

 
#endif // #ifndef __TutorialApplication_h_
