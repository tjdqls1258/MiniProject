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
	m_currentFrame = int(((SDL_GetTicks() / 100) % 3));
	player_jump(hight);
	//player_jump(l_jump, 140);
	SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
	if (m_position.getY() >= 276 && jump)
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		{
			jump = false;
			hight = 80;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
		{
			jump = false;
			hight = 120;
		}
		//수정안 z 슬라이딩 x 낮은점프 스페이스바 높은점프
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_currentRow = 2.5;
	}
	else
	{
		m_currentRow = 1;
	}
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
	else if (jump && !(m_position.getY() >= 276))
	{
		m_velocity.setY(5);

	}
}