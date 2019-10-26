class Solution {
public:
    
    bool isvalid(vector<vector<char>>&b,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
            if(b[row][i]==c)
                return false;
        for(int i=0;i<9;i++)
            if(b[i][col]==c)
                return false;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(b[row/3*3+i][col/3*3+j]==c)
                    return false;
        return true;
        
    }
    
    bool solve(vector<vector<char>>&b)
    { 
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
               if(b[i][j]=='.')
               {
                    for(int k=0;k<9;k++)
                    {
                       if(isvalid(b,i,j,'1'+k))
                       {
                           b[i][j]='1'+k;
                           if(solve(b))
                               return true;
                           else
                              b[i][j]='.'; 
                       }
                    }
                   return false;
               }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
     
        //main called function
        solve(b);
        
    }
};