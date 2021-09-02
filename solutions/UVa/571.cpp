#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e3+1;

struct state{
    int a,b;
};
int dist[N][N];
state p[N][N];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ca,cb,n;
    while(cin >> ca >> cb >> n){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                dist[i][j] = 1e9;
        }


        state s; s.a = 0; s.b = 0;
        dist[0][0] = 0;
        queue<state> q;
        q.push(s);
        while(!q.empty()){
            state cur = q.front();
            q.pop();
            if(cur.b == n){
                s = cur;
                break;
            }

            int next_a[] = {0, cur.a, ca, cur.a, cur.a - min(cb - cur.b, cur.a), cur.a + min(ca - cur.a, cur.b)};
            int next_b[] = {cur.b, 0, cur.b, cb, cur.b + min(cb - cur.b, cur.a), cur.b - min(ca - cur.a, cur.b)};

            for(int i = 0; i < 6; i++){
                state nxt;
                nxt.a = next_a[i];
                nxt.b = next_b[i];
                if(dist[cur.a][cur.b] + 1 < dist[nxt.a][nxt.b]){
                    q.push(nxt);
                    p[nxt.a][nxt.b] = cur;
                    dist[nxt.a][nxt.b] = dist[cur.a][cur.b] + 1;
                }
            }
        }
        vector<string> ans;
        while(s.a || s.b){
            state prev = p[s.a][s.b];
            if(prev.a != s.a && prev.b != s.b){
                if(s.b > prev.b)
                    ans.emplace_back("pour A B");
                else
                    ans.emplace_back("pour B A");
            }
            else if(prev.a != s.a){
                if(s.a > prev.a)
                    ans.emplace_back("fill A");
                else
                    ans.emplace_back("empty A");
            }else{
                if(s.b > prev.b)
                    ans.emplace_back("fill B");
                else
                    ans.emplace_back("empty B");
            }
            s = prev;
        }
        for(int i = (int)ans.size() - 1; i >=0; i--){
            cout << ans[i] << '\n';
        }
        cout << "success\n";
    }
}

