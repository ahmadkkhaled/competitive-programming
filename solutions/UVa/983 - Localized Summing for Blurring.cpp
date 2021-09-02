#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };


int n,m;
long long picture[1001][1001];
long long res[1001][1001];

bool valid(int i, int j){
    return i>=0 && i < n && j>=0 && j<n;
}
long long solve(int i, int j){
    long long a,b,c,d;
    a = picture[i+m-1][j+m-1];
    b = (valid(i-1 , j+m-1) ? picture[i-1][j+m-1] : 0 );
    c = (valid(i+m-1 , j-1) ? picture[i+m-1][j-1] : 0 );
    d = (valid(i-1 , j-1) ? picture[i-1][j-1] : 0 );
    return a - b - c + d;
}
int main()
{
    there_are_fates_worse_than_death();
    bool first = true;
    while(true){
        cin >> n >> m;
        if(cin.fail())
            break;
        if(first)
            first = false;
        else
            cout << endl;
        memset(picture, 0, sizeof(picture));
        memset(res, 0, sizeof(picture));
        for(int i=n-1; i>=0; --i){
            for (int j=0; j<n; ++j){
                cin >> picture[i][j];
            }
        }
        for(int i=0; i<n; ++i){
            for (int j=1; j<n; ++j){
                picture[i][j]+=picture[i][j-1];
            }
        }
        for(int j=0; j<n; ++j){
            for(int i=1; i<n; ++i){
                picture[i][j]+=picture[i-1][j];
            }
        }
        int sz = n-m+1;
        long long sum=0;
        for(int i=sz-1; i>=0; --i){
            for (int j=0; j<sz; ++j){
                res[i][j] = solve(i,j);
                sum+=res[i][j];
                cout << res[i][j] << endl;
            }
        }
        cout << sum << endl;
    }
}
