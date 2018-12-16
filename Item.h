#pragma once
#include "SDLGameObject.h"

class Item : public SDLGameObject
{
private:
	void handleInput();
	bool coll = false;
public:
	Item(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	bool returncoll();

};