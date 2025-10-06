#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "Walter in San Diego: It's hard to be alive";

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main game loop
    bool running = true;
    SDL_Event event;

    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }

        // Clear screen with a sky blue color
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);

        // Draw a simple ground (green rectangle at the bottom)
        SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
        SDL_Rect ground = {0, WINDOW_HEIGHT - 100, WINDOW_WIDTH, 100};
        SDL_RenderFillRect(renderer, &ground);

        // Draw a simple character (Walter) - a simple stick figure
        // Head
        SDL_SetRenderDrawColor(renderer, 255, 220, 177, 255);
        SDL_Rect head = {WINDOW_WIDTH / 2 - 20, WINDOW_HEIGHT / 2 - 60, 40, 40};
        SDL_RenderFillRect(renderer, &head);

        // Body
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_Rect body = {WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT / 2 - 20, 30, 50};
        SDL_RenderFillRect(renderer, &body);

        // Legs
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_Rect leftLeg = {WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT / 2 + 30, 10, 30};
        SDL_Rect rightLeg = {WINDOW_WIDTH / 2 + 5, WINDOW_HEIGHT / 2 + 30, 10, 30};
        SDL_RenderFillRect(renderer, &leftLeg);
        SDL_RenderFillRect(renderer, &rightLeg);

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Cap frame rate at ~60 FPS
        SDL_Delay(16);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
