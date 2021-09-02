#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };

const int N = 100 + 3;
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

long double dist(long double x1, long double y1, long double x2, long double y2){
    long double disx = x1 - x2;disx*=disx;
    long double disy = y1 - y2;disy*=disy;
    return sqrt(disx+disy);
}

int main(){
    there_are_fates_worse_than_death();
    int t;
    cin >> t;
    bool first = true;
    while(t--){
        if(first)
            first = false;
        else
            cout << endl;
        init();
        int points;
        cin >> points;
        vector<pair<long double,long double>> coord;
        for(int i=0; i<points; ++i){
            long double x,y;
            cin >> x >> y;
            coord.push_back({x,y});
        }
        vector<pair<pair<int , int> , long double> > edgeList;
        long double sum = 0;
        for(int i = 0 ; i < points ; ++i){
            for(int j = i + 1 ; j < points ; ++j){
                edgeList.push_back({{i , j} , dist(coord[i].first , coord[i].second , coord[j].first , coord[j].second)});
            }
        }

        sort(edgeList.begin() , edgeList.end() , [](pair<pair<int , int> , long double> a , pair<pair<int , int> , long double> b){
            return a.second < b.second;
        });
        for(int i = 0 ; i< (int)edgeList.size() ; ++i){
            int u = edgeList[i].first.first , v = edgeList[i].first.second;
            long double cost = edgeList[i].second;
            if(merge(u , v)){
                sum += cost;
            }
        }
        cout << fixed <<setprecision(2) << sum << endl;
    }
}
