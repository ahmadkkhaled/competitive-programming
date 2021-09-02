/// https://lifepowerten.wordpress.com/2013/06/16/uva-10168-summation-of-four-primes/
/// https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
/// Any even number n > 4 can be expressed as the sum of two primes

#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int S = 1e7+1;
bool prime[S];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   

    fill(prime, prime+S, true);
    for(int i = 2; i*i<S; ++i){
        if(prime[i])
            for(int j = 2; i*j<S; ++j) prime[i*j] = false;
    }
    while(true){
        int n;
        cin >> n;
        if(cin.fail()) break;
        if(n<8){
            cout << "Impossible." << '\n';
            continue;
        }
        if (n&1) cout << "2 3 ";
        else cout << "2 2 ";
        n -= (4 + (n&1));
        for(int i=2; i<S; ++i){
            if(prime[i] && prime[n-i]){
                cout << i << " " << n-i << '\n';
                break;
            }
        }
    }
}

