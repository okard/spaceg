

#include "Random.hpp"

#include <ctime>

using namespace spaceg;


constexpr unsigned int MersenneTwister::A[];


MersenneTwister::MersenneTwister()
    : pos_(0)
{
    this->seed(time(NULL));
}

MersenneTwister::MersenneTwister(unsigned int seed)
    : pos_(0)
{
    this->seed(seed);
}

void MersenneTwister::seed(unsigned int seed)
{
    /* Initialisiere y mit Pseudozufallszahlen */
    y[0] = seed;
 
    for (int i=1; i<N; ++i) 
    {
      y[i] = (1812433253UL * (y[i-1] ^ (y[i-1] >> 30)) + i);
      /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
      /* In the previous versions, MSBs of the seed affect   */
      /* only MSBs of the array mt[].                        */
      /* 2002/01/09 modified by Makoto Matsumoto             */
    }
    
    calcStateVector();
}

void MersenneTwister::calcStateVector()
{
    // calculate new state vector
    unsigned int h;
    unsigned int i;
    
    for (i=0; i<N-M; ++i) 
    {
      h = (y[i] & HI) | (y[i+1] & LO);
      y[i] = y[i+M] ^ (h >> 1) ^ A[h & 1];
    }
    
    for (; i<N-1; ++i) 
    {
      h = (y[i] & HI) | (y[i+1] & LO);
      y[i] = y[i+(M-N)] ^ (h >> 1) ^ A[h & 1];
    }
 
    h = (y[N-1] & HI) | (y[0] & LO);
    y[N-1] = y[M-1] ^ (h >> 1) ^ A[h & 1];
}


//run generator n times
void MersenneTwister::run(unsigned int runs)
{
    for(int i=0; i < runs; i++)
        random();
}

unsigned int MersenneTwister::random()
{
    if(pos_ == N)
    {
        calcStateVector();
        pos_=0;
    }
    
    unsigned int e = y[pos_++];
    /* Tempering */
    e ^= (e >> 11);
    e ^= (e << 7) & 0x9d2c5680;
    e ^= (e << 15) & 0xefc60000;
    e ^= (e >> 18);
 
    return e;
}

unsigned int MersenneTwister::random(unsigned int min, unsigned int max)
{
    return random() % max + min;
}

float MersenneTwister::randomf()
{
    return static_cast<float>(random());
}
