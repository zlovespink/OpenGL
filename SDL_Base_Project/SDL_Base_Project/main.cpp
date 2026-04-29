#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Test", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    SDL_Surface* surface = IMG_Load("C:/Users/Public/Downloads/image1.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    SDL_Surface* surface1 = IMG_Load("C:/Users/Public/Downloads/image2.jpg");
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_DestroySurface(surface1);


    SDL_Surface* surface2 = IMG_Load("C:/Users/Public/Downloads/image3.jpg");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_DestroySurface(surface2);


    SDL_Surface* surface3 = IMG_Load("C:/Users/Public/Downloads/image4.jpg");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_DestroySurface(surface3);


    SDL_FRect imgrect = { 300, 0, 200, 200 };
    SDL_FRect imgrect1 = { 100, 200, 200, 200 };
    SDL_FRect imgrect2 = { 500, 200, 200, 200 };
    SDL_FRect imgrect3 = { 300, 400, 200, 200 };


    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, &imgrect);
        SDL_RenderTexture(renderer, texture1, NULL, &imgrect1);
        SDL_RenderTexture(renderer, texture2, NULL, &imgrect2);
        SDL_RenderTexture(renderer, texture3, NULL, &imgrect3);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}