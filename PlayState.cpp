#include "PlayState.h"
#include "TextureManger.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = nullptr;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
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
		"assets/fire.png", "fire",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "player"));

	GameObject* walls = new Enemy(new LoaderParams(5000, 238, 64, 164, "wall1"));
	GameObject* walls = new Enemy(new LoaderParams(2000, 320, 64, 164, "wall1"));
	GameObject* walls = new Enemy(new LoaderParams(1564, 238, 64, 164, "wall1"));
	GameObject* walls = new Enemy(new LoaderParams(7200, 238, 64, 164, "wall1"));

	GameObject* fire = new Fire(new LoaderParams(1200, 238, 64, 64, "fire"));
	GameObject* fire = new Fire(new LoaderParams(3200, 238, 64, 64, "fire"));
	GameObject* fire = new Fire(new LoaderParams(6200, 238, 64, 64, "fire"));

	m_gameObjects.push_back(fire);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(walls);
	std::cout << "entering PlayState\n";
	return true;
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
void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}