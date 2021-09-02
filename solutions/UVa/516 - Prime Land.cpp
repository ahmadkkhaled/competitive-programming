#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;


long long fastpow(long long base, long long power){
    if(power == 0) return 1;
    if(power%2==0){
        long long ret = fastpow(base, power/2);
        return (ret*ret);
    }
    return (base * fastpow(base, power-1));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    while(true){

        string s;
        getline(cin, s);
        if(s == "0") break;

        vector<int> v;

        string n;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ')
                n.push_back(s[i]);
            if(i == s.size() - 1 || s[i] == ' '){
                v.push_back(stoi(n));
                n.clear();
            }
        }

        ll x = 1;
        for(int i=0; i<v.size() - 1; i+=2){
            x *= fastpow(v[i], v[i+1]);
        }

        x--;

        map<int, int> f; /// can use vector<int> of size sqrt(input)
        for(int i=2; i*1LL*i <= x; i++){
            while(x%i == 0){
                f[i]++;
                x/=i;
            }
        }
        if(x != 1){
            f[x]++;
        }

        for(auto it = f.rbegin(); it != f.rend(); it++){
            if(it != f.rbegin()) cout << ' ';
            cout << it->first << ' ' << it->second;
        }
        cout << '\n';
    }
}
