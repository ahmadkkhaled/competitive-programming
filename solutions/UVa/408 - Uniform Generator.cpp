#include <bits/stdc++.h>
using namespace std;



void nextPlease(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}



int main()
{
    nextPlease();
    int step,mod;
    while(cin >> step >> mod)
    {
        bool gen[100002] = {0};
        bool bad = false;
        int prevSeed = 0;
        /* The required loop iterates from 0 to mod-1 for the following reasons
         * 1- the result should be a list of numbers from 0 to mod-1 with no chance of redundancy of any number (or there will be an endless loop)
         * 2- iterating from 0 requires the maximum value of i to be mod-1 because -> prevSeed == prevSeed%mod e.g. 15 == 15%15 == 0
         */
        for (int i=0; i<mod; ++i) 
        {
            int seed  = ( prevSeed + step)%mod;
            if(gen[seed])
            {
                bad = true;
                break;
            }
            gen[seed] = true;
            prevSeed = seed;
        }
        if (bad)
        {
            cout << setw(10) << step;
            cout << setw(10) << mod;
            cout << "    " << "Bad Choice\n\n";
        }
        else
        {
            cout << setw(10) << step;
            cout << setw(10) << mod;
            cout << "    " << "Good Choice\n\n";
        }

    }


}
