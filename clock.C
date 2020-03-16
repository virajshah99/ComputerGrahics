#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<string.h>

void main()
{
	int gd=DETECT,direct,gm,j,k,i,xc=250,yc=250;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(i=0;i<=1;i++)
	{
	 for(j=0;j<=360;j+=6)
	{
	 cleardevice();
	 circle(xc,yc,95);
	 direct=-1;
	 line(xc,yc,xc-50,yc-50);
	 line(xc,yc,xc+85*sin(60*M_PI/180),yc+85*cos(60*M_PI/180));
	 line(xc,yc,xc-90*direct*sin(j*M_PI/180),yc-90*cos(j*M_PI/180));
	 delay(1000);
}
getch();
}
}