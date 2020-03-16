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
	int p=0;
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
	int gd=DETECT,gm,k,i,xc=40,yc=300;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(k=0;k<5;k++)
	{
	for(i=0;i<16;i++)
	{
	cleardevice();
	Drawcircle(xc,yc,30);
	floodfill(xc,yc,4);
	xc++;
	yc+=10;
	delay(100);
	}

	for(i=0;i<16;i++)
	{
	cleardevice() ;
	Drawcircle(xc,yc,30);
	floodfill(xc,yc,4);
	xc++;
	yc-=10;
	delay(100);
	}
	}
	getch();
}