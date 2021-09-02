#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };

const int N = 1e5 + 1;
int sz[N] , p[N];

void init(){
    iota(p , p + N , 0); // 0 1 2 3 .. N
    fill(sz , sz + N , 1);
}

int f(int u){
    return p[u] = (p[u] == u ? u : f(p[u])); ///path compression
}

void merge(int u , int v){
    u = f(u);
    v = f(v);

    if(u == v)return;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
}
int main(){
    there_are_fates_worse_than_death();
    int t;
    cin >> t;
    while(t--){
        init();
        int n,m;
        cin >> n >> m;
        if(cin.fail())
            break;
        for(int i=0; i<m; ++i){
            int x,y;
            cin >> x >> y;
            merge(x,y);
        }
        sort(sz,sz+n);
        cout << sz[n-1] << endl;
    }
}
