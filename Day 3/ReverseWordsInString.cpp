/* Question Link:
https://bit.ly/3FmKc1X
https://leetcode.com/problems/reverse-words-in-a-string/ */

/* Solution: There were several solutions for this question but all of them had one thing in common and that was first I need to remove the unwanted space in the
given string, so did that using pointers and then used the erased function to remove the unwanted characters at the end.

Solution 1: After this, the first option that came to
mind was to reverse each word and then reverse the whole string to get the answer */

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (i != 0 && j != s.size()) s[i++] = ' ';
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
        }
        s.erase(i);
        i=0,j=0;
        while(j<s.size())
        {
            i=j;
            while(i<s.size() && s[i]!=' ')i++;
            reverse(s.begin()+j,s.begin()+i);
            j=i+1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

/* Though the above solution was good but it involved reverse function and that too twice which consumes time, hence started thinking of another solution
Solution 2: Same removed the unwanted space from the start and the end and ignored the space in between(instead of removing it), now whenever I got a word in
a temporary string I inserted that word at the start of my answer with an additional this way I saved a lot of time and came up a with a better solution using some
space*/

class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        int left=0,right=s.size()-1;
        while(s[left]==' ') left++;
        while(s[right]==' ') right--;
        while (left <= right) {
            if (s[left] != ' ') {
                temp += s[left];
            }
            else {
                if (s[left - 1] == ' ') {
                    left++;
                    continue;
                }
                else {
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
            left++;
        }
        //cout<<temp;
        ans=temp+" "+ans;
        ans.erase(ans.begin() + ans.length() - 1);
        return ans;
    }
};
