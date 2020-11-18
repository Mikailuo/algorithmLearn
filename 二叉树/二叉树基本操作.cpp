//����ȫ���������Ľ���

#include<iostream>
#define elemtype char
#define SIZE 15
using namespace std;
typedef struct bitnode{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bittree;

bittree init(elemtype c);           //ת��Ŀ������Ϊ��Ӧ�������Ľ�� 
void creat(bittree &t,elemtype a[],int &i,int n);          //�������Ĵ���
bool empty(bittree t);           //�ж��Ƿ�Ϊ����
void treedepth(bittree t,int h,int &depth);     //ǰ�������������� 
int depth(bittree t);				//�������
bittree leftchild(bittree t,bittree e);      //��t��eָ��ָ��Ľ�������
bittree rightchild(bittree t,bittree e);      //��t��eָ��ָ��Ľ����Һ��� 
bittree getlocal(bittree t,elemtype a);        //�õ�����a�Ľ��λ��
void treegetlocal(bittree t,elemtype a,bittree &p);        //�����������������ڶ�Ӧ��a���޸����е�p 
bittree parent(bittree t,bittree e);		//e��ָ���ĸ�ĸ  
void treeparent(bittree t,bittree e,bittree &p); 		     //�ݹ����㸸ĸ 
bittree leftsibling(bittree t,bittree e);       //e��ָ�������ֵ�
bittree rightsibling(bittree t,bittree e);      ///e��ָ�������ֵ� 
void insertchild(bittree &t,bittree p,int LR,bittree e);      			//�Զ�����t��p��������/�ң�0/1��������e��ʹ֮��Ϊ��Ӧ���� 
void deletechild(bittree &t,bittree e,int LR);                  //�Զ�����t�е�e����µ���������ɾ�� 
void show(bittree t);           //���������������������� 
 
int main(void){
	elemtype a[SIZE]={'1','2','3','#','4','#','#','5','#','#','6','#','7','#','#'};			//����ǰ����ʽ��ֵ����Ϊ��ȫ������ֻ����˳������ת������ 
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
	insertchild(tree,goal,0,input);    //��ȷ���� 
	goal=getlocal(tree,'6'); 
	insertchild(tree,goal,1,input);     //�ᱨ����Ϊ6���Һ��� 
	show(tree);
	
	return 0;
}

bittree init(elemtype c){					//ת��Ŀ������Ϊ��Ӧ�������Ľ�� 
	bittree t;
	t=new bitnode;
	t->data=c;
	t->lchild=NULL;
	t->rchild=NULL;
}

void creat(bittree &t,elemtype a[],int &i,int n){			//�������ĵݹ鴴��
cout<<a[i];
	if(i<n){							//i=nʱ˵���ѵ���������ĩ�ˣ�û����������������� 
		if(a[i]=='#') {t=NULL; i++;}				//��ʱ˵����һ�ڵ��λ�ô��޺���,i+1; 
		else{
			t=new bitnode;
			t->data=a[i++];
			creat(t->lchild,a,i,n);            //��������ÿһ��֧,ͬʱi+1 
			creat(t->rchild,a,i,n);
		}
	}
}

bool empty(bittree t){				  //�ж��Ƿ�Ϊ����
	if(t==NULL) return true;
	else return false;
}

void treedepth(bittree t,int h,int &depth){				//�ݹ飬ǰ�������������� 
	if(t){
		if(h>depth) depth=h;
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
	}
	return depth;
}
	
bittree leftchild(bittree t,bittree e){				   //��t��eָ��ָ��Ľ�������
	bittree p;
	p=e->lchild;
	return p; 
} 

bittree rightchild(bittree t,bittree e){				   //��t��eָ��ָ��Ľ����Һ���
	bittree p;
	p=e->rchild;
	return p; 
} 

bittree getlocal(bittree t,elemtype a){			    //�õ�����a�Ľ��λ��
	bittree p=NULL;
	treegetlocal(t,a,p);
	return p;
}

void treegetlocal(bittree t,elemtype a,bittree &p){
	if(t){
		if(t->data==a){
			p=t;								//ֵ��ע����ǣ������p��ʾ�ı������к����һ����a��ȵĽ��λ�� 
		}
		else{
			treegetlocal(t->lchild,a,p); 			//���ϵݹ�������� 
			treegetlocal(t->rchild,a,p);			
		}
	}
}

bittree parent(bittree t,bittree e){				//e��ָ���ĸ�ĸ  
	bittree p=NULL;
	treeparent(t,e,p);
	return p;
}

void treeparent(bittree t,bittree e,bittree &p){      //�ݹ����㸸ĸ 
	if(t){
		if(t->lchild==e||t->rchild==e){					//����ͬ��һ��������һ��ȡ���һ������ַ 
			p=t;
		}
		else{
			treeparent(t->lchild,e,p);
			treeparent(t->rchild,e,p);
		}
	}
}

bittree leftsibling(bittree t,bittree e){	     //e��ָ�������ֵ�
	bittree parent1=NULL;
	bittree lchild=NULL;
	parent1=parent(t,e);					//�õ�e�ĸ�ĸ��� 
	lchild=leftchild(t,parent1);				//�õ���ĸ�����ӣ������ֵ� 
	return lchild;
}

bittree rightsibling(bittree t,bittree e){	 		//e��ָ�������ֵ� 
	bittree parent1=NULL;
	bittree rchild=NULL;
	parent1=parent(t,e);					//�õ�e�ĸ�ĸ��� 
	rchild=rightchild(t,parent1);				//�õ���ĸ�����ӣ������ֵ� 
	return rchild;
}

void insertchild(bittree &t,bittree p,int LR,bittree e){				//�Զ�����t��p��������/�ң�0/1��������e��ʹ֮��Ϊ��Ӧ���� 
	if(LR==0){				//����� 
		if(p->lchild){
			cout<<"ERROR!left child is existed!"<<endl;
		}
		else{
			p->lchild=e;
		}
	}
	else if(LR==1){			//�Ҳ��� 
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

void deletechild(bittree &t,bittree e,int LR){			        //�Զ�����t�е�e����µ���������ɾ�� 
	if(LR==0){				//��ɾ�� 
		if(!e->lchild){
			cout<<"ERROR!left child is empty!"<<endl;
		}
		else{
			e->lchild=NULL;				//���ӽ���ÿ� 
		}
	}
	else if(LR==1){			//��ɾ��
		if(!e->rchild){
			cout<<"ERROR!right child is empty!"<<endl;
		}
		else{
			e->rchild=NULL;              //���ӽ���ÿ� 
		}		
	}
	else{
		cout<<"ERROR!LR is wrong!"<<endl;
	}	
}

void show(bittree t){			       //���������������������ݣ��˴�Ϊǰ�������ʽ 
	if(t){
		cout<<t->data;
		show(t->lchild);
		show(t->rchild);
	}
}
