#include<iostream>
using namespace std;

void merge(int sr[],int tr[],int i,int m,int n);      //sr[i..m]��sr[m+1..n]�����鲢��tr[i..n] 
void msort(int sr[],int tr1[],int s,int t);     //��sr�鲢������tr1����ΧΪs..t 

int main(void){
	int a[10]={2,5,3,1,7,10,4,8,4,6};
	int answer[10];
	int i=0;
	msort(a,a,0,9);
	return 0;
}

void msort(int sr[],int tr1[],int s,int t){
	int tr2[t-s+1];
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
	for(j=i,k=m+1;i<=m,k<=n;j++){ 			//important,���������ţ����������ݰ���˳�������� 
		if(sr[i]>sr[k]) tr[j]=sr[k++];		//tr[]������ 
		else tr[j]=sr[i++];
	}
	while(i<=m) tr[j++]=sr[i++];            //ʣ��ĸ���ճ����tr�� 
	while(k<=n) tr[j++]=sr[k++];			//ͬ��
}

