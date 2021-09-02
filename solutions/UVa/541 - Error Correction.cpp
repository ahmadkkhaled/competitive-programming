#include <bits/stdc++.h>
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=482

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

bool arr[100][100];
int main()
{
    int n;
    cin >> n;
    while(n!=0)
    {
        int corruptrow=0;
        int corruptcol=0;
        bool totallycorrupt=false;
        int idxrow;
        int idxcol;
        int no1s=0;
        for(int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                cin >> arr[i][j];
            }
        }
        for(int i=0; i<n; ++i) //check corrupt rows
        {
            no1s=0;
            for(int j=0; j<n; ++j)
            {
                if(arr[i][j]==1)
                {
                    no1s++;
                }
            }

            if(corruptrow<2)
            {
                if(no1s%2 != 0)
                {
                    corruptrow++;
                    idxrow=i;
                }
            }
            else
            {
                cout << "Corrupt" << endl;
                totallycorrupt=true;
                break;
            }

        }
        if(!totallycorrupt)
        {
            for(int i=0; i<n; ++i)
            {
                no1s=0;
                for(int j=0; j<n; ++j)
                {
                    if(arr[j][i]==1)
                    {
                        no1s++;
                    }
                }
                if(corruptcol<2)
                {
                    if(no1s%2 != 0)
                    {
                        corruptcol=true;
                        idxcol=i; //CHECK
                    }
                }
                else
                {
                    cout << "Corrupt" << endl;
                    totallycorrupt=true;
                    break;
                }
            }
        }
        if(!totallycorrupt)
        {
            if(corruptcol==0 && corruptrow==0)
            {
                cout << "OK" << endl;
            }
            else if ( (corruptcol==0 && corruptrow>0) || (corruptcol>0 && corruptrow==0))
            {
                cout << "Corrupt" << endl;
            }
            else
            {
                cout << "Change bit (" << idxrow+1 << "," << idxcol+1 <<")" << endl;
            }
        }
        cin >> n;
    }
}

