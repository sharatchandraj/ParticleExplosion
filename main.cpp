#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace std;
using namespace particleExplosion;

int main(int argc, char *argv[])
{
    srand(time(NULL)); //srand seeds the rand() function with a number. We seed it with time() so that
                    //rand() gives us a sequence of random numbers

    Screen screen;
    if(!screen.init()){
        cout<<"Error initializing SDL"<<endl;
    }

    Swarm swarm;


    while(true)
    {
        const Particle *const pParticles = swarm.getParticles();

        int elapsed= SDL_GetTicks();


        swarm.update(elapsed);

        unsigned char green = (1+sin(elapsed*0.0001))*128;
        unsigned char red = (1+sin(elapsed*0.0002))*128;
        unsigned char blue = (1+sin(elapsed*0.0003))*128;

        for(int i =0;i<Swarm::NPARTICLES;i++){
            Particle particle = pParticles[i];

            int x = (particle.m_x+1)*Screen::SCREEN_WIDTH/2;
            int y = particle.m_y*Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x,y,red,green,blue);


        }

        screen.boxBlur();
        screen.update();




       if(!screen.processEvents()){ // to check if user clicked the close window button
        break;
       }
    }

    screen.close();
    return 0;
}
