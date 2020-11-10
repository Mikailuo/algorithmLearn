#include<iostream>
#define SIZE 10
using namespace std;

void merge(int sr[],int tr[],int i,int m,int n);      //sr[i..m]��sr[m+1..n]�����鲢��tr[i..n] 
void msort(int sr[],int tr1[],int s,int t);     //��sr�鲢������tr1����ΧΪs..t 

int main(void){
	int a[SIZE]={2,5,3,1,7,10,4,8,4,6};
	int answer[SIZE]={0};
	int i=0;
	msort(a,answer,0,9);
	for(i=0;i<SIZE;i++){
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void msort(int sr[],int tr1[],int s,int t){
	//int tr2[t-s+1]          �������������⣬��������ͻᵼ����һ�ֵ�tr1�߶ȹ�С���޷�ʵ��tr1[s]=sr[s]��һ�� 
	int tr2[SIZE];
	int m;
	if(s==t) tr1[s]=sr[s];
	else{
		m=(t+s)/2;
		msort(sr,tr2,s,m);         //��sr[s..m]���й鲢������tr2[s..m]��� 
		msort(sr,tr2,m+1,t);	   //��sr[m+1,t]���й鲢������tr2[m+1..t]��� 
		merge(tr2,tr1,s,m,t);	   //��tr2[s..m]&tr2[m+1..t]������鲢��ϣ�����tr1�� 
	}
}

void merge(int sr[],int tr[],int i,int m,int n){
	int j,k;
	for(j=i,k=m+1;i<=m&&k<=n;j++){ 			//important,���������ţ����������ݰ���˳�������� 
		if(sr[i]>sr[k]) tr[j]=sr[k++];		//tr[]������ 
		else tr[j]=sr[i++];
	}
	while(i<=m) tr[j++]=sr[i++];            //ʣ��ĸ���ճ����tr�� 
	while(k<=n) tr[j++]=sr[k++];			//ͬ��
}
 

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//#define LQ(a,b) (a<=b)
//void merge(int sr[],int tr[],int i,int m,int n);
////typedef int (*PARR)[6];
////int tr2[6] = {0};
//
////void merge(int sr[],int tr[],int i,int m,int n)
////{
////    int k = 0,j = 0;
////    for(j = m + 1,k = i;i<=m&&j<=n;++k)
////    {
////        if(LQ(sr[i],sr[j]))
////        tr[k] = sr[i++];
////        else 
////        tr[k] = sr[j++];
////    }
////    while(i<=m)
////        tr[k++] = sr[i++];
////    while(j<=n)
////        tr[k++] = sr[j++];
//////    if(i<=m) 
//////        memmove(tr+k,sr+i,m-i+1);
//////    if(j<=n)
//////        memmove(tr+k,sr+j,n-j+1);
////}
//void msort(int sr[],int tr[],int s,int t)
//{
//    //int* tr2 = (int*)malloc(6*sizeof(int));
//    int tr2[t-s+1] = {0};
//    int m = 0;
//    if(s==t) 
//        tr[s] = sr[s];
//        //return;
//    else
//    {
//        m = (s+t)/2;
//        msort(sr,tr2,s,m);
//        msort(sr,tr2,m+1,t);
//        merge(tr2,tr,s,m,t);
//    }
//}
//
//int main(void)
//{
//    int i = 0;
//
//	int a[9]={2,5,3,1,7,10,8,4,6};
//	int answer[9]={0};
//    msort(a,answer,0,8);
//    /*msort(arr,arr,0,5);����������Ҳ��OK��*/
//    for(int i = 0;i<9;i++)
//    {
//        printf("%2d ",answer[i]);
//    }
////    free(tmpArr);
//    getchar();
//    return 0;
//}
//
//void merge(int sr[],int tr[],int i,int m,int n){
//	int j,k;
//	for(j=i,k=m+1;i<=m&&k<=n;j++){ 			//important,���������ţ����������ݰ���˳�������� 
//		if(sr[i]>sr[k]) tr[j]=sr[k++];		//tr[]������ 
//		else tr[j]=sr[i++];
//	}
//	while(i<=m) tr[j++]=sr[i++];            //ʣ��ĸ���ճ����tr�� 
//	while(k<=n) tr[j++]=sr[k++];			//ͬ��
//}
// 
