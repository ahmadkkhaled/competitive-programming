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

        bool neg = false;
        if(n < 0){
            n*=-1;
            neg = true;
        }

        vector<int> f;
        for(int i=2; i*1LL*i <= n; i++){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n/=i;
            }

            if(cnt)
                f.push_back(cnt);
        }
        if(n != 1) f.push_back(1);


        int ans = f[0];
        for(int x : f)
            ans = __gcd(ans, x);

        if(neg && (ans%2 == 0)){
            /**
             * if the number is negative,
             * and the largest P (ans) is an even number
             * find a factor X of ans such that X is the largest odd factor of ans
             * this is valid because if ans is the gcd then all other values in the vector will be divisible by all factors of ans.
             * the minimum number to divide by is 2
             */
            while(ans%2 == 0)
                ans/=2;
        }
        cout << ans << '\n';
    }
}

