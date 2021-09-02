#include <bits/stdc++.h>
#include <queue>

//first time using queue *


/*
┌──┬┐       ┌┐┌┐┌┬─┬┬──┐
│┌┐│└┬──┬─┐┌┘│└┐┌┴┐│├──│
│├┤││││││┼└┤┼│┌┘└┬┴┐│──┤
└┘└┴┴┴┴┴┴──┴─┘└┘└┴──┴──┘
*/


using namespace std;



int sod(int x ){
  return x ==0? 0 : x%10 +sod(x/10);
}

int solution(int A, int B, int M) { // the amount of numbers divisible by M in a range from A to B
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    return (B / M) - (A / M);


}


int main()
{
    int n;
    cin >> n;
    while(n!=0)
    {
        if(n==1)
        {
            cout << "Discarded cards: " << endl;
            cout << "Remaining card: " << 1 << endl;
        }
        else
        {
        queue <int> Q;
        for (int i=1; i<=n; ++i)
        {
            Q.push(i);
        }
        cout << "Discarded cards: ";
        while(Q.size()>1)
        {
            cout << Q.front();
            Q.pop();
            if(Q.size()==1)
            {
                cout << endl;
                cout << "Remaining card: " << Q.front();
                Q.pop();
                cout << endl;
                break;
            }
            cout << ", ";
            int i=Q.front();
            Q.pop();
            Q.push(i);
        }
        }
        cin >> n;
    }
}

