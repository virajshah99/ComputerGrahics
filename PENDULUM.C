#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>


void Draw(int x,int y, int p, int q,int i)
{
	putpixel(x+p,y+q,i);
	putpixel(x+p,y-q,i);
	putpixel(x-p,y+q,i);
	putpixel(x-p,y-q,i);
	putpixel(x+q,y+p,i);
	putpixel(x+q,y-p,i);
	putpixel(x-q,y+p,i);
	putpixel(x-q,y-p,i);

}
void Drawcircle(int xc,int yc,int r)
{
	int x=0,y=r;
	int p=1-r;
	while(x<=y)
	{
		Draw(xc,yc,x,y,4);
		x++;
		if(p<0)
		p+=2*x+1;
		else
		{
			y--;
			p+=2*x-2*y+1;
		}
	}
}
void flood(float x,float y,int new,int old){
int curr = getpixel(x,y);
if(curr == old)
{
putpixel(x,y,new);
delay(5);
flood(x+1,y+1,new,old);
flood(x,y+1,new,old);
flood(x-1,y+1,new,old);
flood(x+1,y-1,new,old);
flood(x,y-1,new,old);
flood(x-1,y-1,new,old);
flood(x+1,y,new,old);
flood(x-1,y,new,old);
}
}

void main()
{
	int gd=DETECT,direct,gm,j,k,i,xc=250,yc=250,R=100,r=10;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(i=0;i<=3;i++)
	{
	 direct = (i%2==0)?+1:(-1);
	 for(j=0;j<=60;j++)
	 {
	 cleardevice();
	 Drawcircle(xc+R*direct*sin(j*M_PI/180),yc+R*cos(j*M_PI/180),r);
	 line(xc,yc,xc+90*direct*sin(j*M_PI/180),yc+90*cos(j*M_PI/180));
	 delay(20);
	}
	 for(k=60;k>0;k--)
	 {
	 cleardevice();
	 Drawcircle(xc+R*direct*sin(k*M_PI/180),yc+R*cos(k*M_PI/180),r);
	 line(xc,yc,xc+90*direct*sin(k*M_PI/180),yc+90*cos(k*M_PI/180));
	 delay(20);
	}
      }
	getch();
}
