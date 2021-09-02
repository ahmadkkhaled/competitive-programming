/**
 * 2D - Kadane
 * Complexity O(n^3)
 * 1D array used as 2D: a[i*width + j]
 */
int table[MAXN][MAXN];
int arr[MAXN];
int runkadane(int r){
    for(int i=0; i<n; ++i) arr[i]+=table[i][r];
    int globalmax = arr[0], prevmax = arr[0];
    for(int i=1; i<n; ++i){
        if(arr[i] + prevmax < arr[i]) prevmax = arr[i];
        else prevmax +=arr[i];
        globalmax = max(globalmax, prevmax);
    }
    return globalmax;
}
for(int i=0; i<ROWS; ++i){
    memset(arr, 0, sizeof(arr));
    for(int j=i; j<COLS; ++j) ans = max(ans, runkadane(j)); /// WIDTH
}