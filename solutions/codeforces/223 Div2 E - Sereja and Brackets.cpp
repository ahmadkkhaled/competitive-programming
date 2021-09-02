#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int S = 1e6+1;

string str;
int n;
struct value{int len,o,c;};
value seg[4*S];

void build(int l = 0, int r = n-1, int idx = 0){
    if(l==r){
        seg[idx].len = 0;
        if(str[l] == '('){
            seg[idx].o = 1;
            seg[idx].c = 0;
        }
        else{
            seg[idx].c = 1;
            seg[idx].o = 0;
        }
        return;
    }
    int mid = l + (r-l)/2;
    build(l, mid,  2*idx+1);
    build(mid+1, r, 2*idx+2);
    int valid = min(seg[2*idx+1].o, seg[2*idx+2].c);
    seg[idx].len = seg[2*idx+1].len + seg[2*idx+2].len + 2*valid;
    seg[idx].o = seg[2*idx+1].o + seg[2*idx+2].o - valid;
    seg[idx].c = seg[2*idx+1].c + seg[2*idx+2].c - valid;
}
value query(int &s, int &e, int l = 0, int r = n-1, int idx = 0){
    if(r < s || l > e) return {0,0,0};
    if(r<=e && l >= s) return seg[idx];
    int mid = l + (r-l)/2;
    value left = query(s,e, l, mid, 2*idx+1), right = query(s,e,mid+1, r, 2*idx+2), ret = {0,0,0};
    int valid = min(left.o, right.c);
    ret.len = left.len + right.len + 2*valid;
    ret.o = left.o + right.o - valid;
    ret.c = left.c + right.c - valid;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> str;
    n = str.size();
    build();
    int m;
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        cout << query(l,r).len << '\n';
    }
}