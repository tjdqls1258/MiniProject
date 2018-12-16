#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include <sstream>
class Infinte : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static Infinte* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Infinte();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_playID; }
	float retrunscore();
private:
	SDL_Color color = { 255,255,255 };
	std::string s;

	void Instance_walls(int x, int y, int w, int h, std::string EnemyName);
	void Instance_fire(int x, int y);
	void instance_BackGround(int x, int y, int w, int h);
	static const std::string s_playID;
	static Infinte* s_pInstance;
	std::vector<GameObject*> m_BackGround;
	std::vector<GameObject*> m_gameObjects;
	Infinte() {}
	bool checkOutSide(SDLGameObject* p1);
	double score = 0.0;
	double exteurn = 20.0;
	void Instance_item(int x, int y);
};