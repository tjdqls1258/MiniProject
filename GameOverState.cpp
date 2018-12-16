#include "GameOverState.h"
#include"Game.h"
#include"MenuState .h"
#include"PlayState.h"
#include "TextureManger.h"
#include"AnimatedGraphic.h"
#include"MenuButton.h"
#include <sstream>
#include "Infinte.h"
#include "UITextureManger.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = nullptr;


void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		MenuState::Instance());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		PlayState::Instance());
}
void GameOverState::s_restartPlay_infinte()
{
	TheGame::Instance()->getStateMachine()->changeState(
		Infinte::Instance());
}
bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/GameOverBack.png",
		"back", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(520, 100, 190, 30, "gameovertext"), 2);
	GameObject* backGround = new SDLGameObject(new LoaderParams(0, 0, 1280, 640, "back"));
	GameObject* button1 = new MenuButton(
		new LoaderParams(520, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	m_gameObjects.push_back(backGround);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);

	if (tf_state == "INFINTE")
	{
		if (!TheUITextureManager::Instance()->load(24, TheGame::Instance()->getRenderer()))
		{
			return false;
		}
		GameObject* button2 = new MenuButton(
			new LoaderParams(520, 300, 200, 80, "restartbutton"),
			s_restartPlay_infinte);
		m_gameObjects.push_back(button2);
	}
	else if(tf_state == "PLAY")
	{
		GameObject* button2 = new MenuButton(
			new LoaderParams(520, 300, 200, 80, "restartbutton"),
			s_restartPlay);
		m_gameObjects.push_back(button2);
	}
	
	std::cout << "entering PauseState\n";
	
	//std::cout <<"Score : " << PlayState::Instance()->retrunscore()<<"\n";


	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	if (tf_state == "INFINTE")
	{
		std::ostringstream ostr;
		ostr << "Score : " << Infinte::Instance()->retrunscore();
		std::string s = ostr.str();
		TheUITextureManager::Instance()->draw(540, 520, 200, 100, TheGame::Instance()->getRenderer(), color, s);
		std::ostringstream ostr1;
		ostr1 << "High Score : " << Game::hi_score;
		std::string s1 = ostr1.str();
		TheUITextureManager::Instance()->draw(440, 420, 400, 100, TheGame::Instance()->getRenderer(), color, s1);
	}
}