
#include <hornero/thirdparty/sdl/sdl.hpp>

void hornero::thirdparty::sdl::Init()
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);
}

void hornero::thirdparty::sdl::Quit()
{
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
