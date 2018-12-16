#pragma once
#include"GameState.h"
class StageSe : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static StageSe* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new StageSe();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;
	static StageSe* s_pInstance;
	static void s_gostage2();
	static void s_gostage1();
	StageSe() {}
};