#include "Fire1.h"
#include "InputHandler.h"

Fire::Fire(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Fire::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Fire::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_position.setX(m_position.getX() - 5);
	m_currentFrame = int(((SDL_GetTicks() / 4) % 4));
	if (m_position.getX() <= -32)
	{
		m_velocity.setX(10000);
	}
	SDLGameObject::update();
}
void Fire::clean()
{
}
