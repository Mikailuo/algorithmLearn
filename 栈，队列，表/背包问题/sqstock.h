#include<iostream>
using namespace std;

typedef struct {
	int size;
	int* num;
	int top;
}sqstock;

//typedef struct {
//	int size=20;
//	int num[size];
//	int top;
//}sqlist;

void init(sqstock &L);
void push(sqstock &L,int e);
void pop(sqstock &L,int &e);
int get_top(sqstock &L);
bool judge(sqstock &L);
void destroy(sqstock L);
void stockprint(sqstock L);         //探讨一下函数内部的传参原理 
//void stockprint(sqstock &L);

void match(int origin[]);
void bagqs(int w[],int weight,int n);

