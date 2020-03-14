#ifndef PARTICLE_H
#define PARTICLE_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI

namespace particleExplosion
{
struct Particle
{
    public:
        double m_speed;
        double m_direction;

        Particle();
        virtual ~Particle();
        void init();
        double m_x;
        double m_y;
        void update(int interval);



    protected:

    private:

};
}
#endif // PARTICLE_H
