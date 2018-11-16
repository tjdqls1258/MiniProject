#include "Game.h"
#include "TextureManger.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			
			Instance_load("assets/Player.png", "animate", m_pRenderer);
			Instance_load("assets/BackGround.png", "back", m_pRenderer);
			Instance_load("assets/black.png", "wall1", m_pRenderer);
			Instance_load("assets/fire.png", "fire", m_pRenderer);
			

			m_gameObjects.push_back(new Object(new LoaderParams(0, 0, 640, 480, "back")));

			m_gameObjects.push_back(new Enemy(new LoaderParams(5000, 238, 64, 164, "wall1")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(2000, 320, 64, 164, "wall1")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(1564, 238, 64, 164, "wall1")));
			m_gameObjects.push_back(new Fire(new LoaderParams(1200, 238, 64, 64, "fire")));

			m_gameObjects.push_back(new Player(new LoaderParams(100, 276, 128, 128, "animate")));
			//SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		}
	}
	else
	{
		return false;
	}

	return true;
}


void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

Game::Game()
{

}

// void Game::clean() Ãß°¡ 

void Game::quit()
{
	clean();
}

bool Game::Instance_load(std::string FillName, std::string ID, SDL_Renderer* R)
{
	if (!TheTextureManager::Instance()->load(FillName, ID, R))
	{
		return false;
	}
}