#include<iostream>
#include<cstring>
#define SIZE 10
using namespace std;

typedef struct{
	char name[SIZE];
	int time;
}elem;
typedef struct{
	elem* num;
	int head;
	int tail;
	int length;
}Q;
void init(Q &q);
void enqueue(Q &q,char a[],int e);
elem dequeue(Q &q);
bool isempty(Q &q);
bool isfull(Q &q);
void shorten(Q &q,int pos);
void arrange(Q &q,int timeszie);

int main(void){
	Q queue;
	int max_time,i,time;
	char name[SIZE];
	init(queue);
	cin>>max_time;
	for(i=0;i<queue.length-1;i++){
		cin>>name>>time;
		enqueue(queue,name,time);
	}
	arrange(queue,max_time); 
	return 0;
}

void init(Q &q){
	int number;
	cout<<"plz input number which do you need: ";
	cin>>number;
	q.num=new elem[number+1]; 				//保留一个elem的空间做缓冲           
	q.head=q.tail=0;
	q.length=number+1;
}

void enqueue(Q &q,char a[],int e){
	if(isfull(q)){
		cout<<"ERROR!fail to insert!"<<endl;
	}
	else{
		strcpy(q.num[q.tail].name,a);
		q.num[q.tail].time=e;
		q.tail=(q.tail+1)%q.length;
	}
}

elem dequeue(Q &q){
	elem p;
	if(isempty(q)){
		cout<<"ERROR!fail to delete!"<<endl;
	}
	else{
		strcpy(p.name,q.num[q.head].name);
		p.time=q.num[q.head].time;
		q.head=(q.head+1)%q.length;	
	}
	return p;
}

bool isempty(Q &q){
	if(q.head==q.tail) return true;
	else return false;
}

bool isfull(Q &q){
	if(q.head==(q.tail+1)%q.length) return true;
	else return false;
}

//错误示范，吐了都。。。改了一下午 
//void shorten(Q &q,int pos){
//	int i;
//	for(i=pos+1;i<q.length;i++){
//		q.num[i-1]=q.num[i];
//	}
//	q.length--;
//	if(q.tail>q.head)
//	q.tail=(q.tail+q.length-1)%q.length;
////	if(q.head!=0)
//	q.head=(q.head+q.length-1)%q.length;
//}
//
//void arrange(Q &q,int timesize){
//	int time=0,pos=0;
//	elem p;
//	while(!isempty(q)){
//		pos=q.head;
//		p=dequeue(q);
////		cout<<p.name<<"---"<<p.time<<endl;
//		if(p.time<=timesize){
//			shorten(q,pos);
//			time+=p.time;
////			cout<<"         "<<p.name<<" "<<time<<endl;
//		}
//		else{
//			p.time-=timesize;
//			enqueue(q,p.name,p.time);
//			time+=timesize;
////			cout<<p.name<<"---"<<p.time<<endl;
//		}
//		if(q.length==1) break;
//	}
//}

//根本不用考虑他范围的缩小，直接有head和tail控制即可 
void arrange(Q &q,int timesize){
	int time=0,pos=0;
	elem p;
	while(!isempty(q)){
		pos=q.head;
		p=dequeue(q);
		if(p.time<=timesize){			
			time+=p.time;
			cout<<p.name<<" "<<time<<endl;
		}
		else{
			p.time-=timesize;
			enqueue(q,p.name,p.time);
			time+=timesize;
		}
	}
}
