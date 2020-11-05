#include<iostream>
#include "sqstock.h"
#define SIZE 4

using namespace std;
//基本操作函数 
void init(sqstock &L){
	L.top=-1;						//初始化栈，栈顶设置为-1 
	L.size=20;
	L.num=new int[L.size];
}

bool judge(sqstock &L){
	if(L.top==-1){				//判断是否到达栈底，空栈 
		return 	true;
	}
	else
	return false;
}

void push(sqstock &L,int e){
	if(L.top==L.size-1){				//判断是否到达栈顶 
		cout<<"full error! "<<"fail to push,plz pop something!"<<endl; 
	}
	else{
		L.top++;
		L.num[L.top]=e;		
	}
}

void pop(sqstock &L,int &e){
//	if(judge(L)){
//		cout<<"empty error! "<<"fail to pop,plz push something!"<<endl;
//	}
//	else{
//		cout<<L.num[L.top];
		e=L.num[L.top];
		L.top--;	
//	}	
}

int get_top(sqstock &L){
	return L.top;
}

void stockprint(sqstock L){         //打印栈，待会重点考量 
	while(!judge(L)){
		cout<<L.num[L.top]<<" ";
		L.top--;
	}
	cout<<endl;
}
//void stockprint(sqstock &L){         //打印栈，待会重点考量 
//	int top=L.top;
//	while(top!=-1){
//		cout<<L.num[top]<<" ";
//		top--;
//	}
//}

//复杂问题函数
void match(int origin[]){   //出栈顺序问题 
	int i=0,j=0;
	int top=-1;
	int data;
	int goal[SIZE];
	sqstock L;
	init(L);
	
	cout<<"plz input number: "<<endl;
	for(i=0;i<SIZE;i++){
		cin>>data;
		goal[i]=data;
	}	
	i=0;
	while(1){
		if(top<L.size){
			if(i<SIZE){
				push(L,origin[i]);				
			}
			top=get_top(L);
			if(goal[j]==L.num[top]){
				pop(L,data);
				j++;
				cout<<data<<"WTF\n";
			}
			i++;
			if(i>2*SIZE){
				break;
			}
		}
		else 
		break;
	}
	if(judge(L)){
		cout<<"successfully matching!"<<endl;
	}
	else{
		cout<<"Fail to match!gosh1"<<endl;	
	}
}

void bagqs(int w[],int weight,int n){     //背包问题-非递归 ，其中w[]为每个物体重量，weight为背包最大承重量，n即为个数 
	sqstock st1;
	int k=0;
	int jud=0;
	
	init(st1);
	do{
		while(k<n&&weight>0){
			if(weight-w[k]>=0){
				push(st1,k);
				weight-=w[k];
			}
			k++;	
		}
		if(weight==0){       //背包满了 
			stockprint(st1); 
			jud+=1;
		}
		pop(st1,k);
		weight+=w[k]; 
		k++;
	}while(!judge(st1)||k<n);
	if(jud==0) cout<<"该条件无解";
}
//void destroy(sqstock &L){
//	delete int[];
//}
