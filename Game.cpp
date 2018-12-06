#include "Game.h"
#include "TextureManger.h"
#include "InputHandler.h"
#include "MenuState .h"
#include "PlayState.h"
Game* Game::s_pInstance = 0;
PlayState* m_pPlayState;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			
			//이미지 로드
			/*Instance_load("assets/Player.png", "animate", m_pRenderer);
			Instance_load("assets/BackGround.png", "back", m_pRenderer);
			Instance_load("assets/black.png", "wall1", m_pRenderer);
			Instance_load("assets/fire.png", "fire", m_pRenderer);
			
			//객체 푸시
			m_gameObjects.push_back(new Object(new LoaderParams(0, 0, 640, 480, "back")));

			m_gameObjects.push_back(new Enemy(new LoaderParams(5000, 238, 64, 164, "wall1")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(2000, 320, 64, 164, "wall1")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(1564, 238, 64, 164, "wall1")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(7200, 238, 64, 164, "wall1")));

			m_gameObjects.push_back(new Fire(new LoaderParams(1200, 238, 64, 64, "fire")));
			m_gameObjects.push_back(new Fire(new LoaderParams(3200, 238, 64, 64, "fire")));
			m_gameObjects.push_back(new Fire(new LoaderParams(6200, 238, 64, 64, "fire")));

			m_gameObjects.p
			m_ush_back(new Player(new LoaderParams(100, 276, 128, 128, "animate")));*/

		}
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());
	}
	else
	{
		return false;
	}

	return true;
}


void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	m_bRunning = false;
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
}

Game::Game()
{

}

// void Game::clean() 추가 

void Game::quit()
{
	clean();
}

