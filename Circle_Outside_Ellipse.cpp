//==========================================
// Title:  Circle outside ellipse
// Author: Sagar Mahesh Bagwe
//==========================================
// Ellipse: center--> 300,300
//			a=80,b=40
// Circle:	radius--> 30

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void midptellipse(int rx, int ry, int xc, int yc)
{

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry)
         - (rx * rx * ry)
         + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy) {

        // Print points based on 4-way symmetry
        putpixel(x + xc, y + yc,15);
        putpixel(-x + xc, y + yc,15);
        putpixel(x + xc, -y + yc,15);
        putpixel(-x + xc, -y + yc,15);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0) {

        // printing points based on 4-way symmetry
        putpixel(x + xc, y + yc,15);
        putpixel(-x + xc, y + yc,15);
        putpixel(x + xc, -y + yc,15);
        putpixel(-x + xc, -y + yc,15);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

//==========================================
// Ellipse: center--> 300,300
//			a=80,b=40
// Circle:	radius--> 30
//==========================================

int main(){
    initwindow(600,600,"Ellipse");
    midptellipse(80,40,300,300);

    //Moving the circle around the perimeter
    circle(300,230,30);
    float x=0,y=0,a=110,b=70;
    for(int i=0;i<=(int)a;i++){
        x=i+300;
        y=sqrt(abs((b*b)*(1-((x-300)*(x-300)/(a*a)))))+300;
        //printf("%f %f",x,y);
        circle(x,y,30);
        delay(60);
        cleardevice();
        midptellipse(80,40,300,300);
    }
    for(int i=(int)a;i>=0;i--){
        x=i+300;
        y=sqrt(abs((b*b)*(1-((x-300)*(x-300)/(a*a)))))+300;
        //printf("%f %f",x,y);
        circle(x,600-y,30);
        delay(60);
        cleardevice();
        midptellipse(80,40,300,300);
    }
    for(int i=300;i>=(int)(300-a);i--){
        x=i;
        y=sqrt(abs((b*b)*(1-((x-300)*(x-300)/(a*a)))))+300;
        //printf("%f %f",x,y);
        circle(x,600-y,30);
        delay(60);
        cleardevice();
        midptellipse(80,40,300,300);
    }
    for(int i=220;i<=(int)(220+a);i++){
        x=i;
        y=sqrt(abs((b*b)*(1-((x-300)*(x-300)/(a*a)))))+300;
        //printf("%f %f",x,y);
        circle(x,y,30);
        delay(60);
        cleardevice();
        midptellipse(80,40,300,300);
    }
    getch();
    closegraph();
}
