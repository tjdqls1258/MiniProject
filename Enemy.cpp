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
	m_position.setX(m_position.getX() - 5);
	m_currentFrame = 0;
	SDLGameObject::update();
}
void Enemy::clean()
{
	//move side
	m_position.setX(rand() % 500 + 1283);
}
