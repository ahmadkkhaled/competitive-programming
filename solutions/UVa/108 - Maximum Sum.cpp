#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };


int table[200][200];
int n;
int arr[150];
int runkadane(int r){
    for(int i=0; i<n; ++i){
        arr[i]+=table[i][r];
    }
    int globalmax = arr[0];
    int prevmax = arr[0];
    for(int i=1; i<n; ++i){
        if(arr[i] + prevmax < arr[i])
            prevmax = arr[i];
        else
            prevmax +=arr[i];
        globalmax = max(globalmax, prevmax);
    }
    return globalmax;
}
int main()
{
    there_are_fates_worse_than_death();
    while(true){
        cin >> n;
        if(cin.fail())
            break;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> table[i][j];
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            memset(arr,0,sizeof(arr));
            for(int j=i; j<n; ++j){
               ans = max(ans, runkadane(j));
            }
        }
        cout << ans << endl;
    }
}
