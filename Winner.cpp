#include "PlayState.h"
#include "GameStateMachine.h"
#include "Winner.h"
#include "MenuButton.h"
#include "Game.h"
#include <iostream>
#include"TextureManger.h"
#include "MenuState .h"
#include "Infinte.h"

Winner* Winner::s_pInstance = nullptr;
const std::string Winner::s_menuID = "WIN";

void Winner::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Winner::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool Winner::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"main", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Stage2.png",
		"Stage2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/winner.png",
		"backGround", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(
		new LoaderParams(500, 300, 200, 100, "main"),
		s_gostage1);

	GameObject* Back = new SDLGameObject(new LoaderParams(0, 0, 1280, 640, "backGround"));
	
	GameObject* button2 = new MenuButton(
		new LoaderParams(400, 500, 400, 100, "Stage2"),
		s_gostage2);
	m_gameObjects.push_back(Back);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering Winner\n";

	return true;
}

bool Winner::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting Winner\n";
	return true;
}

void Winner::s_gostage2()
{
	TheGame::Instance()->getStateMachine()->changeState(Infinte::Instance());
}

void Winner::s_gostage1()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}