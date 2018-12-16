#include "ItemManger.h"
#include"Colletent.h"
#include "LoaderParams.h"
ItemManger* ItemManger::s_pInstance = nullptr;

void ItemManger::instance_bullte(int x, int y)
{
	m_item.push_back(new Item(new LoaderParams(x,y,32,32,"item")));
}

void ItemManger::draw()
{
	for (int i = 0; i < m_item.size(); i++)
	{
		m_item[i]->draw();
	}
}

void ItemManger::update()
{
	for (int i = 0; i < m_item.size(); i++)
	{
		m_item[i]->update();
		if (m_item[i]->returncoll())
		{
			delete_Bullte(i);
			//Colletent::Instance()->Colletent_it_P1();
		}
	}
	
}

void ItemManger::clean()
{
	for (int i = 0; i < m_item.size(); i++)
	{
		m_item[i]->clean();
	}
	m_item.clear();
}
void ItemManger::delete_Bullte(int i)
{
	m_item.erase(m_item.begin() + i);
}