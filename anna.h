#include <iostream>
//#include "Checkerboard.h"
//#include "point.h"
//#include "referee.h"
//using namespace std;
class Anna          //机器人安娜
{
private:

protected:

public:
    int value[20][20];
    //int c,d;
    Point ai(Checkerboard& checkerboard,int whoFirst) ;

};

Point Anna::ai(Checkerboard& checkerboard,int whoFirst)                                   //机器人安娜的大脑 
{
    int x,y,i,m,n,line1=0,line2=0,life=0;
    Point point;
    memset(value,0,sizeof(value));
    for(x=0; x<=14; x++)
        for(y=0; y<=14; y++)
        {
            if(checkerboard.point[x][y].color==0)
            {
                for(m=-1; m<=1; m++)
                    for(n=-1; n<=1; n++)
                    {
                        if(m!=0 || n!=0)
                        {
                            for(i=1; i<=4; i++)
                            {
                                if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==1 )
                                {
                                    line1++;
                                }
                                else if(checkerboard.point[x+i*m][y+i*n].color==0)
                                {
                                    life++;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for(i=-1; i>=-4; i--)
                            {
                                if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==1 )
                                {
                                    line1++;
                                }
                                else if(checkerboard.point[x+i*m][y+i*n].color==0)
                                {
                                    life++;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if(line1==1)
                            {
                                value[x][y]+=1;
                            }
                            else if(line1==2)
                            {
                                if(life==1)
                                {
                                    value[x][y]+=5;
                                }
                                else if(life==2)
                                {
                                    value[x][y]+=10;
                                }
                            }
                            else if(line1==3)
                            {
                                if(life==1)
                                {
                                    value[x][y]+=20;
                                }
                                else if(life==2)
                                {
                                    value[x][y]+=100;
                                }
                            }
                            else if(line1==4)
                            {
                                value[x][y]+=500;
                            }
                            life=0;
                            for(i=1; i<=4; i++)
                            {
                                if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==2 )
                                {
                                    line2++;
                                }
                                else if(checkerboard.point[x+i*m][y+i*n].color==0)
                                {
                                    life++;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for(i=-1; i>=-4; i--)
                            {
                                if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==2 )
                                {
                                    line2++;
                                }
                                else if(checkerboard.point[x+i*m][y+i*n].color==0)
                                {
                                    life++;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if(line2==1)
                            {
                                value[x][y]+=2;
                            }
                            else if(line2==2)
                            {
                                if(life==1)
                                {
                                    value[x][y]+=8;
                                }
                                else if(life==2)
                                {
                                    value[x][y]+=30;
                                }
                            }
                            else if(line2==3)
                            {
                                if(life==1)
                                {
                                    value[x][y]+=50;
                                }
                                else if(life==2)
                                {
                                    value[x][y]+=200;
                                }
                            }
                            else if(line2==4)
                            {
                                value[x][y]+=1000;
                            }
                            line1=0;
                            line2=0;
                            life=0;
                        }
                    }
            }
        }
    int max=0,xx,yy;   //位置
    for(int i=0; i<=14; i++)
        for(int j=0; j<=14; j++)
        {
            if(value[i][j]>max)
            {
                max=value[i][j];
                xx=i;
                yy=j;
            }
        }

    point.x=xx;
    point.y=yy;
    point.color=2;
    checkerboard.point[xx][yy].color=2;
    if(whoFirst==1)
    {
        checkerboard.point[xx][yy].shap="○  ";
    }
    else if(whoFirst==2)
    {
        checkerboard.point[xx][yy].shap="●  ";
    }
    return point;
    /*refereer.refereer.*/
} 
