/* Question Link:
https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400 */

/* Solution: Intution was to point intersection times drawed on paper as a time line and found a good solution */

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    if(n==0) return 0;
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}
