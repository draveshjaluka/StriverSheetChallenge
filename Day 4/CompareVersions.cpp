/* Question Link
https://leetcode.com/problems/compare-version-numbers/
https://www.codingninjas.com/studio/problems/compare-version-numbers_8230793?challengeSlug=striver-sde-challenge */

//Total 3 Solutions:
/* Solution 1: Tried an iterative approach this was my first thought which I gave into this problem compared number dot wise, AC on both Coding Ninjas & LeetCode */

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int s1=v1.size();
        int s2=v2.size();
        vector<int> n1;vector<int>n2;
        long long temp=0;
        for(int i=0;i<s1;i++)
        {
            if(v1[i]=='.')
              {n1.push_back(temp); temp=0;}
            else
                temp=temp*10 + v1[i]-'0';
        }
        n1.push_back(temp);
        temp=0;
        for(int i=0;i<s2;i++)
        {
            if(v2[i]=='.')
              {n2.push_back(temp); temp=0;}
            else
                temp=temp*10 + v2[i]-'0';
        }
        n2.push_back(temp);
        s1=n1.size();
        s2=n2.size();
       /* for(int i=0;i<s1;i++)cout<<n1[i]<<" "; 
        for(int i=0;i<s2;i++)cout<<n2[i]<<" "; */
        if(s1>s2)
        {
            for(int i=0;i<s1-s2;i++)
            {
                n2.push_back(0);
            }
        }
        if(s2>s1)
        {
            for(int i=0;i<s2-s1;i++)
            {
                n1.push_back(0);
            }
        }
        s1=n1.size();
        for(int i=0;i<s1;i++)
        {
            if(n1[i]> n2[i]) {return 1;}
            if(n1[i]<n2[i]) return -1;
        }
        return 0;
    }
};

/* Solution 2 after wrting such a long code I check I am breaking this into small problem i.e. number into each dots and then comparing them so thought to apply
this logic in recursive manner and hence came up with second solution, using a recursive call, AC on leetcode & partially passed on coding ninjas */

class Solution {
public:
    int compareVersion(string v1, string v2) {
        if(v1.size()==0 && v2.size()==0) return 0;
        long long n1=0,n2=0;
        long long s1=0,s2=0;

        while(s1<v1.size())
        {
            if(v1[s1]=='.') { s1++;break;}
            n1=n1*10 + (v1[s1]-'0');
            s1++;
        }
        while(s2<v2.size())
        {
            if(v2[s2]=='.'){s2++;break;}
            n2=n2*10 + v2[s2] - '0';
            s2++;
        }

        if(n1>n2) return 1;
        if (n2>n1) return -1;
        return compareVersion(v1.substr(s1,v1.size()-s1),v2.substr(s2,v2.size()-s2));

    }
};

/* Then converted the above recursive method into iterative again but this time wrote smart version of solution 1 */

#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    int i=0,j=0;
    while(i<a.length() || j<b.length())
    {
        long long int n1=0,n2=0;
        while(i<a.length() && a[i]!='.')
        {
            n1 = n1*10 + (a[i]-'0');
            i++;
        }
        while(j<b.length() && b[j]!='.')
        {
            n2 = n2*10 + (b[j]-'0');
            j++;
        }
        if(n1>n2) return 1;
        else if(n1<n2) return -1;
        i++;
        j++;
    }
    return 0;
}
