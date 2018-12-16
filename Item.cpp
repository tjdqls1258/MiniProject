#include "Item.h"
#include "InputHandler.h"
#include "Game.h"
#include "Enemy.h"

Item::Item(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Item::draw()
{
	if (!coll)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
	}
}
void Item::update()
{
	if (!coll)
	{
		m_velocity.setX(-5);
		m_currentFrame = 0;
		SDLGameObject::update();
	}
}
void Item::clean()
{
	coll = true;
	
}

void Item::handleInput()
{

}

bool Item::returncoll()
{
	return coll;
}