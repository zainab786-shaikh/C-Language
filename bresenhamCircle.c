#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void drawCircle(int xc , int yc , int x,int y){
	putpixel(xc + x,yc + y , RED);
	putpixel(xc - x,yc + y , RED);
	putpixel(xc + x,yc - y , YELLOW);
	putpixel(xc - x,yc - y , YELLOW);

	putpixel(xc + y,yc + x , WHITE);
	putpixel(xc - y,yc + x , WHITE);
	putpixel(xc + y,yc - x , BLUE);
	putpixel(xc - y,yc - x , BLUE);
}
void main(){
	int gd = DETECT,gm,x,y,xc,yc,r,p;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the coordinates of center of the circle:");
	scanf("%d %d",&xc,&yc);
	printf("Enter the radius of circle:");
	scanf("%d",&r);

	x=0;
	y=r;
	p=3-2*r;

	while(x<=y){
	drawCircle(xc,yc,x,y);
		x++;
		if(p<0){
			p=p+4*x+6;
		}else{
			y--;
			p=p+4*(x-y)+10;
		}
	       //	drawCircle(xc,yc,x,y);
	}
	getch();
}