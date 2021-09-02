// Solution didn't receive an Accepted verdict on UVa
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;


void destack(int &x, vector<stack<int>> &v, vector<int> &pos){
    int ro = pos[x];
    while(v[ro].top() != x){
        int tp = v[ro].top();
        v[tp].push(tp);
        pos[tp] = tp;
        v[ro].pop();
    }
}
void place(int &a, int &b, vector<stack<int>> &v, vector<int> &pos){
    vector<int> tower;

    int ro = pos[a];
    while(true){
        int tp = v[ro].top();
        tower.push_back(tp);
        v[ro].pop();

        if(tp == a)
            break;
    }

    ro = pos[b];
    for(int i = (int) tower.size() - 1; i >= 0; i--){
        v[ro].push(tower[i]);
        pos[tower[i]] = ro;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int n;
    cin >> n;

    vector<stack<int>> v(n);
    vector<int> pos(n);
    for(int i = 0; i<n; i++){
        pos[i] = i;
        v[i].push(i);
    }

    while(true){
        string q, type;
        int a,b;

        cin >> q;
        if(q == "quit")
            break;

        cin >> a >> type >> b;
        if(q == "move")
            destack(a, v, pos);

        if(type == "onto")
            destack(b, v, pos);

        place(a,b, v, pos);
    }
    for(int i = 0; i<n; i++){
        cout << i << ": ";

        vector<int> tmp;
        while(!v[i].empty()){
            tmp.push_back(v[i].top());
            v[i].pop();
        }

        for(int x = (int)tmp.size() - 1; x>=0; x--)
            cout << tmp[x] << ' ';
        cout << '\n';
    }
}

