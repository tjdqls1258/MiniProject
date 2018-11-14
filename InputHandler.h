#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}							

	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
	bool isKeyDown(SDL_Scancode Key);
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	void onKeyUp();
	void onKeyDown();
};

typedef InputHandler TheInputHandler;