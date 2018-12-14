#include "PlayState.h"
#include "TextureManger.h"
#include "Game.h"
#include "BackGround.h"
PlayState* PlayState::s_pInstance = nullptr;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
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
	Instance_walls(1000, 276, 64, 164, "wall1");
	Instance_walls(2000, 276, 64, 164, "wall1");
	Instance_walls(3000, 276, 64, 164, "wall1");
	Instance_walls(4000, 276, 64, 164, "wall1");
	
	Instance_walls(1500, 276, 64, 86, "wall2");
	Instance_walls(2500, 276, 64, 86, "wall2");
	Instance_walls(3500, 276, 64, 86, "wall2");

	Instance_fire(1250, 238);
	Instance_fire(2250, 238);
	Instance_fire(3250, 238);

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
	GameObject* fire = new Fire(new LoaderParams(x, y+64-128, 64, 64, "fire"));
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
