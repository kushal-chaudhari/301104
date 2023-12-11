#include<iostream>
#include<graphics.h>
#include<cmath>
#include<stdlib.h>
using namespace std;

class algo
{
    public:
    void dda(float x1, float x2, float y1, float y2);
    void bres(int x,int y,int r);
};

void algo::dda(float x1, float y1, float x2, float y2)
{
    float step;
    float dx=(x2-x1);
    float dy=(y2-y1);
    if (abs(dx)>=abs(dy))
    {
        step=abs(dx);
    }
    else
    {
        step=abs(dy);
    }

    dx=float(dx/step);
    dy=float(dy/step);

    float x=x1;
    float y=y1;
    putpixel(x,y,15);

    int i=1;
    while(i<=step)
    {
        putpixel(x,y,15);
        x=x+dx;
        y=y+dy;
        i++;
        delay(10);
    }
}

void algo:: bres(int x,int y,int r)
{
    int x1=0;
    int y1=r;
    float p=3-(2*r);
    while (x1<=y1)
    {
        putpixel(x+x1,y+y1,15);
        putpixel(x+x1,y-y1,15);
        putpixel(x-x1,y+y1,15);
        putpixel(x-x1,y-y1,15);
        putpixel(x+y1,y+x1,15);
        putpixel(x+y1,y-x1,15);
        putpixel(x-y1,y+x1,15);
        putpixel(x-y1,y-x1,15);
    
        x1++;

        if (p<=0)
        {
            p= p+(4*x1)+6;
        }
        else
        {
            p= p+(4*(x1-y1))+10;
            y1--;
        }
        delay(20);

        
    }

}

int main()
{
    algo a1;
    //int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    initwindow(630,480);
    int r;
    cout<<"Enter the radius"<<endl;
    cin>>r;
    a1.bres(320,240,r);
    float ang=3.24/180;
    float c= r*cos(30*ang);
    float s=r*sin(30*ang);
    //vertices of triangel are 0,r   0-c,0-s    0+c,0-s
    setcolor(15);
    a1.dda(320,240-r,320+c,240+s);
    a1.dda(320+c,240+s,320-c,240+s);
    a1.dda(320-c,240+s,320,240-r);
    a1.bres(320,240,int(s));
    delay(200);
    closegraph();
    return 0;
}