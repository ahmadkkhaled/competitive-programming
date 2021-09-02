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
    int t,n,m;
    double k,d;
    cin >> t;
    while(t--){
        init();
        cin >> n >> m >> k >> d;
        if(cin.fail())
            break;
        vector<pair<int,int>> doc;
        vector<pair<int,int>> trees[101];
        for(int i=0; i<m; ++i){
            int x,y;
            cin >> x >> y;
            doc.push_back({x,y});
        }
        for(int i=0; i<n; ++i){
            int x,y,b;
            cin >> b;
            for(int z=0; z<b; ++z){
                cin >> x >> y;
                trees[i].push_back({x,y});
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                double mindis = numeric_limits<double>::max(); ///ASK sisy
                for (int s=0; s<trees[i].size(); ++s){
                    for (int a=0; a<trees[j].size(); ++a){
                        double disx = trees[i][s].first - trees[j][a].first;
                        double disy = trees[i][s].second - trees[j][a].second;
                        disx*=disx;disy*=disy;
                        mindis=min(mindis, sqrt(disx+disy));
                    }
                }
                if(mindis <= k)
                    merge(i,j); /// merge on i (handles sick tree)
            }
        }
        int sickrep = f(0); /// node that represents sick tree component
        bool docfound = false;
        for(int i=0; i<n; ++i){
            if(f(i) == sickrep){
                for(int j=0; j<trees[i].size(); ++j){
                    for(int u=0; u<doc.size(); ++u){
                        double disx = trees[i][j].first - doc[u].first;
                        double disy = trees[i][j].second - doc[u].second;
                        disx*=disx;disy*=disy;
                        if(sqrt(disx+disy) <= d){
                            docfound = true;
                            break;
                        }
                    }
                    if(docfound)
                        break;
                }
                if(docfound)
                    break;
            }
        }
        cout << (docfound ? "Tree can be saved :)" : "Tree can't be saved :(") << endl;
    }
}
