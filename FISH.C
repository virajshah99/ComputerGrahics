#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bezier(int *x, int *y)
{

	int i;
	double t,xt,yt;
	for(t=0.0;t<1.0;t+=0.001)
	{
		xt = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
		yt = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
		putpixel(xt, yt, RED);
	}
}
void main()
{
	int gd=DETECT,gm,i,j;
	int x[]={100,200,300,400}, y1[]={100,25,150,50}, y2[]={100,175,50,150};
	int xtail[]={400,375,375,400}, ytail[]={50,80,120,150};
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(WHITE);
	for(i=0;i<100;i++)
	{
		cleardevice();
		bezier(x,y1);
		bezier(x,y2);
		bezier(xtail,ytail);
		delay(100);
	}
	getch();
	closegraph();
}