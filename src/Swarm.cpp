#include "Swarm.h"

namespace particleExplosion
{
Swarm::Swarm(): lastTime(0){
    m_particles = new Particle[NPARTICLES];
    //ctor
}

void Swarm::update(int elapsed){

    int interval = elapsed - lastTime;
    for(int i =0;i<Swarm::NPARTICLES;i++){
            m_particles[i].update(interval);

    }

    lastTime = elapsed;
}

Swarm::~Swarm()
{
    //dtor
    delete [] m_particles;
}
}
