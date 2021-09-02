#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };


vector<int> gar[21];
int mem[300][21];
int m,c;

int maxgar(int money, int g){
    if(money < 0)
        return money;
    if(g == c)
        return m - money; 
    if(mem[money][g] != -1)
        return mem[money][g];
    int res = -1;
    for(int i=0; i<gar[g].size(); ++i){
        res = max(res, maxgar(money - gar[g][i], g+1));
    }
    return mem[money][g] = res;
}
int main()
{
    there_are_fates_worse_than_death();
    int n;
    cin >> n;
    while(n--){
        cin >> m >> c;
        if(cin.fail())
            break;
        memset(mem, -1, sizeof(mem));
        for(int i=0; i<c; ++i){
            int k;
            cin >> k;
            if(!gar[i].empty())
                gar[i].clear();
            for(int j=0; j<k; ++j){
                int temp;
                cin >> temp;
                gar[i].push_back(temp);
            }
        }
        int ans = maxgar(m,0);
        if(ans < 0)
            cout << "no solution";
        else
            cout << ans;
        cout << endl;
    }
}
