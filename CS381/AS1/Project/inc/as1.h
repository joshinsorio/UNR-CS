#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_
 
#include "BaseApplication.h"
#include <unordered_map>
 
class as1 : public BaseApplication
{
public:
  as1();
  virtual ~as1();
 
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

	Ogre::Vector3 mObjVelocities;
	Ogre::Vector3 mCameraVelocity;

};

 
#endif // #ifndef __TutorialApplication_h_
