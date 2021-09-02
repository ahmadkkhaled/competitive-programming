#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    while(true){
        ll n;
        cin >> n;
        if(!n) break;

        bool bef = false;
        cout << n << " = ";
        if(n < 0){
            bef = true;
            n*=-1;
            cout << -1;
        }

        for(int i=2; i*1LL*i <= n; i++){ /// cast i*i to long long because input can reach 2^31 (> INT_MAX)
            while(n%i == 0){
                if(bef) cout << " x ";
                cout << i;
                n/=i;
                bef = true;
            }
        }
        if(n != 1){
            if(bef) cout << " x ";
            cout << n;
        }
        cout << '\n';
    }
}

