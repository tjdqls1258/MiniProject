#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			SDL_Surface *pTempSurface = IMG_Load("assets/animate-alpha.png");
			SDL_Surface *pTempBackGround = IMG_Load("assets/BackGround.png");

			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			b_gTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempBackGround);

			//SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			//SDL_SetRenderDrawColor(b_pRenderer, 0, 0, 0, 255);

			SDL_FreeSurface(pTempSurface);
			SDL_FreeSurface(pTempBackGround);
			//플레이어
			m_sourceRectangle.w = 128;
			m_sourceRectangle.h = 82;

			m_destubationRetangle.x = 10;
			m_destubationRetangle.y = 320;
			m_sourceRectangle.x = 0;
			m_sourceRectangle.y = 0;

			m_destubationRetangle.h = m_sourceRectangle.h;
			m_destubationRetangle.w = m_sourceRectangle.w;

			//배경
			b_sourceRectangle.w = 640;
			b_sourceRectangle.h = 480;

			b_destubationRetangle.x = b_sourceRectangle.x = 0;
			b_destubationRetangle.y = b_sourceRectangle.y = 0;

			b_destubationRetangle.h = b_sourceRectangle.h;
			b_destubationRetangle.w = b_sourceRectangle.w;
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
	SDL_RenderClear(m_pRenderer);
	
	SDL_RenderCopy(m_pRenderer, b_gTexture, &b_sourceRectangle, &b_destubationRetangle);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destubationRetangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	b_sourceRectangle.x = 1 * int(((SDL_GetTicks() / 10) % 3200));
}