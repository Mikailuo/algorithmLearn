//���ڿ��ǰ�������뷽ʽ������������������߼���Ȼ�ǵ�һ�㣬�ڶ��㣨��һ������Һ��ӣ��������㣨�ڶ�������Һ��ӣ���ǰ������
//��˴�ͳ������ǰ�к���ݹ飩��Ȼ�޷�ʵ�֣����������ö��������Ƚ�����߼��Ľṹ��Ϊ�������ߡ�
//����ÿһ��ѭ���н�ĳһ��ĵ�i���������������жϣ������ڱ������У���һ�־ͽ��ò���һ��㣨���ֵܣ����ӿ����������Һ���
//�����Ĳ����߼����������뷽ʽ���߼����Ǻ��� 
 
#include<iostream>
#define elemtype char
#define SIZE 15
#define MAXSIZE 12
using namespace std;
typedef struct bitnode{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bittree;

struct queue{					//���е����ݽṹ{
	bittree bt[MAXSIZE];
	int front, rear;
};

void creat(queue &q);   //����һ���ն���
void enqueue(queue &q,bittree t);   //��t���
bittree dequeue(queue &q);   //���ӣ������ض�ͷԪ��
bool isempty(queue &q);    //�ж϶����Ƿ�Ϊ��

bittree init(elemtype c);           //ת��Ŀ������Ϊ��Ӧ�������Ľ�� 
void sqcreat(bittree &t,queue &q);				//�������Ĵ��� �������������ݣ���α����ĸ�ʽ 
void treedepth(bittree t,int h,int &depth);     //ǰ�������������� 
int depth(bittree t);				//�������
bool empty(bittree t);           //�Ƿ�Ϊ����

int main(void){
	bittree tree;
	queue q;
	int dep;
	sqcreat(tree,q);
	dep=depth(tree);
	cout<<dep<<endl;
	return 0;
}

void creat(queue &q){        //����һ����ѭ������
	q.front=q.rear=0;
}
void enqueue(queue &q,bittree t){			 //��bt��� 
	if((q.rear-q.front+MAXSIZE+1)%MAXSIZE==0){		//��ʱ������ 
		cout<<"error!queue is full"<<endl;
	}
	else{
		q.bt[q.rear]=t;
		q.rear=(q.rear+1)%MAXSIZE;
	}
}

bittree dequeue(queue &q){			  //���ӣ������ض���Ԫ��
	bittree p;
	if(isempty(q)){		//���п�
		cout<<"error!queue is empty"<<endl; 
	}
	else{
		p=q.bt[q.front];
		q.front=(q.front+1)%MAXSIZE;			//ע��������ѭ������ 
	}
	return p;
}

bool isempty(queue &q){
	if(q.rear==q.front) return true;
	else return false;
} 



bittree init(elemtype c){					//ת��Ŀ������Ϊ��Ӧ�������Ľ�� 
	bittree t;
	t=new bitnode;
	t->data=c;
	t->lchild=NULL;
	t->rchild=NULL;
	return t;
}

void sqcreat(bittree &t,queue &q){			//�������Ĵ��� �������������ݣ���α����ĸ�ʽ 
	bittree p;
	elemtype x;
	
	cin>>x;
	t=init(x);
	enqueue(q,t);					//�����ڵ���� 
	while(!isempty(q)){			//���в��գ�˵����������û�б�����Ҷ�ڵ� 
		p=dequeue(q);		//ȡ�����׽�㣬�ж����Һ�������������ں��Ӽ������ 
		cin>>x;
		if(x!='0'){						//��������ʱ�����롮0��,����˵���������� 
			p->lchild=init(x);              //�������ӽ�� 
			enqueue(q,p->lchild);		//����������� 
		}
		cin>>x;
		if(x!='0'){						//�ж�p���Һ������������ͬ���� 
			p->rchild=init(x);
			enqueue(q,p->rchild);
		}
	}
}

void treedepth(bittree t,int h,int &depth){				//�ݹ飬ǰ�������������� 
	if(t){
		if(h>depth) depth=h;					//����"���" 
		treedepth(t->lchild,h+1,depth);
		treedepth(t->rchild,h+1,depth);
	}
}

int depth(bittree t){				//�������
	bittree p=t;
	int depth=0;
	if(empty(t)) return depth;              //������Ȼ����� 
	else{
		treedepth(t,1,depth);         //
		return depth;
	}
}

bool empty(bittree t){				  //�ж��Ƿ�Ϊ����
	if(t==NULL) return true;
	else return false;
}

