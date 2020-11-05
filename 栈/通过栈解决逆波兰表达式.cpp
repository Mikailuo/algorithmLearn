//
////#include<iostream>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define SIZE 20
////using namespace std;
//
//typedef struct{
//	int a[SIZE];
////	int length;
//	int top;             //Õ»¶¥
//}stock;
//
//void init(stock &L);
//void push(stock &L,int e);
//void pop(stock &L,int &e);
//bool isfull(stock &L);
//int gettop(stock &L);
//bool isempty(stock &L);
//
//int main(void){
//	int a,b,answer,e;
//	char s[10];
//	stock l;
//	init(l);
//
//	while(scanf("%s",s),s[0]!='m'){
//            printf("!!!");
//		if(s[0]=='+'){
//			pop(l,b);
//			pop(l,a);
//			push(l,a+b);
//		}
//		else if(s[0]=='-'){
//			pop(l,b);
//			pop(l,a);
//			push(l,a-b);
//		}else if(s[0]=='*'){
//			pop(l,b);
//			pop(l,a);
//			push(l,a*b);
//		}else if(s[0]=='/'){
//			pop(l,b);
//			pop(l,a);
//			push(l,a/b);
//		}else{
//			push(l,atoi(s));
//		}
//
////		if(sosa=='\0') break;
//	}
//    printf("???");
//	answer=gettop(l);
//	printf("%d\n",answer);
//}
//
//void init(stock &L){
//	L.top=-1;
//}
//
//void push(stock &L,int e){
//	L.top++;
//	L.a[L.top]=e;
//}
//
//void pop(stock &L,int &e){
//	e=L.a[L.top];
//	L.top--;
//}
//int gettop(stock &L){
//	int answer;
//	answer=L.a[L.top];
//	return answer;
//}


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	int a,b;
	stack<int > sta;
	char s[100];
	while(scanf("%s", s)!=EOF)  {
		if( s[0] == '+')  {
			a=sta.top();
			sta.pop();
			b=sta.top();
			sta.pop();
			sta.push(a + b);
		}  else if(s[0] == '-')  {
			b=sta.top();
			sta.pop();
			a=sta.top();
			sta.pop();
			sta.push(a - b);
		} else if(s[0] == '*')  {
			a=sta.top();
			sta.pop();
			b=sta.top();
			sta.pop();
			sta.push(a * b);
		} else {
			sta.push(atoi(s));
		}
		printf("%d\n", sta.top());
	}
	printf("%d\n", sta.top());
	return 0;
}

