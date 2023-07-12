/* Question Link:
https://www.codingninjas.com/studio/problems/maximum-meetings_1062658 */

/*Solution sorted the meetings according to conditions and then traverse the sorted data comparing current start time with end time of last one */

struct meeting{
    int st;
    int en;
    int po;
};
bool static cmp(struct meeting m1,struct meeting m2)
{
    if(m1.en<m2.en) return true;
    else if(m1.en>m2.en) return false;
    else if(m1.po<m2.po) return true;
    return false;
}
int maximumMeetings(vector<int> &s, vector<int> &e)
{
    // Write your code here
    int n=e.size();
    struct meeting m[n];
    for(int i=0;i<n;i++)
    {
        m[i].st=s[i];m[i].en=e[i];m[i].po=i+1;
    }

    sort(m,m+n,cmp);

    int ans=0;

    int last=m[0].en;
    for(int i=1;i<n;i++)
    {
        if(m[i].st>last)
        {
            last=m[i].en;
            ans++;
        }
    }
    return ans+1;
}
