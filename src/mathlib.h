//
//Simplified cmath library for this assignment
//Inspired by and uses the GNU C++ Library
//
//You should not need to modify this file for a valid solution, but it is allowed
//

#ifndef __MATHLIB_H__
#define __MATHLIB_H__

#include <cmath>

namespace mathlib {

  template <typename R>
    R add (double x, double y)
    {
      return (R) (x + y);
    }

	//subtraction
        template <typename R>
        R sub(double x, double y){
                return (R) (x - y);
        }

        //multiplication
        template <typename R>
        R mult(double x, double y){
                return (R) (x * y);
        }

	//modulo
        template <typename R>
        R mod(double x, double y){
                return (R) std::fmod(x,y);
        }

	//absolute value
	template <typename R>
	R abs(double x, char noarg=' '){
		return (R) ((x > 0) ? x : mathlib::mult<R>((R)-1,(R)x));
	}

	//floor
	template <typename R>
	R floor(double x, char noarg=' '){
		return (R) (sub<R>(x,mod<R>((R)x,(R)1)));
	}

	//ceiling
	template <typename R>
	R ceil(double x, char noarg=' '){
		return (R) mult<R>((R)-1,floor<R>(mult<R>((R)-1,(R)x)));
	}

	//round to nearest
	template <typename R>
	R round(double x, char noarg=' '){
		return (R) ((x < 0) ? (int)(x-0.5) : (int)(x+0.5));
	}

	//minimum
	template <typename R>
	R min(double x, double y){
		return (R) ((x > y) ? y : x);
	}

	//maximum
	template <typename R>
	R max(double x, double y){
		return (R) ((x > y) ? x : y);
	}

	//factorial
	template <typename R>
	R fact(double x){
		double f = 1;
		for(int i = 1; i <= (int)x; ++i){
			f = mult<R>((R)f,(R)i);
		}
		return (R) f;
	}

	//sin(double arg, char mode)
	//mode = default -> sin(arg)
	//mode = 'h' -> sinh(arg)
	//mode = 'a' -> arcsin(arg)
	template <typename R>
	R sin(double x, char mode){
		switch(mode){
			case 'h' : return (R) std::sinh(x);
			case 'a' : return (R) std::asin(x);
			default :  return (R) std::sin(x);
		}
	}

	//cos(double arg, char mode)
	template <typename R>
        R cos(double x, char mode){
                switch(mode){
                        case 'h' : return (R) std::cosh(x);
                        case 'a' : return (R) std::acos(x);
                        default :  return (R) std::cos(x);
                }
        }

	//tan(double arg, char mode)
	template <typename R>
        R tan(double x, char mode){
                switch(mode){
                        case 'h' : return (R) std::tanh(x);
                        case 'a' : return (R) std::atan(x);
                        default :  return (R) std::tan(x);
                }
        }

	//e^x
	template <typename R>
	R exp(double x, char noarg=' '){
		return (R) std::exp(x);
	}

	//log_b x
	template <typename R>
	R logb(double x, double base){
		return (R) (std::log(x) / std::log(base));
	}

	//log_10 x
	template <typename R>
	R log10(double x, char noarg=' '){
		return (R) std::log10(x);
	}

	//ln x
	template <typename R>
	R ln(double x, char noarg=' '){
		return (R) std::log(x);
	}

	//square root
	template <typename R>
	R sqrt(double x, char noarg=' '){
		return (R) std::sqrt(x);
	}

	//x^y
	template <typename R>
	R pow(double x, double y){
		return (R) std::pow(x,y);
	}

	//tetration
	template <typename R>
	R hyperpow(double x, double y){
		double z;
		if(y <= 0) return 0;
		for(z = x; y > 1; y--) z = std::pow(x,z);
		return (R) z;
	}

	//truncation
	template <typename R>
	R trunc(double x, char noarg=' '){
		return (R) std::trunc(x);
	}

	//division
	template <typename R>
	R div(double x, double y){
		return (R) (x / y);
	}

	//gcd
	template <typename R>
	R gcd(double x, double y){
		if(x == 0) return y;
		return gcd<R>(mod<R>((R)y,(R)x),(R)x);
	}

	//lcm
	template <typename R>
	R lcm(double x, double y){
		return (R) ((x / gcd<R>((R)x,(R)y)) * y);
	}

	//cube root
	template <typename R>
	R cbrt(double x, char noarg=' '){
		return (R) std::cbrt(x);
	}

	//greater than
	template <typename R>
	R isgreater(double x, double y){
		return (R) std::isgreater(x,y);
	}

	//less than
	template <typename R>
	R isless(double x, double y){
		return (R) std::isless(x,y);
	}

	//>=
	template <typename R>
	R isgreaterequal(double x, double y){
		return (R) std::isgreaterequal(x,y);
	}

	//<=
	template <typename R>
	R islessequal(double x, double y){
		return (R) std::islessequal(x,y);
	}

	//==
	template <typename R>
	R isequal(double x, double y){
		return (R) (x == y);
	}

	//!=
	template <typename R>
	R isneq(double x, double y){
		return (R) !(x == y);
	}

	//nth root of x
	template <typename R>
	R nroot(double x, double y){
		return pow<R>((R)x,div<R>((R)1,(R)y));
	}

	//mean of x, y
	template <typename R>
	R mean(double x, double y){
		return div<R>(add<R>((R)x,(R)y),(R)2);
	}
}

#endif
