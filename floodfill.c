#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void f_fill(int x,int y,int o_color,int n_color){
	int c;
	c = getpixel(x,y);
	if(c == o_color){
		putpixel(x,y,n_color);
		f_fill(x,y-1,o_color,n_color);
		f_fill(x+1,y,o_color,n_color);
		f_fill(x,y+1,o_color,n_color);
		f_fill(x-1,y,o_color,n_color);
	}
}
void main(){
	int gd = DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	circle(100,200,20);
	f_fill(100,200,BLACK,YELLOW);
	getch();
}