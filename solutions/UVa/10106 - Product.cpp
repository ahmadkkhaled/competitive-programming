
/* The following algorithm calculates two big integers without using BigInt class using the following approach
* 1- Basic digit by digit multiplication
* 2- Carry propagation by @Youssef ElGhareeb https://www.youtube.com/watch?v=KNd6eqRpWqE
*/

#include <bits/stdc++.h>
using namespace std;


void nextPlease(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}




int carry[62500];

int main()
{
    nextPlease();

    string x,y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for (int i=0; i<x.length(); ++i)
    {
        for(int j=0; j<y.length(); ++j)
        {
            int tmp;
            tmp = (x[i]-'0')*(y[j]-'0');
            carry[i+j] += tmp;
        }
    }
    int maxij = x.length() + y.length() - 2;
    int prop = 0;
    string res = "";
    for (int i=0; i<= maxij; ++i )
    {
        carry[i] += prop;
        res += ((carry[i]%10) + '0');
        prop = carry[i]/10;
    }
    if(prop != 0 )
    {
        res += (prop + '0');
    }
    reverse(res.begin(), res.end());
    cout << res;

}
