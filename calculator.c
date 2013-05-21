#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
int str[100];
int c;
int a=0;
int b=0;
int op,gk;
int count=0;
int power(int a,int b){
	int c=a;
	if(b==0) return 1; else{
		while(b>0){c*=a;b--;}
	}
	return c/a;
}
void read(){
	int i=0;
	while ((c = getchar()) !='\n'){
		if(c!=' ') {str[i] = c;count++;}
		i++;
		}
}
void err(){
	printf("%s","Error! Please enter correct expression!\n");
}

float calculate(int a,int b){
	float t =a;
	float r =b;
	if (op==0) return t + r;
	if (op==1) return t - r;
	if (op==2) return t * r;
	if (op==3) return t / r;
	if (op==4) return t - (t / r)*r;
}
void getNumbers(int k){
	float a = 0;
	float b = 0;
	int i = 0;
	while(i<count){
		if(i<k) a+=(str[i]-48) * power(10,k-i-1);
		if(i>k) b+=(str[i]-48) * power(10,count-i-1);
	i++;
	}
	printf("%s","Answer : ");
	printf("%f",calculate(a,b));
	printf("%s\n","");
}
void findoperation(){
	int i=0;
	int c=0;
	int k=0;
	char s[5]="+-*/%";
	while(i<5){
		int g=0;
		while(str[g]!='\n'){
			if(str[g]==s[i]){c=1;k=g;break;}
			g++;
		}
		if(c==1) break; else i++;
	}
	op=i;
	getNumbers(k);
	
}
int correctinformation(){
	char s[10] = "0123456789";
	int g=0;
	int y=0;
	while(g<count){	
		int i=0;	
		while(i<10){
			if(str[g]==48+i)y++;
			i++;
		}
		if(y==g) if(str[g]==43 | str[g]==45 | str[g]==42 | str[g]==47 | str[g]==37) y++;
		if(y!=g+1){err(); return 0;}
		g++;
	}
	return 1;
}

