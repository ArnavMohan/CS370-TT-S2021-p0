#ifndef __TEST_H__
#define __TEST_H__

#include "mathlib.h"
#include <string>
#include <assert.h>

const unsigned N_THREAD = 10;

template <typename T>
std::string calls(T a, T b){
        using namespace mathlib;
        T m = max<T>(a,b);
        assert(isgreaterequal<T>(m,min<T>(a,b)) == (T)1);
        T rad = mult<T>(b, (T)57.2958);
        T err = sub<T>(tan<T>(rad,' '), div<T>(sin<T>(rad,' '), cos<T>(rad,' ')));
        if(isgreater<T>(round<T>(err),(T)0)) err = floor<T>(err);

        T logn = ln<T>(b);
        T approxlogn = logb<T>(b,2.71);
        T logerr = abs<T>(sub<T>(logn, approxlogn));
        assert(logerr >= (T)0); // should not log

        assert(isequal<T>(mean<T>(a,b), div<T>(add<T>(a,b),2)) == (T) 1);

        T h = cos<T>(a,'h');
        assert(isgreater<T>(h,1) == (T) 1);

        h = hyperpow<double>(5.0,2.0);
        T r = nroot<T>(h,5.0);
        assert(isequal<T>(r,pow<T>(5.0,5.0)) == (T)1);
        gcd<T>(a,b);
        h = hyperpow<T>(5,2);
        r = nroot<T>(h,5);
        assert(isequal<T>(r,pow<T>(5,5)) == (T)1);
        gcd<T>(a,b);
        return "";
}

#endif
