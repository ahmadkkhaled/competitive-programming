#include <bits/stdc++.h>



using namespace std;



void nextPlease(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}


int di[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, -1, 1, 1, -1, -1, 1};
char grid[25][25];
bool vis [25][25];
int eagles = 0;
int n;

bool exist (int i, int j)
{
    if( (i>=n) || (i<0) || (j>=n) || (j<0) || (grid[i][j] == '0') )
    {
        return false;
    }
    return true;
}

void checkpath(int x, int y)
{
    for (int i=0; i<8; ++i)
    {
        int modx = x + di[i];
        int mody = y + dj[i];
        if (exist(modx,mody) && (!vis[modx][mody]))
        {
            vis[modx][mody] = true;
            checkpath(modx, mody);
        }
    }
}

void settozero()
{
    for(int i=0; i<25; ++i)
    {
        for (int j=0; j<25; ++j)
        {
            grid[i][j] = '0';
            vis[i][j] = false;
        }
    }
}
int main()
{
    int ctr = 0;
    cin >> n;
    while(!cin.eof())
    {
        ctr++;
        eagles = 0;
        settozero();
        for (int i=0; i<n; ++i)
        {
            cin >> grid[i];
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if ( exist(i,j) && (!vis[i][j]) )
                {
                    eagles++;
                    checkpath(i,j);
                }
            }
        }
        cout << "Image number " << ctr << " contains " << eagles << " war eagles.\n";
        cin >> n;
    }
}
