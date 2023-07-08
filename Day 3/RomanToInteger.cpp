/* Question Link: 
https://leetcode.com/problems/roman-to-integer/
https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_981308 */

/* Solution: Creadted a simple map of roman characters to their value and traversed the roman string backward with simple logic that, the roman character previous to
current roman character shoudl >= value to add else subtract and get the desired answer */

int romanToInt(string s) {
    // Write your code here
    unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans=m[s[s.size()-1]];
        for(int i=s.size()-1;i>0;i--)
        {
            if(m[s[i-1]]>=m[s[i]]) ans+=m[s[i-1]];
            else ans-=m[s[i-1]];
        }
        return ans;
}
 
