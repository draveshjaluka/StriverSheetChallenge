/* Question Link: 
https://leetcode.com/problems/valid-anagram/
https://www.codingninjas.com/studio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge */

/* Solution: could have done in O(1) constant space but it was mentioned in follow up to change the code for all unicode characters, hence used map to solve it */

class Solution {
public:
    bool isAnagram(string s1, string s2) {
    unordered_map<char,int> m;
    if(s1.size()!=s2.size()) return false;
    for(int i=0;i<s1.size();i++)
    {
        m[s1[i]]++;
        m[s2[i]]--;
    }
    for(auto it:m)
    {
        if(it.second!=0) return false;
    }
    return true;
    }
};
