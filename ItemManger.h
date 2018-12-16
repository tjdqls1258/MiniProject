#pragma once
#ifndef ITEMMANGER_H
#define ITEMMANGER_H
#include <vector>
#include "Item.h"
#include"GameObject.h"

class ItemManger
{
private:
	static ItemManger* s_pInstance;
public:
	static ItemManger* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new ItemManger();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void instance_bullte(int x, int y);
	void draw();
	void update();
	void clean();
	void delete_Bullte(int i);
	std::vector<GameObject*> m_item;
};

#endif // ITEMMANGER_H