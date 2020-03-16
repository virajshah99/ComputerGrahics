#include<stdio.h>
#include<graphics.h>
// #include<conio.h>
// #include<dos.h>
#include<math.h>
#include<string.h>

void mptcircle(int xc, int yc, int r)
{
	int i,xk,yk,xk1,yk1;
	int p;

	p=1-r;
	xk=0;
	yk=r;
	while(xk<=yk)
	{
		putpixel(xc+xk,yc+yk,RED);
		putpixel(xc+xk,yc-yk,RED);
		putpixel(xc-xk,yc-yk,RED);
		putpixel(xc-xk,yc+yk,RED);
		putpixel(xc+yk,yc+xk,RED);
		putpixel(xc+yk,yc-xk,RED);
		putpixel(xc-yk,yc+xk,RED);
		putpixel(xc-yk,yc-xk,RED);
		xk1=xk+1;
		if(p>=0)
		{
			yk1=yk-1;
			p=p+2*xk1-2*yk+3;
		}
		else
		{
			yk1=yk;
			p=p+2*xk1+1;
		}
		xk=xk1;
		yk=yk1;
	}

}

int direction(int difference)
{
    if(difference > 0)
    return 1;
    else if(difference < 0)
    return -1;
    else
    return 0;
}

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int x,y,dx,dy,swap,temp,s1,s2,p,i;

    x=x1;
    y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=direction(x2-x1);
    s2=direction(y2-y1);

    swap=0;

    if(dy>dx)
    {
        temp=dx;
        dx=dy;
        dy=temp;
        swap=1;
    }
    p=2*dy-dx;

    for(i=0;i<=dx;i++)
    {
        putpixel(x,y,RED);
        while(p>=0)
        {
            p=p-2*dx;

            if(swap)
                x+=s1;
            else
                y+=s2;
        }
        p=p+2*dy;

        if(swap)
            y+=s2;
        else
            x+=s1;
    }
}

void main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "");
    // setbkcolor(WHITE);

    int i,j,r=50;

    char number[2];

    // setcolor(BLACK);

    for(i=0;i<=360*5;i+=6)
    {
        cleardevice();
        mptcircle(250,250,r+15);
        for(j=1;j<=12;j++)
        {
            sprintf(number, "%d", j);
            outtextxy(250+round(-r*sin(-j*30*M_PI/180))-3,250+round(-r*cos(-j*30*M_PI/180))-3,number);
            // mptcircle(250+round(r*cos(j*30*M_PI/180)),250+round(r*sin(j*30*M_PI/180)), 5);
        }
        bresenhamLine(250,250,250+round(r*cos(i*M_PI/180)),250+round(r*sin(i*M_PI/180)));
        bresenhamLine(250,250,250+round(r/3*cos(i/60*M_PI/180)),250+round(r/3*sin(i/60*M_PI/180)));
        delay(100);
    }

    getch();
    closegraph();
}
