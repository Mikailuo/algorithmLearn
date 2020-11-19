//由于考虑按层次输入方式来构造二叉树，构造逻辑必然是第一层，第二层（第一层的左右孩子），第三层（第二层的左右孩子，从前往后排
//因此传统方法（前中后序递归）必然无法实现，因此这里采用队列这种先进后出逻辑的结构作为操作工具。
//即，每一轮循环中将某一层的第i个结点的左右子树判断，若存在便放入队列，下一轮就将该层下一结点（右兄弟）出队考虑他的左右孩子
//这样的操作逻辑就与层次输入方式的逻辑相吻合了 
 
#include<iostream>
#define elemtype char
#define SIZE 15
#define MAXSIZE 12
using namespace std;
typedef struct bitnode{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bittree;

struct queue{					//队列的数据结构{
	bittree bt[MAXSIZE];
	int front, rear;
};

void creat(queue &q);   //创建一个空队列
void enqueue(queue &q,bittree t);   //将t入队
bittree dequeue(queue &q);   //出队，并返回对头元素
bool isempty(queue &q);    //判断队列是否为空

bittree init(elemtype c);           //转化目标数据为对应二叉树的结点 
void sqcreat(bittree &t,queue &q);				//二叉树的创建 ，队列输入数据（层次遍历的格式 
void treedepth(bittree t,int h,int &depth);     //前序遍历求树的深度 
int depth(bittree t);				//树的深度
bool empty(bittree t);           //是否为空树

int main(void){
	bittree tree;
	queue q;
	int dep;
	sqcreat(tree,q);
	dep=depth(tree);
	cout<<dep<<endl;
	return 0;
}

void creat(queue &q){        //创建一个空循环队列
	q.front=q.rear=0;
}
void enqueue(queue &q,bittree t){			 //将bt入队 
	if((q.rear-q.front+MAXSIZE+1)%MAXSIZE==0){		//此时队列满 
		cout<<"error!queue is full"<<endl;
	}
	else{
		q.bt[q.rear]=t;
		q.rear=(q.rear+1)%MAXSIZE;
	}
}

bittree dequeue(queue &q){			  //出队，并返回队首元素
	bittree p;
	if(isempty(q)){		//队列空
		cout<<"error!queue is empty"<<endl; 
	}
	else{
		p=q.bt[q.front];
		q.front=(q.front+1)%MAXSIZE;			//注意这里是循环队列 
	}
	return p;
}

bool isempty(queue &q){
	if(q.rear==q.front) return true;
	else return false;
} 



bittree init(elemtype c){					//转化目标数据为对应二叉树的结点 
	bittree t;
	t=new bitnode;
	t->data=c;
	t->lchild=NULL;
	t->rchild=NULL;
	return t;
}

void sqcreat(bittree &t,queue &q){			//二叉树的创建 ，队列输入数据（层次遍历的格式 
	bittree p;
	elemtype x;
	
	cin>>x;
	t=init(x);
	enqueue(q,t);					//将根节点入队 
	while(!isempty(q)){			//队列不空，说明还有子树没有遍历到叶节点 
		p=dequeue(q);		//取出队首结点，判断左右孩子情况，若存在孩子即入队列 
		cin>>x;
		if(x!='0'){						//当无左孩子时，输入‘0’,这里说明存在左孩子 
			p->lchild=init(x);              //创建左孩子结点 
			enqueue(q,p->lchild);		//将左孩子入队列 
		}
		cin>>x;
		if(x!='0'){						//判断p的右孩子情况，过程同上文 
			p->rchild=init(x);
			enqueue(q,p->rchild);
		}
	}
}

void treedepth(bittree t,int h,int &depth){				//递归，前序遍历求树的深度 
	if(t){
		if(h>depth) depth=h;					//经典"框架" 
		treedepth(t->lchild,h+1,depth);
		treedepth(t->rchild,h+1,depth);
	}
}

int depth(bittree t){				//树的深度
	bittree p=t;
	int depth=0;
	if(empty(t)) return depth;              //空树自然无深度 
	else{
		treedepth(t,1,depth);         //
		return depth;
	}
}

bool empty(bittree t){				  //判断是否为空树
	if(t==NULL) return true;
	else return false;
}

