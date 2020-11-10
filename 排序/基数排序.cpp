#include<iostream>
#define SIZE 10					//SIZE为数据集的个数 
#define keynum 10 				//keynum为某位关键字的总个数  

using namespace std;
typedef struct{
	int num;					//数据 
	int bitsum;                 //关键字位数 
	int key[SIZE];                  //关键字数组 
}data;

//采用LSD标准 
void radixpass(data a[],data b[],int size,int i);      //sr[i..m]和sr[m+1..n]有序表归并到tr[i..n] 
void radixsort(data a[]);     //对sr归并保存在tr1，范围为s..t 

int main(void){
	int a[SIZE]={32,25,13,31,57,10,46,98,54,66};
	data answer[SIZE]={0};
	int i=0,j=0,bit=2,factor;
	//初始化目标表 
	for(i=0;i<SIZE;i++){
		answer[i].num=a[i];
		answer[i].bitsum=bit;
		factor=answer[i].num;
		for(j=bit-1;j>=0;j--){   		//将数据中每一位关键字（这里值十进制位数）存入关键字数组 
			answer[i].key[j]=factor%10;
			factor=factor/10;
		}	
	}
	//进行基数排序 
	radixsort(answer);
	//输出 
	for(i=0;i<SIZE;i++){
		cout<<answer[i].num<<" ";
	}
	cout<<endl;
	return 0;
}

void radixsort(data a[]){
	int i,j;
	data c[SIZE]; 					//结果数组 
	i=a[0].bitsum;
	while(i>=1){
		radixpass(a,c,SIZE,i-1);      //对第i位关键字做基数排序,结果保存至数组C中 
		i--;						  //进行下一轮基数排序 
		if(i>=1){
		radixpass(c,a,SIZE,i-1);	  //减少时间消耗，继续对下一位做基数排序，反过来把结果保存在数组a中 
		i--;
		}
		else{
			for(j=0;j<SIZE;j++) a[j]=c[j];       //此时说明最后一次基数排序结果存在c中，故再做一次拷贝赋值给a 
		} 
	}
}

void radixpass(data a[],data b[],int size,int i){
	//将每个数据按第i位关键字统计分布情况，用count来存取
	//累加count，使其转化为表征小于等于第i位关键字的数据个数
	//利用新count，把a填入b中，这样一轮操作即可保证在第i位关键字上数据相对有序 
	int j,k;
	int count[keynum]={0}; 			//记录数组，用来记录某个关键字的分布情况
	for(j=0;j<SIZE;j++) count[a[j].key[i]]++;        //保存数据集在i位关键字的分布情况 
	for (k=0;k<keynum;k++) count[k]=count[k-1]+count[k];         //累加count
	//按count顺序填表 
	for(k=SIZE-1;k>=0;k--){	   //倒序的目的，在前i-1位中已经基本有序（从小到大）了，这时如果采用顺序会使i位关键字同级之间顺序逆序 
		j=a[k].key[i];				//获取a[k]在第i位的关键字 为j 
		b[count[j]-1]=a[k];			//将count[j]-1（a中所有数据i位关键字小于等于a[k]的索引最大值）作为a[k]数据的新位置 
		count[j]--;					//填了一个，自然下一次填入时要减少一个萝卜坑 
	}
}

