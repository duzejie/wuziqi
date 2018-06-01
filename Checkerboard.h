#include <iostream>
#include "point.h"
//using namespace std;
class Checkerboard   //棋盘类
{

private:

    int sizeOfBoard;
protected:

public:
    Point point[20][20];

    Checkerboard()
    {
        sizeOfBoard=15;
       

    }
    Checkerboard(int n)
    {
        sizeOfBoard=n;
        
    }



    void newCheckerboard()
    {
        for(int i=0; i<sizeOfBoard ; i++)
        {
            for(int j=0; j<sizeOfBoard ; j++ )
            {
                point[i][j].x=i;
                point[i][j].y=j;
                point[i][j].color=0;
            }
        }
        /////////初始化棋盘形状
        point[0][0].shap="┌  ";
        point[0][sizeOfBoard-1].shap="┐";
        point[sizeOfBoard-1][0].shap="└  ";
        point[sizeOfBoard-1][sizeOfBoard-1].shap="┘";
        for(int i=1; i<sizeOfBoard-1 ; i++)
            for(int j=1; j<sizeOfBoard-1 ; j++ )
                point[i][j].shap="┼  ";
        for(int i=1; i<sizeOfBoard-1 ; i++) point[i][0].shap="├  ";
        for(int i=1; i<sizeOfBoard-1 ; i++) point[i][sizeOfBoard-1].shap="┤";
        for(int i=1; i<sizeOfBoard-1 ; i++) point[0][i].shap="┬  ";
        for(int i=1; i<sizeOfBoard-1 ; i++) point[sizeOfBoard-1][i].shap="┴  ";
    }
    void draw();

};


void Checkerboard::draw()
{
    cout<<"  0  1   2   3   4   5   6   7   8   9   10  11  12  13  14"<<endl;
   for(int i=0; i<sizeOfBoard ; i++)
    {
        cout<<" ";
        for(int j=0; j<sizeOfBoard ; j++ )
        {
            cout<<point[i][j].shap;
        }
        cout<<i;
        cout<<endl;
        if(i!=sizeOfBoard-1)
        {
            for(int j=0; j<sizeOfBoard ; j++ )
            {
                cout<<"   ";
            }
        }

        cout<<endl;
    }
}
