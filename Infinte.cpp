#include "Infinte.h"
#include "TextureManger.h"
#include "Game.h"
#include "BackGround.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Colletent.h"
#include "UITextureManger.h"
#include "ItemManger.h"
#include<ctime>
Infinte* Infinte::s_pInstance = nullptr;
const std::string Infinte::s_playID = "INFINTE";

void Infinte::update()
{
	srand((unsigned int)time(0));
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(
			PauseState::Instance());
	}
	score += 0.1;
	std::ostringstream ostr;
	ostr << "Score : " << score;
	s = ostr.str();
	ItemManger::Instance()->update();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		if (i != 0)
		{
			if (Colletent::Instance()->getColletent(dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
			{
				if (Game::hi_score < score)
				{
					Game::hi_score = score;
				}
				GameOverState::Instance()->set_infinte(s_playID);
				TheGame::Instance()->getStateMachine()->pushState(
					GameOverState::Instance());
			}
			else if (checkOutSide(dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
			{
				m_gameObjects[i]->clean();
			}
		}
	}
	for (int i = 0; i < ItemManger::Instance()->m_item.size(); i++)
	{

		if (Colletent::Instance()->getColletent(dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(ItemManger::Instance()->m_item[i])))
		{
			score += 1.0;
			ItemManger::Instance()->m_item[i]->clean();
			Instance_item(1280, rand() % 80 + 294);
		}
		else if (checkOutSide(dynamic_cast<SDLGameObject*>(ItemManger::Instance()->m_item[i])))
		{
			ItemManger::Instance()->m_item[i]->clean();
			Instance_item(1380, rand() % 80 + 294);
		}
	}
	if (score == exteurn)
	{
		exteurn * 2;
		Instance_walls(4280, 294, 64, 164, "wall1");
		Instance_walls(5280, 374, 64, 164, "wall2");
		Instance_fire(8280, 300);
	}
	for (int j = 0; j < m_BackGround.size(); j++) {
		m_BackGround[j]->update();
	}
}

void Infinte::render()
{
	for (int i = 0; i < m_BackGround.size(); i++) {
		m_BackGround[i]->draw();
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	TheUITextureManager::Instance()->draw(540, 500, 200, 100, TheGame::Instance()->getRenderer(), color, s);
	ItemManger::Instance()->draw();
}
bool Infinte::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/item.png", "item",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
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
	if (!TheUITextureManager::Instance()->load(24, TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	score = 0.0;
	GameObject* player = new Player(new LoaderParams(100, 100, 128, 128, "player"));
	m_gameObjects.push_back(player);
	Instance_walls(1280, 294, 64, 164, "wall1");
	
	Instance_walls(2280, 374, 64, 86, "wall2");

	Instance_fire(5000, 300);

	instance_BackGround(0, 0, 1280, 640);
	instance_BackGround(1280, 0, 1280, 640);

	Instance_item(1400, 374);
	std::cout << "entering Infinte\n";
	return true;
}
void Infinte::Instance_item(int x, int y)
{
	ItemManger::Instance()->instance_bullte(x, y);
}
void Infinte::Instance_walls(int x, int y, int w, int h, std::string EnemyName)
{
	GameObject* walls = new Enemy(new LoaderParams(x, y, w, h, EnemyName));
	m_gameObjects.push_back(walls);
}
void Infinte::instance_BackGround(int x, int y, int w, int h)
{
	GameObject* background = new BackGround(
		new LoaderParams(x, y, w, h, "back"));

	m_BackGround.push_back(background);
}
void Infinte::Instance_fire(int x, int y)
{
	GameObject* fire = new Fire(new LoaderParams(x, y, 64, 64, "fire"));
	m_gameObjects.push_back(fire);
}

bool Infinte::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	ItemManger::Instance()->clean();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting Infinte\n";
	return true;
}
bool Infinte::checkOutSide(SDLGameObject* p1)
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
float Infinte::retrunscore()
{
	return score;
}