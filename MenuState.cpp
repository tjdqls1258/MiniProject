#include "StageSe.h"
#include "GameStateMachine.h"
#include "MenuState .h"
#include "MenuButton.h"
#include "Game.h"
#include <iostream>
#include"TextureManger.h"

MenuState* MenuState::s_pInstance = nullptr;
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Start.png",
		"backGround", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(
		new LoaderParams(400, 300, 400, 100, "playbutton"),
		s_menuToPlay);
	GameObject* Back = new SDLGameObject(new LoaderParams(0, 0, 1280, 640, "backGround"));
	GameObject* button2 = new MenuButton(
		new LoaderParams(400, 500, 400, 100, "exitbutton"),
		s_exitFromMenu);
	m_gameObjects.push_back(Back);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";

	return true;
}

bool MenuState::onExit()
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
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(StageSe::Instance());
}