#include <bits/stdc++.h>
using namespace std;

/* {
 
 Can occour in DAG only 

} */

class Solution
{
    void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[node])
                dfs(it, adj, st, vis);
        }
        st.push(node);
    }

public:
    void tropSort(int V, vector<int>adj[]){

        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++){

            if (!vis[i])
                dfs(i, adj, st, vis);
        }

        vector<int> res;

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};