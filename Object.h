#pragma once
#include "SDLGameObject.h"

class Object : public SDLGameObject
{
private:
	void handleInput();
public:
	Object(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};
