//
//  main.m
//  SDL3Test
//
//  Created by Matias Lanzi on 7/3/25.
//


#include <iostream>
#include <cmath>

#include <SDL3/SDL.h>

float ratio = 16.0f/9.0f;
float height = 600;
float width = height * ratio;
int centerX = width / 2;    
int centerY = height / 2;

float frameRate = 30.0f;
int skipTicks = (1.0f/frameRate) * 1000; // Milliseconds per frame

float frameFinish = 0;
float deltaTime = 0.0f;
float speedScale = .1f;
uint64_t frameCount = 0;



int main(int argc, const char * argv[]) {

    
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Hello", width, height, SDL_WINDOW_RESIZABLE);
    
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    
    if (!renderer){
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    // loop
    bool running = true;
    SDL_Event event;
    int destPointX, destPointY;
    int amplitude = 50;
    
    float lastFrameTime = SDL_GetTicks();
    
    while (running) {
        
        // Input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        
        // Timing
        float currentTime = SDL_GetTicks();
        if (currentTime >= frameFinish + skipTicks) {
            
            // Calculate delta time
            deltaTime = (currentTime - lastFrameTime) * 0.001f;
            lastFrameTime = currentTime;
            
            // Update
            destPointX = sin(frameCount*speedScale)*amplitude;
            destPointY = cos(frameCount*speedScale)*amplitude;
            
            // Draw
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderLine(renderer, centerX - destPointX, centerY - destPointY, centerX + destPointX, centerY + destPointY);
            SDL_RenderPresent(renderer);
            
            // Update frame timing
            frameCount++;
            frameFinish = SDL_GetTicks();
        } else {
            SDL_Delay(1); // Prevent busy waiting
        }
    }
    
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    
    SDL_Quit();
    
    return 0;
}
