#define elem char
typedef struct bithrnode{
	elem data;
	struct bithrnode *lchild,rchild;         //左孩子，右孩子 
	struct bithrnode *pred,*succ;				//pred前驱，succ后继 
}bithrnode,*bithrtree;

bithrtree tree2thr(bittree t){				//二叉树的线索格式化 
	bithrtree answer;
	if(!t){
		answer->data=t.data;
		answer->lchild=t.lchild;
		answer->rchild=t.rchild;
		answer->pred=NULL;
		answer->succ=NULL;	
	}
	else answer=NULL;
	return answer;
}

void inorderthreading(bithrtree &h,bittree t){
	bithrtree pre,t1;	
	t1=tree2thr;  			//线索格式化二叉树t 
	h=new bithrnode;			//创造线索树的头结点 
	h->lchild=t;
	h->rchild=NULL;
	if(!t1){					//空树时，线索树的头结点前驱后继都指向本身 
		h->pred=h;
		h->succ=h;
	}
	else{
		pre=h;
		inthreading(t,pre);         //对t进行中序遍历，在遍历的同时进行线索化 
		pre->succ=h;
		h->pred=pre;
	}
}


void inthreading(bithrtree p,bithrtree &pre){
	//中序遍历的套路 
	if(p){
		inthreading(p->lchild,pre);
		pre->succ=p; 		//注意区分一个是树的左右孩子，一个是线索树（链表）中的前驱后继 
		p->pred=pre;
		pre=p;
		inthreading(p->rchild,pre);
	}
}

void show(bithrtree t){
	bithrtree head=t;
	bithrtree p=t->succ;
	while(p!=head){
		cout<<p.data<<" ";
		p=p->succ;
	}
}
