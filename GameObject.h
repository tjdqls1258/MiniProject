#pragma once
#include<iostream>
#include<string>
#include "SDL.h"
#include <map>
#include <SDL_image.h>

class LoaderParams;

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};