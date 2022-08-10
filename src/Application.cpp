#include "Application.h"
#include "mlGame.h"

namespace LE{
    Application::Application(/* args */){
        printf("Starting application\n");
    }
    
    Application::~Application(){
        printf("Killing application\n");
    }

    bool Application::Run(){
        printf("Application is running but is not doing much! \n Running game.");
        return false;
    }
}

int main(int argc, char *argv[]){

    // Just a test, eventually this will be it.
    LE::Application* theApp = new LE::Application();
    while (theApp->Run());
    if(theApp) delete theApp;

    
    mlGame* mpGame = new mlGame();
    while(mpGame->Running());
    if(mpGame) delete mpGame;
    mpGame = nullptr;

    return 0;
}