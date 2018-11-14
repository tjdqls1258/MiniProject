#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : 
	SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_position.setX(m_position.getX() - 1);
	m_currentFrame = int(((SDL_GetTicks() / 1) % 1));
	SDLGameObject::update();
}
void Enemy::clean()
{
}
