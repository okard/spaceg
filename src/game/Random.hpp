

#pragma once
#ifndef __SPACEG_RANDOM__
#define __SPACEG_RANDOM__


namespace spaceg {
    
/**
* TODO Implement MersenneTwister
* Makoto Matsumoto, Takuji Nishimur
* based on the c implemention of german wikipedia
*/
class MersenneTwister
{
private:
    static const unsigned int N = 624;
    static const unsigned int M = 397;
    static const unsigned int HI = 0x80000000;
    static const unsigned int LO = 0x7fffffff;
    static constexpr unsigned int A[2] = { 0, 0x9908b0df };
    
    //actual list of random words
    unsigned int y[N];
    
    //position in list
    unsigned int pos_;
    
    void calcStateVector();
public:
    MersenneTwister();
    MersenneTwister(unsigned int seed);
    
    //set a seed
    void seed(unsigned int seed);
    
    //run generator n times
    void run(unsigned int runs);

    unsigned int random();
    
    unsigned int random(unsigned int min, unsigned int max);
    
    float randomf();   
};

} // end namespace spaceg

#endif //__SPACEG_RANDOM__