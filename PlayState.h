#include "GameState.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_playID; }
private:
	void Instance_walls(int x, int y, int w, int h, std::string EnemyName);
	void Instance_fire(int x, int y);
	void instance_BackGround(int x, int y, int w, int h);
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_BackGround;
	std::vector<GameObject*> m_gameObjects;
	PlayState() {}
};