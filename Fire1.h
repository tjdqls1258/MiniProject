#pragma once
#include "SDLGameObject.h"

class Fire : public SDLGameObject
{
private:
	void handleInput() {}
public:
	Fire(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};