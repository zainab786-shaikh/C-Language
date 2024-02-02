#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main(){
	int gd = DETECT , gm , x1,y1,x2,y2,dx,dy,step,xin,yin,i;
	initgraph(&gd,&gm,"c:\\TC\\BGI");

	printf("Enter starting point:");
	scanf("%d %d",&x1,&y1);
	printf("Enter ending point:");
	scanf("%d %d",&x2,&y2);

	dx = x2 - x1;
	dy = y2 -y1;
	if(dx >= dy){
		step = dx;
	}else{
		step = dy;
	}

	xin = dx/step;
	yin = dy/step;

	for(i=1;i<=step;i++){
		putpixel(x1,y1,YELLOW);
		x1 += xin;
		y1 += yin;
	}
	getch();
}