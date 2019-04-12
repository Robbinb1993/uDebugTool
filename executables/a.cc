#include <iostream>
#include "string.h"
#include <algorithm>

using namespace std;

int memo[1000000];

int f(long long n)
{
    if(n==1) return 1;

    if(n>=1000000)
    {
        if(n%2==0) return 1+f(n/2);
        else return 1+f(3*n+1);
    }

    if(memo[n]!=-1) return memo[n];

    int x;
    if(n%2==0) x=1+f(n/2);
    else x=1+f(3*n+1);
    memo[n]=x;
    return x;

}

int main() {
   while (true) {}
   return 0;
}
