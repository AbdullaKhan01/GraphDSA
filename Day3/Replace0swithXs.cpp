//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int row,int col,int n,int m)
    {
        if(row >= 0 && row < n && col >=0 && col < m) 
        {
            return true;
        }
        else return false;
    }
    void dfs(vector<vector<char>>&mat,vector<vector<int>>&visited,int row,int col)
    {
        visited[row][col] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(isValid(nrow,ncol,mat.size(),mat[0].size()))
            {
                if(!visited[nrow][ncol] && mat[nrow][ncol] == 'O')
                {
                    dfs(mat,visited,nrow,ncol);
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //for first and last row
        for(int j=0;j<m;j++)
        {
            if(!visited[0][j] && mat[0][j] == 'O')
            {
                dfs(mat,visited,0,j);
            }
            if(!visited[n-1][j] && mat[n-1][j] == 'O')
            {
                dfs(mat,visited,n-1,j);
            }
        }
        
        //for first and last column
        
        for(int i=0;i<n;i++){
            if(!visited[i][0] && mat[i][0] == 'O')
            {
                dfs(mat,visited,i,0);
            }
            
            if(!visited[i][m-1] && mat[i][m-1] == 'O')
            {
                dfs(mat,visited,i,m-1);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 'O' && !visited[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
