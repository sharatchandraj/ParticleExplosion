#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"


namespace particleExplosion
{
class Swarm
{
    public:
        Swarm();
        virtual ~Swarm();
        const static int NPARTICLES = 10000;
        const Particle *const getParticles(){
            return m_particles;
        };
        void update(int elapsed);

    protected:

    private:
         Particle  *m_particles;
         int lastTime;
};
}
#endif // SWARM_H
