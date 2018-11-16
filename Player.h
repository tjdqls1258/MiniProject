#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
	bool jump = true;
	int hight = 0;
	void handleInput();
	void player_jump(int hight);
	void coll_map();
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};
