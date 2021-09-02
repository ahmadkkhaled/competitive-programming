#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;



int n;
int r[10];
int c[10];
int dp[10][10];

int solve(int s, int e){
    if(s == e){
        return 0;
    }

    int &ret = dp[s][e];
    if(~ret){
        return ret;
    }

    ret = INT_MAX;
    for(int i = s; i<e; i++){
        ret = min(ret, r[s] * c[i] * c[e] + solve(s, i) + solve(i+1, e) );
    }
    return ret;
}

void build(int s, int e){
    if(s == e){
        cout << 'A' << s+1;
        return;
    }
    cout << '(';
    for(int i = s; i<e; i++){
        if(dp[s][e] == r[s] * c[i] * c[e] + solve(s, i) + solve(i+1, e)){
            build(s, i);
            cout << " x ";
            build(i+1 , e);
            break;
        }
    }
    cout << ')';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t = 0;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }

        t++;
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++){
            cin >> r[i] >> c[i];
        }

        solve(0, n - 1);
        cout << "Case " << t << ": ";
        build(0, n - 1);
        cout << '\n';
    }

}
