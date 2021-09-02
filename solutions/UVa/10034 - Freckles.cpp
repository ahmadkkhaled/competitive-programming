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
bool incomp[1000];

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
        memset(incomp, false, sizeof(incomp));
        int points;
        cin >> points;
        if(points == 0 || points == 1){
            long double ans = 0;
            cout << fixed << setprecision(2) << ans << endl;
            cout << 0;
            continue;
        }
        vector<pair<long double,long double>> coord;
        for(int i=0; i<points; ++i){
            long double x,y;
            cin >> x >> y;
            pair<long double,long double> temp = make_pair(x,y);
            coord.push_back(temp);
        }
        long double sum = 0;
        vector<pair<long double,long double>> curr;
        curr.push_back(coord[0]);
        incomp[0] = true;
        int totalsize = 1;
        while(totalsize < points){
            long double mindis = numeric_limits<long double>::max();
            int next = -1;
            for(int i=0; i<curr.size(); ++i){
                for(int j=0; j<coord.size(); ++j){
                    if(curr[i] == coord[j] || incomp[j])
                        continue;
                    double disx = coord[j].first - curr[i].first; disx*=disx;
                    double disy = coord[j].second - curr[i].second; disy*=disy;
                    if(mindis > sqrt(disx+disy)){
                        mindis = sqrt(disx+disy);
                        next = j;
                    }
                }
            }
            sum+=mindis;
            incomp[next] = true;
            totalsize++;
            curr.push_back(coord[next]);
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
}
