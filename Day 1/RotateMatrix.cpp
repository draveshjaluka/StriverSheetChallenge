/*Question Rotate Matrix:
Leetcode Link: https://leetcode.com/problems/rotate-image/
Coding Ninja Link: https://bit.ly/3rhVUWx */

/* this time both platform has slight different question, this Solution is of leetcode, used simple swap functions to achieve the required result*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       for(int i=0;i<matrix.size();i++)
        {
            int s=0,e=matrix.size()-1;
            while(s<e)
            {
                swap(matrix[i][s],matrix[i][e]);
                s++;e--;
            }
        }
    }
};

/*Coding Ninja question this question was a bit tricky compared to the above here it asked to rotate the element in a clockwise manner*/
//Took some to understand that it is actually saying to turn the elements clockwise border wise, finally wrote the code

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int m, int n)
{
    // Write your code here
    int prev,curr;
    int row=0,col=0;
    while(row<m && col<n)
    {
        if(row+1==m || col+1 ==n) break;
        prev= mat[row+1][col];
        for(int i=col;i<n;i++)
        {
            curr=mat[row][i];
            mat[row][i]=prev;
            prev=curr;
        }
        row++;
        for(int i=row;i<m;i++)
        {
            curr=mat[i][n-1];
            mat[i][n-1]=prev;
            prev=curr;
        }
        n--;
        if(row<m)
        {
            for(int i=n-1;i>=col;i--)
            {
                curr=mat[m-1][i];
                mat[m-1][i]=prev;
                prev=curr;
            }
        }
        m--;
        if(col<n)
        {
            for(int i=m-1;i>=row;i--)
            {
                curr=mat[i][col];
                mat[i][col]=prev;
                prev=curr;
            }
        }
        col++;
        
    }

}
