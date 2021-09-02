#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e6+1;

set<int> final;
set<int> curr;
vector<int> adj[107];
int n,m;

void solve(int node){
    if(node > n){
        if(curr.size() > final.size()) final = curr;
        return;
    }
    if(n-node + curr.size() + 1 <= final.size()) return;

    bool canblack = true;

    for(auto nei : adj[node]){
        if(curr.count(nei)) {
            canblack = false;
            break;
        }
    }

    if(canblack){
        curr.insert(node);
        solve(node+1);

        curr.erase(node);
    }

    solve(node+1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(1);

        cout << final.size() << '\n';
        string white = "";
        for(int node : final) cout << white << node, white = " ";
        cout << '\n';

        final.clear();
        curr.clear();
        for(int i=0; i<107; i++) adj[i].clear();
    }
}

