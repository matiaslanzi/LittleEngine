/* 
 * This is the entry point of LittleEngine, a little game engine I am putting
 * together for fun. I think it's pretty simple and pretty cool, I mean it
 * gets me programming my own games in C++ very quickly.
 * 
 * Define your assets in the assets manager (not really a manager). 
 * 
 * Create a state by subclassing mlState.h, this will give you the game loop
 * functions you can use to build the game so use this class to create,
 * initialize and manipulate your game objects.
 * 
 * Push your state into the mStateStack before entering the loop for an empty 
 * stack will quit the game cleanly. All you have to do to quit is take 
 * care of your objects and pop the mStateStack empty.
 * 
 * For convenience must of the classes are singletons like 
 * mlGraphics or mlAssets.
 *
 * For now only main exists, ideally we subclass Application and we should have
 * everything we need to make a game, look into Application.h.
 * 
 * The same idea behind MicroEngine https://github.com/matiaslanzi/MicroEngine.
 * 
 * This should be a shared lib or a dll, it should be separate from the game.
 * But I will deal with that later, I don't think I'm there yet.
 * 
 * The main purpose of this is to learn so please don't kill me programming gurus 
 * if there is a better way to do things or my code sucks. 
 * If you want to reach me you can do so from my website http://matiaslanzi.com
 * Cheers!
 * @matiaslanzi
 */

#include "mlGame.h"

int main(int argc, char *argv[]){

    mlGame* mpGame = new mlGame();

    while(mpGame->Running());

    if(mpGame) delete mpGame;
    
    mpGame = nullptr;

    return 0;
}