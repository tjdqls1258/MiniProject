#include "PlayState.h"
#include "TextureManger.h"
#include "Game.h"
#include "BackGround.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Colletent.h"
#include "Winner.h"

PlayState* PlayState::s_pInstance = nullptr;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(
			PauseState::Instance());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		if (i != 0)
		{
			if (Colletent::Instance()->getColletent(dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
			{
				GameOverState::Instance()->set_infinte(s_playID);
				TheGame::Instance()->getStateMachine()->pushState(
					GameOverState::Instance());
			}
			else if (checkOutSide(dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
			{
				m_gameObjects.erase(m_gameObjects.begin() + i);
				i++;
			}
			if (m_gameObjects.size() == 1)
			{
				TheGame::Instance()->getStateMachine()->pushState(
					Winner::Instance());
			}
		}
	}
	for (int j = 0; j < m_BackGround.size(); j++) {
		m_BackGround[j]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_BackGround.size(); i++) {
		m_BackGround[i]->draw();
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{

	if (!TheTextureManager::Instance()->load(
		"assets/Player.png", "player",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"assets/BackGround.png", "back",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"assets/black.png", "wall1",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"assets/black2.png", "wall2",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"assets/fire.png", "fire",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject* player = new Player(new LoaderParams(100, 100, 128, 128, "player"));
	m_gameObjects.push_back(player);
	Instance_walls(1000, 294, 64, 164, "wall1");
	Instance_walls(2000, 294, 64, 164, "wall1");
	Instance_walls(3000, 294, 64, 164, "wall1");
	Instance_walls(4000, 294, 64, 164, "wall1");
	
	Instance_walls(1650, 374, 64, 86, "wall2");
	Instance_walls(2650, 374, 64, 86, "wall2");
	Instance_walls(3650, 374, 64, 86, "wall2");

	Instance_fire(1350, 300);
	Instance_fire(2350, 300);
	Instance_fire(3350, 300);

	instance_BackGround(0, 0, 1280, 640);
	instance_BackGround(1280, 0, 1280, 640);

	std::cout << "entering PlayState\n";
	return true;
}
void PlayState::Instance_walls(int x, int y, int w, int h, std::string EnemyName)
{
	GameObject* walls = new Enemy(new LoaderParams(x, y, w, h, EnemyName));
	m_gameObjects.push_back(walls);
}
void PlayState::instance_BackGround(int x, int y, int w, int h)
{
	GameObject* background = new BackGround(
		new LoaderParams(x, y, w, h, "back"));

	m_BackGround.push_back(background);
}
void PlayState::Instance_fire(int x, int y)
{
	GameObject* fire = new Fire(new LoaderParams(x, y, 64, 64, "fire"));
	m_gameObjects.push_back(fire);
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}
bool PlayState::checkOutSide(SDLGameObject* p1)
{
	int x = p1->getPosition().getX();
	int y = p1->getPosition().getY();
	int out = p1->getWidth() *(-1);
	if (x < out || y > 640)
	{
		return true;
	}
	return false;
}