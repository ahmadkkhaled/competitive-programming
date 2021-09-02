#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };

const int N = 2e5 + 3;
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


int main(){
    there_are_fates_worse_than_death();
    int c,s,q;
    bool first = true;
    int test = 0;
    while(true){
        cin >> c >> s >> q;
        test++;
        if(!c && !s && !q)
            break;
        if(first)
            first = false;
        else
            cout << endl;
        vector<pair<pair<int,int> , int >> edgelist;
        for(int i=0; i<s; ++i){
            int x,y,z;
            cin >> x >> y >> z;
            edgelist.push_back({{x,y},z});
        }
        sort(edgelist.begin(), edgelist.end(), []( pair<pair<int,int>,int> &a, pair<pair<int,int>, int > &b){return a.second < b.second;} );
        cout << "Case #" << test << endl;
        for(int i=0; i<q; ++i){
            init();
            int c1,c2;
            cin >> c1 >> c2;
            int maxsound = INT_MIN;
            bool connected = false;
            for(int j=0; j<edgelist.size(); ++j){
                int u = edgelist[j].first.first;
                int v = edgelist[j].first.second;
                int sound = edgelist[j].second;
                if(merge(u,v))
                    maxsound = max(maxsound, sound);
                if(f(c1) == f(c2)){
                    connected = true;
                    break;
                }
            }
            if(connected)
                cout << maxsound << endl;
            else
                cout << "no path" << endl;
        }
    }
}
