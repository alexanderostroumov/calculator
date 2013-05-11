//#include <glibc>
#include <stdlib.h>
#include <stdio.h>
#include "calculator.h"
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
void correctinformation(){
	char s[15] ="0123456789+-*/%";
	int g=0;
	int y=0;
	while(str[g]!='\n'){	
		int i=0;	
		while(i<15){	
			if(str[g]==s[i])y++;
			i++;
		}
		if(y!=1){err(); break;}
		g++;
	}
}
int calculate(int a,int b){
	if (op==0) return a + b;
	if (op==1) return a - b;
	if (op==2) return a * b;
	if (op==3) return a / b;
	if (op==4) return a - (a / b)*b;
	//if (op==5) return a  b;
}
void getNumbers(int k){
	int a = 0;
	int b = 0;
	int i = 0;
	printf("%s", "count:");
	printf("%d\n",count);
	while(i<count){
		if(i<k) a+=(str[i]-48)*power(10,k-i-1);
		if(i>k) b+=(str[i]-48) * power(10,count-i-1);
	i++;
	}
	//printf("%d\n",a);
	//printf("%d\n",b);
	printf("%s","Answer : ");
	printf("%d",calculate(a,b));
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
	printf("%d\n",op);
	getNumbers(k);
	
}


int main(int argc, char* argv){	
	read();
	//correctinformation();
	findoperation();
	return 0;
}
