#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	coll_map();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 3));
	player_jump(hight);
	SDLGameObject::update();
}
void Player::clean()
{
}
void Player::coll_map()
{
	if (m_position.getX() <= 16)
	{
		m_position.setX(16.0f);
	}
	else if (m_position.getX() >= 1124)
	{
		m_position.setX(1124.0f);
	}
}
void Player::handleInput()
{
	if (m_position.getY() >= 320 && jump&& (m_position.getY() <= 384))
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		{
			jump = false;
			hight = 80;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
		{
			jump = false;
			hight = 120;
		}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z) && (m_position.getY() >= 320))
	{
		m_currentRow = 2.5;
		m_position.setY(384);
		if (!jump)
		{
			m_currentRow = 1;
			m_position.setY(320);
		}
	}
	else if(jump && (m_position.getY() >= 320))
	{
		m_currentRow = 1;
		m_position.setY(320);
	}
	//ÁÂ¿ì ¿òÁ÷ÀÓ
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
}

void Player::player_jump(int hight)
{
	if (!jump)
	{
		if (m_position.getY() >= hight)
		{
			m_velocity.setY(-8);
		}
		else
		{
			jump = true;
		}
	}
	else if (jump && !(m_position.getY() >= 320))
	{
		m_velocity.setY(5);
	}
}