//Link to the question: 
//https://leetcode.com/problems/set-matrix-zeroes/
//https://www.codingninjas.com/codestudio/problems/zero-matrix_1171153

/*Solution 1: Read needed to give an in-place solution, so simply thought to find the zero in the matrix position and convert that
row and column into a flag value(I choose INT_MIN as the flag value) keeping in mind if some other zeroes come up I ignored the conversion for it
and finally converted all INT_MIN value to zero for the final loop, this turned up to disaster as I overlooked the constraints and an input of INT_MIN 
was there therefore this solution failed*/

//Anyhow here is the above solution in code

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int fi=0,fj=0;
                if(matrix[i][j]==0)
                {
                    matrix[i][j]=INT_MIN;
                    while(fi<n)
                    {
                        if(matrix[i][fi]!=0) matrix[i][fi]=INT_MIN;
                        fi++;
                    }
                    while(fj<m)
                    {
                        if(matrix[fj][j]!=0) matrix[fj][j]=INT_MIN;
                        fj++;
                    }
                }
                else continue;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==INT_MIN) matrix[i][j]=0;
            }
        }
    }
};

/*Solution 2: Now after a bit of thinking I thought of using a map but it wanted a solution with constant space then decided to use the first row and col as a map
to mark the zeroes, also used flag values if the first row or col itself contained a zero, then it was pretty straight forward*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fi=false,fj=false;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)if(matrix[i][0]==0)fi=true;
        for(int i=0;i<n;i++)if(matrix[0][i]==0)fj=true;
        //cout<<1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
       for(int i=1;i<m;i++)
       {
           for(int j=1;j<n;j++)
           {
               if(matrix[i][0]==0 || matrix[0][j]==0)
               {
                   matrix[i][j]=0;
               }
           }
       }
       if(fi)
       {
           for(int i=0;i<m;i++) matrix[i][0]=0;
       }
       if(fj)
       {
           for(int i=0;i<n;i++) matrix[0][i]=0;
       }

    }
};
