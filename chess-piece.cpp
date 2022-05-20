#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
typedef struct
{
    int x;
    int y;
    int level;
}data;
int mv[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n,m,r1,c1,r2,c2;
        cin>>n>>m;
        int a[n+1][m+1];
        memset(a,0,sizeof(int)*(n+1)*(m+1));
        cin>>r1>>c1>>r2>>c2;
        data d,d1,d2;
        queue<data> qt;
        d.x = r1;
        d.y = c1;
        d.level = 0;
        qt.push(d);
        a[d.x][d.y] = 2;
        int tmx,tmy,tml;
        int steps = 0;
        bool f = false;
        while(!qt.empty())
        {
            if(f)
            {
                break;
            }
            d1 = qt.front();
            qt.pop();
            for(int k=0; k<8; k++)
            {
                tmx = d1.x + mv[k][0];
                tmy = d1.y + mv[k][1];
                tml = d1.level + 1;

                if(tmx>=1 && tmx<=n && tmy>=1 && tmy<=m && a[tmx][tmy] == 0)
                {
                    if(tmx == r2 && tmy == c2)
                    {
                        steps = tml;
                        f = true;
                        break;
                    }
                    d2.x = tmx;
                    d2.y = tmy;
                    d2.level = tml;
                    qt.push(d2);
                    a[d2.x][d2.y] = 2;
                }
            }
        }
        if(!f)
        {
            steps = -1;
        }
        cout<<"Case #"<<t<<endl;
        cout<<steps<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
