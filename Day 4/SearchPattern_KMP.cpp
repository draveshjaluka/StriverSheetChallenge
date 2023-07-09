/* Question Link: 
https://www.codingninjas.com/studio/problems/search-pattern-kmp-algorithm_8416386 */

/* Solution: No idea what kmp algorithm was, so I headed to youtube to understand the concept of the algorithm by watching abdul bari's video but was confused with the
coding part but gfg help me out */

void lpsa(string pat,int m,int *lps)
{
	int len=0;
	lps[len]=0;
	int i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else 
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
vector<int> stringMatch(string txt, string pat) {
	// Write your code here.
	int m=pat.size();
	int n=txt.size();
	vector<int>ans;
	int lps[m];
	lpsa(pat,m,lps);
	int i=0,j=0;
	while((n-i)>=(m-j))
	{
		if(txt[i]==pat[j])
		{
			i++;j++;
		}
		if(j==m)
		{
			ans.push_back(i-j+1);
			j=lps[j-1];
		}
		else if(i<n && pat[j]!=txt[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else i=i+1;
		}
	}
	return ans;
}

