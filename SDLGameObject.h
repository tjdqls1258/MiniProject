#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	Vector2D & getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	std::string get_textID() { return m_textureID; }
	bool returncoll() { return coll; }
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	double m_currentRow;
	double m_currentFrame;
	std::string m_textureID;
	bool coll;
};