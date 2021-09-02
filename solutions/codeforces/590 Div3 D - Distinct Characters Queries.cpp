#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int S = 1e5+1;

string str;
int segtree[4*S];

void build(int l = 0, int r = (int)str.size()-1, int idx = 0){
    if(l==r){
        int shift = str[l]-'a';
        segtree[idx]|=(1<<shift);
        return;
    }
    int mid = l + (r-l)/2;
    build(l, mid, 2*idx+1);
    build(mid+1, r, 2*idx+2);
    segtree[idx] = segtree[2*idx+1] | segtree[2*idx+2];
}
int query(int &s, int &e, int l = 0, int r = (int)str.size()-1, int idx = 0){
    if(r < s || l > e) return 0;
    if(l>=s && r <= e) return segtree[idx];
    int mid = l+(r-l)/2;
    return query(s,e,l,mid,2*idx+1) | query(s, e, mid+1, r, 2*idx+2);
}
void update(int &pos, char &c, int l = 0, int r = (int)str.size()-1, int idx = 0){
    if(l > pos || r < pos) return;
    if(l == r){
        segtree[idx] = 0;
        segtree[idx] |= ( 1 << (c -'a') );
        return;
    }
    int mid = l+(r-l)/2;
    update(pos, c, l, mid, 2*idx+1);
    update(pos, c, mid+1, r, 2*idx+2);
    segtree[idx] = segtree[2*idx+1] | segtree[2*idx+2];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> str;
    int q;
    cin >> q;
    build();
    while(q--){
        int t;
        cin >> t;
        if(t==2){
            int l,r;
            cin >> l >> r;
            l--,r--;
            cout << __builtin_popcount(query(l,r)) << '\n';
        }
        else{
            int idx;
            cin >> idx;
            idx--;
            char ch;
            cin >> ch;
            update(idx, ch);
        }
    }
}