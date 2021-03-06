#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

#ifdef EXECUTION_TIME_COMPUTATION
#include <chrono> 
using namespace std::chrono; 
#endif 

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

inline void printProgress (double percentage)
{
    int val  = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}

inline float
degrees_to_radians(float a)
{
    return a*(M_PI/180.0f);
}

template <typename T>
T lerp(const T& A, const T& B, float t)
{
    return (1.0f-t) * A + t * B;
}

template<typename T> void
safe_delete(T*& ptr)
{
    if(ptr) { delete   ptr; ptr = nullptr; }
}

template <typename T> void
safe_array_delete(T *&ptr)
{
    if(ptr) { delete[] ptr; ptr = nullptr; }
}

#endif