//（完全）二叉树的建立

#include<iostream>
#define elemtype char
#define SIZE 15
using namespace std;
typedef struct bitnode{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bittree;

bittree init(elemtype c);           //转化目标数据为对应二叉树的结点 
void creat(bittree &t,elemtype a[],int &i,int n);          //二叉树的创建
bool empty(bittree t);           //判断是否为空树
void treedepth(bittree t,int h,int &depth);     //前序遍历求树的深度 
int depth(bittree t);				//树的深度
bittree leftchild(bittree t,bittree e);      //求t树e指针指向的结点的左孩子
bittree rightchild(bittree t,bittree e);      //求t树e指针指向的结点的右孩子 
bittree getlocal(bittree t,elemtype a);        //得到数据a的结点位置
void treegetlocal(bittree t,elemtype a,bittree &p);        //遍历二叉树，若存在对应的a则修改已有的p 
bittree parent(bittree t,bittree e);		//e所指结点的父母  
void treeparent(bittree t,bittree e,bittree &p); 		     //递归求结点父母 
bittree leftsibling(bittree t,bittree e);       //e所指结点的左兄弟
bittree rightsibling(bittree t,bittree e);      ///e所指结点的右兄弟 
void insertchild(bittree &t,bittree p,int LR,bittree e);      			//对二叉树t的p结点进行左/右（0/1）插入结点e，使之成为对应孩子 
void deletechild(bittree &t,bittree e,int LR);                  //对二叉树t中的e结点下的子树进行删除 
void show(bittree t);           //遍历二叉树并输出结点数据 
 
int main(void){
	elemtype a[SIZE]={'1','2','3','#','4','#','#','5','#','#','6','#','7','#','#'};			//按照前序表达式给值，若为完全二叉树只需用顺序表规则转化即可 
	bittree tree=NULL;
	bittree input=NULL;
	bittree goal=NULL;
	int i=0;
//	init(tree);
	creat(tree,a,i,SIZE);
	show(tree);
	cout<<endl;
	
	input=init('A');
	goal=getlocal(tree,'6'); 
	insertchild(tree,goal,0,input);    //正确无误 
	goal=getlocal(tree,'6'); 
	insertchild(tree,goal,1,input);     //会报错，因为6有右孩子 
	show(tree);
	
	return 0;
}

bittree init(elemtype c){					//转化目标数据为对应二叉树的结点 
	bittree t;
	t=new bitnode;
	t->data=c;
	t->lchild=NULL;
	t->rchild=NULL;
}

void creat(bittree &t,elemtype a[],int &i,int n){			//二叉树的递归创建
cout<<a[i];
	if(i<n){							//i=n时说明已到输入数组末端，没有数据填入二叉树了 
		if(a[i]=='#') {t=NULL; i++;}				//此时说明上一节点该位置处无孩子,i+1; 
		else{
			t=new bitnode;
			t->data=a[i++];
			creat(t->lchild,a,i,n);            //迭代遍历每一分支,同时i+1 
			creat(t->rchild,a,i,n);
		}
	}
}

bool empty(bittree t){				  //判断是否为空树
	if(t==NULL) return true;
	else return false;
}

void treedepth(bittree t,int h,int &depth){				//递归，前序遍历求树的深度 
	if(t){
		if(h>depth) depth=h;
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
	}
	return depth;
}
	
bittree leftchild(bittree t,bittree e){				   //求t树e指针指向的结点的左孩子
	bittree p;
	p=e->lchild;
	return p; 
} 

bittree rightchild(bittree t,bittree e){				   //求t树e指针指向的结点的右孩子
	bittree p;
	p=e->rchild;
	return p; 
} 

bittree getlocal(bittree t,elemtype a){			    //得到数据a的结点位置
	bittree p=NULL;
	treegetlocal(t,a,p);
	return p;
}

void treegetlocal(bittree t,elemtype a,bittree &p){
	if(t){
		if(t->data==a){
			p=t;								//值得注意的是，这里的p表示的遍历所有后最后一个与a相等的结点位置 
		}
		else{
			treegetlocal(t->lchild,a,p); 			//不断递归遍历子树 
			treegetlocal(t->rchild,a,p);			
		}
	}
}

bittree parent(bittree t,bittree e){				//e所指结点的父母  
	bittree p=NULL;
	treeparent(t,e,p);
	return p;
}

void treeparent(bittree t,bittree e,bittree &p){      //递归求结点父母 
	if(t){
		if(t->lchild==e||t->rchild==e){					//这里同上一个函数，一般取最后一个结点地址 
			p=t;
		}
		else{
			treeparent(t->lchild,e,p);
			treeparent(t->rchild,e,p);
		}
	}
}

bittree leftsibling(bittree t,bittree e){	     //e所指结点的左兄弟
	bittree parent1=NULL;
	bittree lchild=NULL;
	parent1=parent(t,e);					//得到e的父母结点 
	lchild=leftchild(t,parent1);				//得到父母的左孩子，即左兄弟 
	return lchild;
}

bittree rightsibling(bittree t,bittree e){	 		//e所指结点的右兄弟 
	bittree parent1=NULL;
	bittree rchild=NULL;
	parent1=parent(t,e);					//得到e的父母结点 
	rchild=rightchild(t,parent1);				//得到父母的左孩子，即左兄弟 
	return rchild;
}

void insertchild(bittree &t,bittree p,int LR,bittree e){				//对二叉树t的p结点进行左/右（0/1）插入结点e，使之成为对应孩子 
	if(LR==0){				//左插入 
		if(p->lchild){
			cout<<"ERROR!left child is existed!"<<endl;
		}
		else{
			p->lchild=e;
		}
	}
	else if(LR==1){			//右插入 
		if(p->rchild){
			cout<<"ERROR!right child is existed!"<<endl;
		}
		else{
			p->rchild=e;
		}		
	}
	else{
		cout<<"ERROR!LR is wrong!"<<endl;
	}
}

void deletechild(bittree &t,bittree e,int LR){			        //对二叉树t中的e结点下的子树进行删除 
	if(LR==0){				//左删除 
		if(!e->lchild){
			cout<<"ERROR!left child is empty!"<<endl;
		}
		else{
			e->lchild=NULL;				//左子结点置空 
		}
	}
	else if(LR==1){			//右删除
		if(!e->rchild){
			cout<<"ERROR!right child is empty!"<<endl;
		}
		else{
			e->rchild=NULL;              //右子结点置空 
		}		
	}
	else{
		cout<<"ERROR!LR is wrong!"<<endl;
	}	
}

void show(bittree t){			       //遍历二叉树并输出结点数据，此处为前序遍历方式 
	if(t){
		cout<<t->data;
		show(t->lchild);
		show(t->rchild);
	}
}
