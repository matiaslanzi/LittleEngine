# LittleEngine
Simple SDL game engine

Added make file

Messy for now, I am working on cleaning it to continue development. I got rid of all empty classes, you know the ones you put there as placeholders for your dreams.

In the mean time I wrote a [mini version of the engine MicroEngine](https://github.com/matiaslanzi/MicroEngine) to be able to quickly prototype or visualize.

Oh and there is no make file, I use to compile this with a bash script, duh! so I'm getting into make now where I should be getting acquainted with Cmake. But I really want to have the make basics down.

## Compiling
I added a makefile with the intention of making it simple, I don't know if I accomplished it.
In order to compile this, create a symlinks of your libraries in your project. Put the includes in the include directory and the lib on the lib directory of your project, then just run `make` command.
[This is a great video about it](https://youtu.be/Dyz9O7s7B8w)

I am trying to figure out how to deal with multiple architectures. That is the thing to learn for me.
If you have any suggestions please feel free to contact me through [my website](https://matiaslanzi.com)

## Dependencies 
This engine is using SDL lib to display things on screen so we need to use the following dependencies:
SDL2, SDL2_ttf, SDL2_image. Make sure the libraries exist in your system and that you have symlinked the appropriate directories as stated in the above section.

## Usage
The engine pushes a mlState class into `mlStateStack` in mlGame class. 
The stack it's public in mlGame so pass mlGame to your state.

The first state loaded is the mlStateSplashState, and if you push `space bar` then mlStateGame gets stacked. 
When you win the game mlStateGame gets popped and we return to the mlStateSplashState. 
Escape key will keep popping states and quit the program.

You can manage your states as you wish, I usually use something like this:
splashState > menuState > gameState > winstate
Often times need to jump around but it works.

No input is handled in the game so it's up to you to handle the SDL_QUIT event type, take a look at each state file it will make sense.

## Contributions
Please feel free to contribute to this project. I marked with TODO: the stuff that can be made better and of course any ideas are welcome.

Hope this is as useful for you as it was for me writing it. I claim no status in these programming matters other than longevity. I am just having fun. I love C++ and my only hope is to continue learning.

Thank you.

@matiaslanzi

[www.matiaslanzi.com](https://matiaslanzi.com)

-