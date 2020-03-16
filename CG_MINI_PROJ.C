#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main()
{
	int i=0,j;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");


	for (j=0;j<500;j++)
	{
		//ROAD
		line(0,390,639,390);
		if(j<=110)
		{
			//Signal
			arc(422,210,0,180,12);
			line(410,210,410,258);
			line(434,210,434,258);
			arc(422,258,180,360,12);
			circle(422,215,7);
			circle(422,236,7);
			circle(422,256,7);
			line(420,270,420,390);
			line(424,270,424,390);
			setfillstyle(1,RED);
			floodfill(422,215,WHITE);
			//CAR BODY
			line(50+i,370,90+i,370);
			arc(110+i,370,0,180,20);
			line(130+i,370,220+i,370);
			arc(240+i,370,0,180,20);
			line(260+i,370,300+i,370);
			line(300+i,370,300+i,350);
			line(300+i,350,240+i,330);
			line(240+i,330,200+i,300);
			line(200+i,300,110+i,300);
			line(110+i,300,80+i,330);
			line(80+i,330,50+i,340);
			line(50+i,340,50+i,370);
			//CAR Windows
			line(165+i,305,165+i,330);
			line(165+i,330,230+i,330);
			line(230+i,330,195+i,305);
			line(195+i,305,165+i,305);

			line(160+i,305,160+i,330);
			line(160+i,330,95+i,330);
			line(95+i,330,120+i,305);
			line(120+i,305,160+i,305);
			//Wheels
			circle(110+i,370,17);
			circle(240+i,370,17);
			delay(10);
			i++;
			cleardevice();
		}
		if(j>110 && j<=200)
		{
			//Signal
			arc(422,210,0,180,12);
			line(410,210,410,258);
			line(434,210,434,258);
			arc(422,258,180,360,12);
			circle(422,215,7);
			circle(422,236,7);
			circle(422,256,7);
			line(420,270,420,390);
			line(424,270,424,390);
			setfillstyle(1,YELLOW);
			floodfill(422,236,WHITE);
			//CAR BODY
			line(50+i,370,90+i,370);
			arc(110+i,370,0,180,20);
			line(130+i,370,220+i,370);
			arc(240+i,370,0,180,20);
			line(260+i,370,300+i,370);
			line(300+i,370,300+i,350);
			line(300+i,350,240+i,330);
			line(240+i,330,200+i,300);
			line(200+i,300,110+i,300);
			line(110+i,300,80+i,330);
			line(80+i,330,50+i,340);
			line(50+i,340,50+i,370);
			//CAR Windows
			line(165+i,305,165+i,330);
			line(165+i,330,230+i,330);
			line(230+i,330,195+i,305);
			line(195+i,305,165+i,305);

			line(160+i,305,160+i,330);
			line(160+i,330,95+i,330);
			line(95+i,330,120+i,305);
			line(120+i,305,160+i,305);
			//Wheels
			circle(110+i,370,17);
			circle(240+i,370,17);
			delay(10);
			cleardevice();
		}
		if(j>200 && j<=500)
		{
			//Signal
			arc(422,210,0,180,12);
			line(410,210,410,258);
			line(434,210,434,258);
			arc(422,258,180,360,12);
			circle(422,215,7);
			circle(422,236,7);
			circle(422,256,7);
			line(420,270,420,390);
			line(424,270,424,390);
			setfillstyle(1,GREEN);
			floodfill(421,256,WHITE);
			//CAR BODY
			line(50+i,370,90+i,370);
			arc(110+i,370,0,180,20);
			line(130+i,370,220+i,370);
			arc(240+i,370,0,180,20);
			line(260+i,370,300+i,370);
			line(300+i,370,300+i,350);
			line(300+i,350,240+i,330);
			line(240+i,330,200+i,300);
			line(200+i,300,110+i,300);
			line(110+i,300,80+i,330);
			line(80+i,330,50+i,340);
			line(50+i,340,50+i,370);
			//CAR Windows
			line(165+i,305,165+i,330);
			line(165+i,330,230+i,330);
			line(230+i,330,195+i,305);
			line(195+i,305,165+i,305);

			line(160+i,305,160+i,330);
			line(160+i,330,95+i,330);
			line(95+i,330,120+i,305);
			line(120+i,305,160+i,305);
			//Wheels
			circle(110+i,370,17);
			circle(240+i,370,17);
			i++;
			delay(10);
			cleardevice();
		}
	}
	getch();
}