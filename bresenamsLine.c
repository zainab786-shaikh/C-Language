#include<stdio.h>
#inlclude<conio.h>
#include<graphics.h>
#include<dos.h>
int main(){
	int gd = DETECT , gm,x,y,x1,y1,x2,y2,dx,dy,p;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	printf("Enter starting point:");
	scanf("%d %d",&x1,&y1);
	printf("Enter ending point:");
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2*dy-dx;
	while(x<= x2){
		putpixel(x,y,WHITE);
		x++;
		if(p<0){
			p = p+2*dy;
		}else{
			p = p+2*dy-2*dx;
			y++;
		}
	}
	getch();
}