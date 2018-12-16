#pragma once
#include"GameState.h"
class Winner : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static Winner* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Winner();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;
	static Winner* s_pInstance;
	static void s_gostage2();
	static void s_gostage1();
	Winner() {}
};