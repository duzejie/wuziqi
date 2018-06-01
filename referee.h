#include <iostream>
#include "Checkerboard.h"
#include <cstdlib>
#include "anna.h"
using namespace std;
class Referee     //创建裁判类
{
private:

protected:

public:
    Checkerboard checkerboard ;
    Anna anna;
    int whoFirst;//1:人先，2电脑先。
    bool judge(int x,int y,int who);
    void newgame();
    void start();
    /**/
};
bool Referee::judge(int x,int y,int who) //判断输赢
{

    int m,n,i,line=0;
    for(m=-1; m<=1; m++)
        for(n=-1; n<=1; n++)
        {
            if(m!=0 || n!=0)
            {
                for(i=1; i<=4; i++)
                {
                    if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==who )
                    {
                        line++;
                    }
                    else
                    {
                        break;
                    }
                }
                for(i=0; i>=-4; i--)
                {
                    if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && checkerboard.point[x+i*m][y+i*n].color==who )
                    {
                        line++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(line>=5)

                {
                    return true;
                }
                else
                {
                    line=0;
                }
            }
        }
    return false;
}/**/
void Referee::newgame()
{
    system ("color f8");
    system ("title a杜五子棋！");
    whoFirst=1;
    cout<<"你敢让先吗？回答 y or n。"<<endl;
    char s;
    scanf("%c",&s);

    if(s=='y')whoFirst=2;
    /**/
    printf("开始新局\n");
    //     Checkerboard checkerboard ;
    checkerboard.newCheckerboard();
    //   checkerboard.point[7][7].shap="○";
    checkerboard.draw();
    start();

}
void Referee::start()
{
    if(whoFirst==2)
    {
        checkerboard.point[7][7].color=2;

        checkerboard.point[7][7].shap="●  ";
        system ("cls");
        checkerboard.draw();
    }

    cout<<endl;
    cout<<"请输入您要下的棋子 行\\列 用空格隔开:";
    int x,y;
    while(cin>>x>>y)
    {
        if(checkerboard.point[x][y].color==0 && x>=0 && x<=14 && y>=0 && y<=14)
        {

            //	cout<<"duzejei\n";
            checkerboard.point[x][y].color=1;

            if(whoFirst==1)
            {
                checkerboard.point[x][y].shap="●  ";

            }
            else if(whoFirst==2)
            {
                checkerboard.point[x][y].shap="○  ";
            }

            //         system ("cls");
            //         checkerboard.draw();
            if(!judge(x,y,1))
            {
                system ("cls");
                checkerboard.draw();
                Point pointx;
                pointx=anna.ai(checkerboard,whoFirst);
                if(!judge(pointx.x,pointx.y,2))
                {
                    system ("cls");
                    checkerboard.draw();
                    cout<<endl;
                    cout<<"您的棋子落在"<<x<<"行"<<" "<<y<<"列"<<endl;
                    cout<<"电脑的棋子落在"<<pointx.x<<"行"<<" "<<pointx.y<<"列"<<endl;
                    cout<<"请输入您要下的棋子";
                }
                else
                {
                    system ("cls");
                    checkerboard.draw();
                    cout<<endl;
                    cout<<"电脑的棋子落在"<<pointx.x<<"行"<<" "<<pointx.y<<"列"<<endl;
                    cout<<"电脑获胜!"<<endl;
                    break;
                }



            }
            else
            {
                system ("cls");                 //清屏
                checkerboard.draw();

                cout<<endl;
                cout<<"您获胜啦!"<<endl;
                break;
            }
        }
        else
        {
            cout<<"输入错误，请重新输入:"<<endl;
        }
    }
}
