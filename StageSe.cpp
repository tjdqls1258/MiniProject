#include "PlayState.h"
#include "GameStateMachine.h"
#include "StageSe.h"
#include "MenuButton.h"
#include "Game.h"
#include <iostream>
#include"TextureManger.h"
#include "Infinte.h"
StageSe* StageSe::s_pInstance = nullptr;
const std::string StageSe::s_menuID = "STAGE";

void StageSe::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void StageSe::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool StageSe::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Stage1.png",
		"Stage1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Stage2.png",
		"Stage2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/StageSen.png",
		"backGround", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(
		new LoaderParams(400, 300, 400, 100, "Stage1"),
		s_gostage1);

	GameObject* Back = new SDLGameObject(new LoaderParams(0, 0, 1280, 640, "backGround"));
	
	GameObject* button2 = new MenuButton(
		new LoaderParams(400, 500, 400, 100, "Stage2"),
		s_gostage2);
	m_gameObjects.push_back(Back);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering StageSe\n";

	return true;
}

bool StageSe::onExit()
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
	std::cout << "exiting StageSe\n";
	return true;
}

void StageSe::s_gostage2()
{
	TheGame::Instance()->getStateMachine()->changeState(Infinte::Instance());
}

void StageSe::s_gostage1()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}