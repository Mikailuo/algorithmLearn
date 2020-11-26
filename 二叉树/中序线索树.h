#define elem char
typedef struct bithrnode{
	elem data;
	struct bithrnode *lchild,rchild;         //���ӣ��Һ��� 
	struct bithrnode *pred,*succ;				//predǰ����succ��� 
}bithrnode,*bithrtree;

bithrtree tree2thr(bittree t){				//��������������ʽ�� 
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
	t1=tree2thr;  			//������ʽ��������t 
	h=new bithrnode;			//������������ͷ��� 
	h->lchild=t;
	h->rchild=NULL;
	if(!t1){					//����ʱ����������ͷ���ǰ����̶�ָ���� 
		h->pred=h;
		h->succ=h;
	}
	else{
		pre=h;
		inthreading(t,pre);         //��t��������������ڱ�����ͬʱ���������� 
		pre->succ=h;
		h->pred=pre;
	}
}


void inthreading(bithrtree p,bithrtree &pre){
	//�����������· 
	if(p){
		inthreading(p->lchild,pre);
		pre->succ=p; 		//ע������һ�����������Һ��ӣ�һ�����������������е�ǰ����� 
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
