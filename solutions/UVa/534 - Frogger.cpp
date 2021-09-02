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

bool merge(int u , int v){
    u = f(u);
    v = f(v);

    if(u == v)return false;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
    return true;
}

long double dist(int x1, int y1, int x2, int y2){
    long double disx = x1 - x2*1.0;disx*=disx;
    long double disy = y1 - y2*1.0;disy*=disy;
    return sqrt(disx+disy);
}

int main(){
    there_are_fates_worse_than_death();
    int n;
    cin >> n;
    long long test = 0;
    while(true){
        test++;
        if(n==0)
            break;
        init();
        vector<pair<int,int>> coord;
        for(int i=0; i<n; ++i){
            int x,y;
            cin >> x >> y;
            coord.push_back({x,y});
        }
        vector<pair<pair<int,int> , long double>> edgelist;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                edgelist.push_back( { {i,j} , dist(coord[i].first, coord[i].second, coord[j].first, coord[j].second)} );
            }
        }
        sort(edgelist.begin(), edgelist.end(), []( pair<pair<int,int>,long double> &a, pair<pair<int,int>, long double> &b){return a.second < b.second;} );
        long double mindis = -1;
        for(int i=0; i < edgelist.size(); ++i){
            if(merge(edgelist[i].first.first, edgelist[i].first.second)){
                mindis = max(mindis, edgelist[i].second);
            }
            if(f(0) == f(1)) /// if source and destination are in the same component
                break;
        }
        cout << "Scenario #" << test << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << mindis << endl << endl;
        cin >> n;
    }
}
