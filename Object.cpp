#include "Object.h"
#include "InputHandler.h"

Object::Object(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Object::draw()
{
	SDLGameObject::draw();
}
void Object::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 10) % 3200));
	SDLGameObject::update();
}
void Object::clean()
{
}
void Object::handleInput()
{

}