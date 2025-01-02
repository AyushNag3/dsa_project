#include<bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 using namespace __gnu_pbds;
#define int long long int 
#define endl "\n"
#define all(v) v.begin(),v.end() 
#define vi vector<int>
#define f(i,e,n) for(int i=e; i<n; i++)
#define cf(i,e,n) for(int i=e; i<=n; i++)
#define yes  cout << "Yes" << endl;
#define no    cout << "No" << endl;
#define pr(a) cout << a << endl ;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> distTo(V, 1e9);

        
        distTo[S] = 0;
        pq.push({0, S});

        
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    
                    pq.push({dis + w, v});
                }
            }
        }
        
        return distTo;
    }
};

void solve() {
   
    int V = 3, E = 3, S = 0;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

signed main()
{
   solve() ;
}