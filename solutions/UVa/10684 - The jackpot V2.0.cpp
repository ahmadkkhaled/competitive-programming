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
        for(int i=0; i<n; ++i){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        int prevmax = -1;
        int globalmax = -1;
        for(int i=0; i<n; ++i){
            if(prevmax + vec[i] < vec[i])
                prevmax = vec[i];
            else
                prevmax +=vec[i];
            globalmax = max(globalmax, prevmax);
        }
        if(globalmax > 0)
            cout << "The maximum winning streak is " << globalmax << ".";
        else
            cout << "Losing streak.";
        cout << endl;
    }
}
