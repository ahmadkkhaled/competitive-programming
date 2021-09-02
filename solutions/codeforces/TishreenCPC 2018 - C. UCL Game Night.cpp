#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };


int table[105][105];
int arr[150];
int runkadane(int &l, int &r, int &k, int &n){
    for(int i=0; i<n; ++i){
        arr[i]+=table[i][r];
    }
    int sum = arr[0], left = 0;
    int h=0,w = r-l+1;
    for(int i=1; i<n; ++i){
        if(sum <= k){
            h = max(h, i-left);
        }
        while(sum + arr[i] > k && left < i){
            sum-=arr[left];
            left++;
        }
        sum+=arr[i];
    }
    if(sum <= k)
        h = max(h, n-left);
    return h*w;
}
int main()
{
    there_are_fates_worse_than_death();
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> table[i][j];
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<m; ++i){
            memset(arr,0,sizeof(arr));
            for(int j=i; j<m; ++j){
                ans = max(ans, runkadane(i, j,k, n));
            }
        }
        cout << ans << endl;
    }
}
