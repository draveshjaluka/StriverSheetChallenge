/* Question Link: 
https://www.codingninjas.com/studio/problems/893000?topList=striver-sde-sheet-problems */

/* Solution:  The question took me some time but finally got the answer with two pointers approach */


int minCharsforPalindrome(string s) {
	// Write your code here.
	int i=0,j=s.size()-1;

	int ans=0;
	int n=s.size();
	while(i<j)
	{
		if(s[i]==s[j]){i++;j--;}
		else
		{
			ans++;
			i=0;j=n-ans-1;
		}
	}
	return ans;
}

