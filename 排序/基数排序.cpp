#include<iostream>
#define SIZE 10					//SIZEΪ���ݼ��ĸ��� 
#define keynum 10 				//keynumΪĳλ�ؼ��ֵ��ܸ���  

using namespace std;
typedef struct{
	int num;					//���� 
	int bitsum;                 //�ؼ���λ�� 
	int key[SIZE];                  //�ؼ������� 
}data;

//����LSD��׼ 
void radixpass(data a[],data b[],int size,int i);      //sr[i..m]��sr[m+1..n]�����鲢��tr[i..n] 
void radixsort(data a[]);     //��sr�鲢������tr1����ΧΪs..t 

int main(void){
	int a[SIZE]={32,25,13,31,57,10,46,98,54,66};
	data answer[SIZE]={0};
	int i=0,j=0,bit=2,factor;
	//��ʼ��Ŀ��� 
	for(i=0;i<SIZE;i++){
		answer[i].num=a[i];
		answer[i].bitsum=bit;
		factor=answer[i].num;
		for(j=bit-1;j>=0;j--){   		//��������ÿһλ�ؼ��֣�����ֵʮ����λ��������ؼ������� 
			answer[i].key[j]=factor%10;
			factor=factor/10;
		}	
	}
	//���л������� 
	radixsort(answer);
	//��� 
	for(i=0;i<SIZE;i++){
		cout<<answer[i].num<<" ";
	}
	cout<<endl;
	return 0;
}

void radixsort(data a[]){
	int i,j;
	data c[SIZE]; 					//������� 
	i=a[0].bitsum;
	while(i>=1){
		radixpass(a,c,SIZE,i-1);      //�Ե�iλ�ؼ�������������,�������������C�� 
		i--;						  //������һ�ֻ������� 
		if(i>=1){
		radixpass(c,a,SIZE,i-1);	  //����ʱ�����ģ���������һλ���������򣬷������ѽ������������a�� 
		i--;
		}
		else{
			for(j=0;j<SIZE;j++) a[j]=c[j];       //��ʱ˵�����һ�λ�������������c�У�������һ�ο�����ֵ��a 
		} 
	}
}

void radixpass(data a[],data b[],int size,int i){
	//��ÿ�����ݰ���iλ�ؼ���ͳ�Ʒֲ��������count����ȡ
	//�ۼ�count��ʹ��ת��Ϊ����С�ڵ��ڵ�iλ�ؼ��ֵ����ݸ���
	//������count����a����b�У�����һ�ֲ������ɱ�֤�ڵ�iλ�ؼ���������������� 
	int j,k;
	int count[keynum]={0}; 			//��¼���飬������¼ĳ���ؼ��ֵķֲ����
	for(j=0;j<SIZE;j++) count[a[j].key[i]]++;        //�������ݼ���iλ�ؼ��ֵķֲ���� 
	for (k=0;k<keynum;k++) count[k]=count[k-1]+count[k];         //�ۼ�count
	//��count˳����� 
	for(k=SIZE-1;k>=0;k--){	   //�����Ŀ�ģ���ǰi-1λ���Ѿ��������򣨴�С�����ˣ���ʱ�������˳���ʹiλ�ؼ���ͬ��֮��˳������ 
		j=a[k].key[i];				//��ȡa[k]�ڵ�iλ�Ĺؼ��� Ϊj 
		b[count[j]-1]=a[k];			//��count[j]-1��a����������iλ�ؼ���С�ڵ���a[k]���������ֵ����Ϊa[k]���ݵ���λ�� 
		count[j]--;					//����һ������Ȼ��һ������ʱҪ����һ���ܲ��� 
	}
}

