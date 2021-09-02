#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e3 + 1;
const int M = 18279;

int n,m;
string a[N][M];
int out[N][M];
bool vis[N][M];

long long fastpow(long long base, long long power){
    assert(power >= 0);
    if(power == 0) return 1;
    if(power%2==0){
        long long ret = fastpow(base, power/2);
        return (ret*ret);
    }
    return (base * fastpow(base, power-1));
}

bool isnum(string &s){
    for(int i = 0; i<s.size(); i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
int solve(int &r, int &c){
    vis[r][c] = true;

    bool negative = false;
    if(a[r][c][0] == '-'){
        negative = true;
        a[r][c] = a[r][c].substr(1);
    }

    if(isnum(a[r][c])){
        int ret = stoi(a[r][c]);
        if(negative) ret = -ret;
        return out[r][c] = ret;
    }

    vector<string> cells;
    string cell;
    for(int i = 1; i<a[r][c].size(); i++){
        if(a[r][c][i] == '+'){
            cells.push_back(cell);
            cell.clear();
        }else{
            cell.push_back(a[r][c][i]);
        }
    }
    cells.push_back(cell);

    vector<pair<int,int>> pos;
    for(string &s : cells){

        string js,is;
        for(int i = 0; i<s.size(); i++){
            if(isdigit(s[i]))
                break;
            js.push_back(s[i]);
        }

        for(int i = 0; i<s.size(); i++){
            if(isdigit(s[i]))
                is.push_back(s[i]);
        }

        int j = 0;
        for(int i = 0; i<js.size(); i++){
            j += fastpow(26, js.size() - i - 1) * (js[i] - 'A' + 1);
        }


        int i = stoi(is) - 1;
        j = j - 1;
        pos.push_back({i,j});
    }

    int sum = 0;
    for(auto &p : pos){
        int i = p.first;
        int j = p.second;
        if(!vis[i][j]){
            sum += solve(i,j);
        }else{
            sum += out[i][j];
        }
    }
    return out[r][c] = sum;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        cin >> m >> n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)
                cin >> a[i][j];
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]){
                    solve(i,j);
                }
            }
        }

        for(int i = 0; i<n; i++){
            string white;
            for(int j = 0; j<m; j++){
                cout << white << out[i][j];
                white = " ";
            }
            cout << endl;
        }
    }
}

