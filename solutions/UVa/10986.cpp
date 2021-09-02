#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

struct edge{
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}

    bool operator < (const edge &e) const{
        return e.w < w;
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t;
    cin >> t;
    for(int cse = 1; cse <= t; cse++){
        int n,m,s,e;
        cin >> n >> m >> s >> e;

        vector<vector<edge>> adj(n + 1);
        for(int i = 0; i<m; i++){
            int u,v,c;
            cin >> u >> v >> c;
            adj[u].push_back(edge(u, v, c));
            adj[v].push_back(edge(v, u, c));
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<edge> q;
        q.push(edge(-1, s, 0));
        dist[s] = 0;
        while(!q.empty()){
            edge eg = q.top();
            q.pop();

            if(eg.w > dist[eg.to]) continue;
            if(eg.to == e) break;

            int u = eg.to;
            for(edge ne : adj[u]){
                int v = ne.to;
                if(dist[v] > dist[u] + ne.w){
                    dist[v] = dist[u] + ne.w;
                    ne.w = dist[v];
                    q.push(ne);
                }
            }
        }

        cout << "Case #" << cse << ": ";
        if(dist[e] < 1e9)
            cout << dist[e];
        else
            cout << "unreachable";
        cout << '\n';
    }
}

