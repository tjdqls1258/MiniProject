#pragma once
#include "GameState.h"
#include <iostream>

class GameObject;

class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static GameOverState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameOverState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_gameOverID; }
	void set_infinte(std::string tf_state)
	{
		this->tf_state = tf_state;
	}
private:
	SDL_Color color = { 255,255,255 };
	std::string tf_state = "";
	static GameOverState* s_pInstance;
	static void s_gameOverToMain();
	static void s_restartPlay();
	static void s_restartPlay_infinte();
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
};