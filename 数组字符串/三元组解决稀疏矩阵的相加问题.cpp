#include <iostream>
#include <algorithm>
#define SIZE 25
using namespace std;
typedef struct{
	int row,col;
	int num;
}triple;
typedef struct{
	triple data[SIZE];
	int mu,nu,tu;
}tsmatrix;

void creat(tsmatrix &t,int a[][5],int row);
void show(tsmatrix t);
void add(tsmatrix t1,tsmatrix t2,tsmatrix &t3);
void axissort(tsmatrix &t,int key);
void axispass(tsmatrix &t,int key);

int main(void){
	int a[5][5]={{0,0,1,0,2},
				 {1,0,2,6,0},
				 {0,0,0,0,1},
				 {0,0,0,0,0},
				 {0,1,0,0,0},
				};
	int b[5][5]={{1,0,0,0,1},
				 {0,0,2,0,3},
				 {0,0,0,0,0},
				 {1,2,1,1,1},
				 {0,0,0,0,1},
				};
	tsmatrix t1,t2,t3;
	creat(t1,a,5);
	creat(t2,b,5);
	show(t1);show(t2);
	add(t1,t2,t3);
	show(t3);
	axissort(t3,1);                     //���ǻ������򣬵�Ȼ����Ҳ���Դӹ鲢�������� 
	show(t3);		
	return 0;
}
void creat(tsmatrix &t,int a[][5],int row){
	int i,j,k=0;
	for(i=0;i<row;i++){
		for(j=0;j<5;j++){
			if(a[i][j]!=0){
				t.data[k].row=i;
				t.data[k].col=j;
				t.data[k].num=a[i][j];
				k++;
			}
		}
	}
	t.mu=i+1;					//�ѳ�ѭ����i,j��Ϊ����������� 
	t.nu=j+1;
	t.tu=k;     				//���һ���Ѿ���k++�� 
}

void show(tsmatrix t){
	int i;
	cout<<"��Ԫ�飺"<<endl;
	for(i=0;i<t.tu;i++){
		cout<<"	("<<t.data[i].num<<" "<<t.data[i].row<<" "<<t.data[i].col<<")"<<endl;
	}
}

void add(tsmatrix t1,tsmatrix t2,tsmatrix &t3){
	int i,j,k=0;
	t3=t2;
	for(i=0;i<t1.tu;i++){
		k=0;
		for(j=0;j<t2.tu;j++){
			if(t1.data[i].col==t2.data[j].col&&t1.data[i].row==t2.data[j].row){
				t3.data[j].num+=t1.data[i].num;
				k=1;
			}
		}
		if(k==0){
			t3.data[t3.tu++]=t1.data[i];
		}
	}
}
void axissort(tsmatrix &t,int key){							//�ؼ��ֵ�λ�� 
	while(key>-1){
		axispass(t,key);
		key--;
	}
}
void axispass(tsmatrix &t,int key){						//�������� 
	int i=0,j=0;
	tsmatrix another=t;
	int count[t.tu]={0};
	if(key==1){ 						                //key=1,��ʱ��row�������ȣ��������� 
		while(i<t.tu) count[t.data[i++].row]++; 		//count�ռ����� 
		while(j<t.tu-1) count[j+1]+=count[j++]; 	//count�ۼ�
		for(i=t.tu-1;i>=0;i--){		                //��� 
			t.data[count[another.data[i].row]]=another.data[i];
			count[another.data[i].row]--;
		}
	}
	if(key==0){ 						                //key=1,��ʱ��row�������ȣ��������� 
		while(i<t.tu) count[t.data[i++].col]++; 		//count�ռ����� 
		while(j<t.tu-1) count[j+1]+=count[j++]; 	//count�ۼ�
		for(i=t.tu-1;i>=0;i--){		                //��� 
			t.data[count[another.data[i].col]]=another.data[i];
			count[another.data[i].col]--;
		}
	}
}
