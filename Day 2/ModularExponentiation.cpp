/* Question Link:
https://www.codingninjas.com/studio/problems/modular-exponentiation_8230803?challengeSlug=striver-sde-challenge */

/* Solution: After reading the question and looking at the easy mark thought it is a simple question and hence simply applied the formula to get the answer but then
read the constraints and follow up to do it in O(log n), hence used another method i.e. divide and conquer method */

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	if(x==0) return 0;
    if(n==0) return 1;
    long ans;
    if(n%2==0)
    {
        long tempa=modularExponentiation(x,n/2,m);
        ans = (tempa * tempa)%m;        
    }
    else
    {
        long tempa=modularExponentiation(x,n-1,m);
        ans=x%m;
        ans=(ans*tempa)%m;
    }

    return (ans%m);
}
