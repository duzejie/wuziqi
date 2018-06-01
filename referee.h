#include <iostream>
#include "Checkerboard.h"
#include <cstdlib>
#include "anna.h"
using namespace std;
class Referee     //����������
{
private:

protected:

public:
    Checkerboard checkerboard ;
    Anna anna;
    int whoFirst;//1:���ȣ�2�����ȡ�
    bool judge(int x,int y,int who);
    void newgame();
    void start();
    /**/
};
bool Referee::judge(int x,int y,int who) //�ж���Ӯ
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
    system ("title a�������壡");
    whoFirst=1;
    cout<<"��������𣿻ش� y or n��"<<endl;
    char s;
    scanf("%c",&s);

    if(s=='y')whoFirst=2;
    /**/
    printf("��ʼ�¾�\n");
    //     Checkerboard checkerboard ;
    checkerboard.newCheckerboard();
    //   checkerboard.point[7][7].shap="��";
    checkerboard.draw();
    start();

}
void Referee::start()
{
    if(whoFirst==2)
    {
        checkerboard.point[7][7].color=2;

        checkerboard.point[7][7].shap="��  ";
        system ("cls");
        checkerboard.draw();
    }

    cout<<endl;
    cout<<"��������Ҫ�µ����� ��\\�� �ÿո����:";
    int x,y;
    while(cin>>x>>y)
    {
        if(checkerboard.point[x][y].color==0 && x>=0 && x<=14 && y>=0 && y<=14)
        {

            //	cout<<"duzejei\n";
            checkerboard.point[x][y].color=1;

            if(whoFirst==1)
            {
                checkerboard.point[x][y].shap="��  ";

            }
            else if(whoFirst==2)
            {
                checkerboard.point[x][y].shap="��  ";
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
                    cout<<"������������"<<x<<"��"<<" "<<y<<"��"<<endl;
                    cout<<"���Ե���������"<<pointx.x<<"��"<<" "<<pointx.y<<"��"<<endl;
                    cout<<"��������Ҫ�µ�����";
                }
                else
                {
                    system ("cls");
                    checkerboard.draw();
                    cout<<endl;
                    cout<<"���Ե���������"<<pointx.x<<"��"<<" "<<pointx.y<<"��"<<endl;
                    cout<<"���Ի�ʤ!"<<endl;
                    break;
                }



            }
            else
            {
                system ("cls");                 //����
                checkerboard.draw();

                cout<<endl;
                cout<<"����ʤ��!"<<endl;
                break;
            }
        }
        else
        {
            cout<<"�����������������:"<<endl;
        }
    }
}
