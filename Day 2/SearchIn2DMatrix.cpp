/* Question Link 
https://leetcode.com/problems/search-a-2d-matrix/
https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge */

//Was asked to write code in O(log m*n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=m*n -1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(matrix[mid/n][mid%n]== target) return true;
            if(matrix[mid/n][mid%n]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};
