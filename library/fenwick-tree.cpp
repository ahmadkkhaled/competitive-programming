template<typename T>
struct fenwick{
    vector<T> tree;
    int n;

    fenwick(){}

    /// call this function with (n + 1)
    fenwick(int n){
        this->n = n;
        tree = vector<T>(n, 0);
    }

    T sum(int i){
        T ret = 0;

        while(i > 0){
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    void update(int i, T delta){ /// delta = new - old
        while(i < n){
            tree[i] += delta;
            i += (i & -i);
        }
    }

    T range(int l, int r){
        return sum(r) - sum(l - 1);
    }
};