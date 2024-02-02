#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void b_fill(int x , int y,int b_color,int f_color){
	int c = getpixel(x,y);
	if(c != b_color && c!=f_color){
		putpixel(x,y,f_color);
		b_fill(x,y-1,b_color,f_color);
		b_fill(x+1,y,b_color,f_color);
		b_fill(x,y+1,b_color,f_color);
		b_fill(x-1,y,b_color,f_color);
	}
}
void main(){
	int gd = DETECT , gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	circle(100,200,20);
	b_fill(100,200,WHITE,RED);
	getch();
}