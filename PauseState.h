#pragma once
#include "GameState.h"
class GameObject;

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static PauseState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PauseState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	static PauseState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};