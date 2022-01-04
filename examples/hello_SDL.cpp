#include "SDL.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main ([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        std::cout<<"SDL could not initialize!"<<std::endl;
    }
    else
    {
        window = SDL_CreateWindow ("SDL example",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            std::cout<<"Window could not be created! SDL_Error"<<std::endl;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface (window);

            SDL_FillRect (screenSurface,
                          nullptr,
                          SDL_MapRGB (screenSurface->format, 0xcc, 0x55, 0xbb));

            SDL_UpdateWindowSurface (window);

            SDL_Delay (2000);
        }
    }

    SDL_DestroyWindow (window);
    SDL_Quit();

    return 0;
}