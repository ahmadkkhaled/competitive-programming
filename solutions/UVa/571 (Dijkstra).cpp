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
bool vis[N][N];
state p[N][N];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ca,cb,n;
    while(cin >> ca >> cb >> n){
        for(int i = 0; i <= ca; i++){
            for(int j = 0; j <= cb; j++){
                dist[i][j] = 1e9;
                vis[i][j] = false;
            }
        }

        state s{};
        dist[0][0] = 0;
        while(true){
            state cur{}; cur.a = -1;
            int val = 1e9;
            for(int a = 0; a <= ca; a++){
                for(int b = 0; b <= cb; b++){
                    if(!vis[a][b] && dist[a][b] < val){
                        cur.a = a;
                        cur.b = b;
                        break;
                    }
                }
            }
            if(cur.a == n || cur.b == n){
                s = cur;
                break;
            }
            vis[cur.a][cur.b] = true;

            int next_a[] = {0, cur.a, ca, cur.a, cur.a - min(cb - cur.b, cur.a), cur.a + min(ca - cur.a, cur.b)};
            int next_b[] = {cur.b, 0, cur.b, cb, cur.b + min(cb - cur.b, cur.a), cur.b - min(ca - cur.a, cur.b)};
            for(int i = 0; i < 6; i++){
                state nxt;
                nxt.a = next_a[i];
                nxt.b = next_b[i];
                if(dist[cur.a][cur.b] + 1 < dist[nxt.a][nxt.b]){
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

