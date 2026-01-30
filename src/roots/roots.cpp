#include <iostream>
#include <iomanip>

#include "roots.hpp"


//Used AI to point out that in my while loops I looked to see if C > 1e-6 not f(C)> 1e-6.
//Also it gave me that neat way to check for the same sign by multiplying the two functions together
// and seeing if its negative and other than one more problem which I listed in the code that is all the AI I used.
bool bisection(std::function<double(double)> f,double a, double b,double *root)
{
    double inptpos = b;
    double inptneg = a;
    double C = (inptpos+inptneg)/2 ;
    
    if((f(a) > 0 and f(b) >0) or (f(a) < 0 and f(b) < 0)){
        return false;
    }
    else {
        while (std::abs(f(C)) > 1e-6)
        {
            if (f(inptneg) * f(C) < 0)
            {
                inptpos = C;
            }
            else{
                inptneg = C;
            }
            C = (inptpos+inptneg)/2;
        }
        *root = C;
        return true;
    }
}

bool regula_falsi(std::function<double(double)> f,double a, double b,double *root)
{
   double inptpos = b;
    double inptneg = a;
    double C = inptneg - f(inptneg)*(inptpos-inptneg)/(f(inptpos)-f(inptneg));
    
    if((f(a) > 0 and f(b) >0) or (f(a) < 0 and f(b) < 0)){
        return false;
    }
    else {
        while (std::abs(f(C)) > 1e-6)
        {
            if (f(inptneg) * f(C) < 0)
            {
                inptpos = C;
            }
            else{
                inptneg = C;
            }
            C = inptneg - f(inptneg)*(inptpos-inptneg)/(f(inptpos)-f(inptneg));
        }
        *root = C;
        return true;
    }
}

bool newton_raphson(std::function<double(double)> f,std::function<double(double)> g,double a, double b, double c,double *root)
{
    double x_n = c; //Used AI here to point out I had an unused parameter C, which I guess was meant to be the guess
    if((f(a) > 0 and f(b) >0) or (f(a) < 0 and f(b) < 0)){
        return false;
    }
    else{
        while(std::abs(f(x_n)) > 1e-6)
        {
            x_n = x_n - f(x_n)/g(x_n);
        }
        *root = x_n;
        return true;
    }
}

bool secant(std::function<double(double)> f,double a, double b, double c,double *root)
{
    double x_n = b;
    double x_n1 = a;
    double buffer;
    if((f(a) > 0 and f(b) >0) or (f(a) < 0 and f(b) < 0)){
        return false;
    }
    else{
        while(std::abs(f(x_n)) > 1e-6)
        {
            buffer = x_n1;
            x_n1 = x_n1 - f(x_n1)*(x_n1 - x_n)/(f(x_n1) - f(x_n));
            x_n = buffer;
        }
        *root = x_n;
        return true;
    }
}