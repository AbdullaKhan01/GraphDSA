//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
bool check(int start,int V,vector<int>adj[],int color[])
{
    // Code here
	    queue<int> q;
	    
	    
	    q.push(start);
	    color[start] = 0;
	    while(!q.empty())
	    {
	        int front = q.front();
	        q.pop();
	        for(auto it:adj[front])
	        {
	            if(color[it] == -1)
	            {
	                color[it] = !color[front];
	                q.push(it);
	                
	            }
	            else if(color[it] == color[front]) return false;
	        }
	    }
	    return true;
}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    //TC -> same as BFS
	    //SC -> same as DFS
	    int color[V];
	    for(int i=0;i<V;i++) color[i] = -1;
	    
	    bool flag = true;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i] == -1)
	        {
	            flag = flag && check(i,V,adj,color);
	        }
	    }
	    return flag;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
