#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

int *a;

void merge(int *left, int leftsize, int *right, int rightsize, int* parent){
    int i=0, j=0, k=0;

    while (i < leftsize && j < rightsize){
        if(left[i] < right[j])
            parent[k++] = left[i++];
        else
            parent[k++] = right[j++];
    }

    while(i < leftsize)
        parent[k++] = left[i++];
    while(j < rightsize)
        parent[k++] = right[j++];
}
ll count(int *parent, int n){
    if(n < 2){
        return 0;
    }
    int mid = n/2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for(int i=0; i<mid; i++)
        left[i] = parent[i];

    for(int i = mid; i < n; i++)
        right[i - mid] = parent[i];

    ll inv = count(left, mid) + count(right, n - mid);
    merge(left, mid, right, n - mid, parent);

    int i = 0, j = 0;

    while(i < mid && j < n - mid){
        if(left[i] > right[j]){
            inv += mid - i;
            j++;
        }
        else{
            i++;
        }
    }

    delete[] left;
    delete[] right;

    return inv;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int n;
    while(true){
        cin >> n;
        if(!n) break;

        a = new int[n];
        for(int i=0; i<n; i++)
            cin >> a[i];

        cout << count(a, n) << '\n';


        delete[] a;
    }
}

