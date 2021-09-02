#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };



int main()
{
    there_are_fates_worse_than_death();
    while(true){
        int n;
        cin >> n;
        if(!n)
            break;
        vector<int> vec;
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            int temp;
            cin >> temp;
            sum+=temp;
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        if(ans > 0)
            cout << "The maximum winning streak is " << ans << ".";
        else
            cout << "Losing streak.";
        cout << endl;
    }
}
