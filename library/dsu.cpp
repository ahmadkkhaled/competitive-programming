// find() with path compression is O(log(n))

int sz[N] , p[N];
void init(){
    iota(p , p + N , 0); // 0 1 2 3 .. N
    fill(sz , sz + N , 1);
}
int f(int u){ return p[u] = (p[u] == u ? u : f(p[u])); }
bool merge(int u , int v){
    u = f(u);
    v = f(v);

    if(u == v)return false;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
    return true;
}


// dynamically allocated DSU
class disjoint_set{
private:
    int *sz;
    int *p;
public:
    disjoint_set(int size){
        sz = new int[size];
        p =  new int[size];
        iota(p , p + size , 0);
        fill(sz , sz + size , 1);
    }
    int find(int u){ return p[u] = (p[u] == u ? u : find(p[u])); }
    bool merge(int u , int v){
        u = find(u);
        v = find(v);

        if(u == v)return false;

        if(sz[v] < sz[u])swap(u , v);

        p[u] = v;
        sz[v] += sz[u];
        return true;
    }
    ~disjoint_set(){
        delete[] sz;
        delete[] p;
    }
};