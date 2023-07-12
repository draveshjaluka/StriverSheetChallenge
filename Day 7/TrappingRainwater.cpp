/* Question link:
https://leetcode.com/problems/trapping-rain-water/
https://www.codingninjas.com/studio/problems/trapping-rain-water_630519 */

/* Question Link, it clearly gives hint to se two pointer marking height of min and max between right, did that in a different way */
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();   
        vector<int>lmax(n),rmax(n); 
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(height[i-1],lmax[i-1]);
        }
        for(int i=n-2;i>=0;--i)
        {
            rmax[i]=max(rmax[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int water= min(lmax[i],rmax[i]);
            if(water>=height[i]) ans+=water - height[i];
        }
        return ans;
    }
};
