#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

int n,b;
bool ok(int mid, int &mnq, vector< vector< pair<int,int> > > &v){
    ll mon = b;
    for(int i = 0; i<n; i++){
        bool found = false;
        for(auto &pr : v[i]){
            if(pr.second >= mid && mon >= pr.first){
                mnq = min(mnq, pr.second);
                mon-=pr.first;
                found = true;
                break;
            }
        }
        if(!found)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> b;
        vector< vector< pair<int,int> > > v(n);
        map<string, int> idxof;
        int idx = 0;
        for(int i = 0; i<n; i++){
            string model, grb;
            int p,q;
            cin >> model >> grb >> p >> q;

            if(idxof.find(model) != idxof.end()){
                v[idxof[model]].push_back({p,q});
            }else{
                v[idx].push_back({p,q});
                idxof[model] = idx++;
            }
        }

        n = idx;
        for(int i = 0; i<n; i++){
            sort(v[i].begin(), v[i].end());
        }


        /**
         * set some mid M
         * for each component C of type I get the CHEAPEST instance of I that has a quality Q >= M
         * if for all C we are able to get an instance within the budget, increase M
         * otherwise decrease M.
         */
        int l = 0, r = 1e9+1;
        ll mid;
        int ans = -1;
        while(l<=r){
            mid = (1ll * l + r) / 2;
            int mnq = INT_MAX;

            if(ok(mid, mnq, v)){
                ans = mnq;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout << ans << '\n';
    }
}

