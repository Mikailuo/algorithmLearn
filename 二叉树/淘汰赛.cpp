//��Ŀ���飺
 
//�� 2^n(n<=7)�����Ҳμ����籭����Ȧ�ҽ�����̭�����ڡ��Ҿ�֪���������ҵ�����ֵ��
//�Ҷ�����ȡ�����ֵ�ߵĹ��Һ�����ֵ�͵Ĺ����߱���ʱ���߻�ʤ��1 �Ź��Һ� 2 �Ź�����һ��������ʤ��
//������3 �Ź��Һ� 4 �Ź���Ҳ��һ����ʤ�߽�������������Ĺ�������ͬ�ķ�������������̣�ֱ��������
//���������������ҵ�����ֵ�������Ǿ����ĸ����ң�

#include<iostream>
#include<cmath>
using namespace std;

typedef struct{							//�������ź�ʵ������Ϊ�ṹ�� 
	int power;							//�����ʺ�������ߣ� 
	int id;
}sol;
sol arrange(sol a[],int length);		//���ź��� 

int main(void){
	int i=0,n,length;
	sol answer;							//Ŀ��Ķ��� 
	cin>>n;
	length=pow(2,n);					//�����Ҫ�������� 
	sol a[length];						//��������ؼ���Ϣ�Ľṹ������ 
	
	for(i=0;i<length;i++){
		a[i].id=i+1;
		cin>>a[i].power;              	//���ݽṹ�廯
	}
	answer=arrange(a,length);
	cout<<answer.id;					 
	return 0;
}

sol arrange(sol a[],int length){           //��a[length]��Ϊ������������a[1]��Ϊ�������Ǿ� 
	int i,k;
	sol num;
	while(length>=2){					 	//������һ�ֵı��� 
		k=0;
		for(i=0;i<length;i=i+2){					//ÿ��֧������һ���н��б�����ѡ��һ�Ӵ浽��һ������ 
			if(length==2){								//������Ч���ȵ��ڶ�ʱ˵�����������Ѵﵽ���һ�֣���ս������ 
				if(a[i].power>=a[i+1].power) break;				//��ʱa[1]�������ǵ��Ǿ��� 
				else{											//��a[0]��a[1]������ʹ���Ǿ�Ϊa[1] 
					num=a[i];
					a[i]=a[i+1];
					a[i+1]=num;
				}	
			}
			else{												//��������ʤ�߰��ŵ����������k����׼�����ֶԾ� 	 
				if(a[i].power>=a[i+1].power) a[k++]=a[i];	
				else a[k++]=a[i+1];								
			}
		}
		length/=2;				//ԭ�������۰루һ�������̭�ˣ� 
	}
	return a[1];				//������Ǿ�����ϲSN������233 
}



