#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;
const int oo = 1e9+1;

struct edge{
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}

    bool operator < (const edge &e) const{
        return e.w < w;
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,k;
    while(cin >> n >> k){
        vector<int> time(n);
        for(int &x : time)
            cin >> x;

        int dist[101][6];
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 6; j++){
                dist[i][j] = oo;
            }
        }
        priority_queue<pair<edge,int>> q;

        cin.ignore();
        vector<vector<pair<edge, int>>> adj(101);
        for(int i = 0; i < n; i++){
            string s;
            getline(cin, s);
            stringstream ss(s);

            int u,v;
            ss >> u;
            if(u == 0){
                dist[0][i] = 0;
                q.push({edge(-1, 0, 0) , i});
            }
            while(ss >> v){
                int w = abs(u-v) * time[i];
                adj[u].push_back({edge(u, v, w), i});
                adj[v].push_back({edge(v, u, w), i});
                u = v;
            }
        }

        bool flag = true;
        while(!q.empty()){
            pair<edge, int> p = q.top();
            q.pop();

            int u = p.first.to, elev = p.second, sofar = p.first.w;
            if(dist[u][elev] < sofar) continue;
            if(u == k) {
                cout << dist[u][elev] << '\n';
                flag = false;
                break;
            }

            for(pair<edge, int> e : adj[u]){
                int v = e.first.to;
                int nxtelev = e.second;
                int adl = e.first.w + 60 * (elev != nxtelev);
                if(dist[v][nxtelev] > sofar + adl){
                    e.first.w = dist[v][nxtelev] = sofar + adl;
                    q.push(e);
                }
            }
        }
        if(flag)
            cout << "IMPOSSIBLE\n";
    }
}

