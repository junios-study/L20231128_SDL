#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning) //message loop
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			IsRunning = false;
			break;
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
			break;
		}
		//명령어 죄다 저장
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0x00);
		SDL_RenderClear(MyRenderer);

//		SDL_RenderDrawRect()

		SDL_RenderPresent(MyRenderer);
	}

	SDL_Quit();
	return 0;
}