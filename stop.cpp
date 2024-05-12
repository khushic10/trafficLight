#include<stdio.h>
#include<graphics.h>
#include<dos.h>
int x=0,y=0;
void background()
{
	setcolor(0);
	rectangle(420,280,430,500);//stop 1
	setfillstyle(1,15);
	floodfill(425,300,0);
	//traffic light 1
	circle(520,200,15);
	circle(520,165,15);
	circle(520,130,15);
	rectangle(500,110,540,220);
	line(520,270,520,220);
	setfillstyle(1,8);//circles
	floodfill(520,200,0);
	floodfill(520,165,0);
	floodfill(520,130,0);
	setfillstyle(1,6);
	floodfill(505,150,0);
	//traffic light 2
	circle(1000,200,15);
	circle(1000,165,15);
	circle(1000,130,15);
	rectangle(980,110,1020,220);
	line(1000,270,1000,220);
	setfillstyle(1,8);//circles
	floodfill(1000,200,0);
	floodfill(1000,165,0);
	floodfill(1000,130,0);
	setfillstyle(1,6);
	floodfill(985,150,0);
	rectangle(900,280,910,500);//stop 2
	setfillstyle(1,15);
	floodfill(905,300,0);
	//zebra crossing
	rectangle(440,300,520,320);
	rectangle(440,340,520,360);
	rectangle(440,380,520,400);
	rectangle(440,420,520,440);
	rectangle(440,460,520,480);
	rectangle(920,300,1000,320);
	rectangle(920,340,1000,360);
	rectangle(920,380,1000,400);
	rectangle(920,420,1000,440);
	rectangle(920,460,1000,480);
	rectangle(0,280,1200,500);//road
	setfillstyle(1,7);
	floodfill(100,300,0);
	floodfill(1100,300,0);
	floodfill(600,300,0);
	rectangle(0,100,1200,280);//background
	setfillstyle(1,10);
	floodfill(100,580,0);
	floodfill(100,250,0);
	setfillstyle(1,11);
	floodfill(10,10,0);

}
int car(int sb)
{
	int position=-30;
	setcolor(6);
	//body
	line(5+sb,340,95+sb,340);
	line(140+sb,370,120+sb,370);
	line(-30+sb,380,-30+sb,410);
	line(5+sb,340,-30+sb,380);
	line(95+sb,340,120+sb,370);
	line(140+sb,370,140+sb,410);
	line(-30+sb,410,0+sb,410);
	arc(15+sb,410,0,180,15);
	line(30+sb,410,70+sb,410);
	arc(85+sb,410,0,180,15);
	line(100+sb,410,140+sb,410);
	setfillstyle(1,1);
	floodfill(-20+sb,380,6);
	floodfill(10+sb,380,6);
	//tyres
	circle(15+sb,410,12);
	circle(85+sb,410,12);
	setfillstyle(1,9);
	floodfill(15+sb,410,6);
	floodfill(85+sb,410,6);
	//windows
	line(0+sb,370,45+sb,370);
	line(10+sb,350,45+sb,350);
	line(45+sb,350,45+sb,370);
	line(10+sb,350,0+sb,370);
	rectangle(55+sb,350,90+sb,370);
	floodfill(20+sb,360,6);
	floodfill(60+sb,360,6);
	
	position+=sb;
	return position;
}
void red()
{
	setfillstyle(1,4);
	floodfill(520,130,0);
}
void green()
{
	setfillstyle(1,2);
	floodfill(520,165,0);
}
void yellow()
{
	setfillstyle(1,14);
	floodfill(520,200,0);
}
void red1()
{
	setfillstyle(1,4);
	floodfill(1000,130,0);
}
void green1()
{
	setfillstyle(1,2);
	floodfill(1000,165,0);
}
void yellow1()
{
	setfillstyle(1,14);
	floodfill(1000,200,0);
}
void traffic(int a,int b,int c,int d)
{
	x++;
	y++;
	if(x<=a)
	{
		yellow();
	}
	else if(x>a && x<=b) 
	{
		red();
	}
	else if(x>b && x<=c)
	{
		green();
		if(x==c)
			x=0;
	}
	if(y<=a+d)
	{
		yellow1();
	}
	else if(y>a+d && y<=b+d) 
	{
		red1();
	}
	else if(y>b+d && y<=c+d)
	{
		green1();
		if(y==c+d)
			y=0;
	}

}
main()
{
	initwindow(1200,600,"Traffic",50,50);
	int page=0,n=0,sb=0,e=35,f,color1,color2,position;
	setbkcolor(15);
	while(n<500)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		background();
		position=car(sb);
		traffic(30,90,150,110);
		color1=getpixel(520,130);
		if(color1==4 && position>240 && position+170<420)
		{
			sb+=0;
		}
		else if(color2==4 && position>720 && position+170<900)
		{
			sb+=0;
		}
		else
		{
			sb+=5;
		}
		color2=getpixel(1000,130);
		page=(1-page);
		delay(20);
		n++;
	}
			setactivepage(1);
	getch();
	closegraph();
}