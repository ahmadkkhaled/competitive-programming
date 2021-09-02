int arr[N], seg[4*N];
int n;
void build(int l = 0, int r = n-1, int idx = 0){ /// L,R are the range specifiers
    if(l==r){
        segtree[idx] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(l, mid, 2*idx+1);
    build(mid+1, r, 2*idx+2);
    seg[idx] = /// OPERATION seg[ 2*idx + 1 ] seg[ 2*idx + 2 ]
}
query(int& s, int& e, int l = 0, int r = n-1, int idx = 0){
    if(r < s || l > e) return;
    if(l>=s && r <= e) return seg[idx];
    int mid = l+(r-l)/2;
    return  /// OPERATION query(s, e, l, mid, 2*idx+1) query(s, e, mid+1, r, 2*idx+2);
}
int main(){
    read();
    build();
}