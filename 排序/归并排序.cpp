#include<iostream>
using namespace std;

void merge(int sr[],int tr[],int i,int m,int n);      //sr[i..m]和sr[m+1..n]有序表归并到tr[i..n] 
void msort(int sr[],int tr1[],int s,int t);     //对sr归并保存在tr1，范围为s..t 

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
		msort(sr,tr2,s,m);         //对sr[s..m]进行归并排序，以tr2[s..m]输出 
		msort(sr,tr2,m+1,t);	   //对sr[m+1,t]进行归并排序，以tr2[m+1..t]输出 
		merge(tr2,tr1,s,m,t);	   //将tr2[s..m]&tr2[m+1..t]有序组归并组合，保存tr1中 
	}
}

void merge(int sr[],int tr[],int i,int m,int n){
	int j,k;
	for(j=i,k=m+1;i<=m,k<=n;j++){ 			//important,有序表的重排，对其中数据按照顺序重新在 
		if(sr[i]>sr[k]) tr[j]=sr[k++];		//tr[]中排序 
		else tr[j]=sr[i++];
	}
	while(i<=m) tr[j++]=sr[i++];            //剩余的复制粘贴到tr中 
	while(k<=n) tr[j++]=sr[k++];			//同理
}

