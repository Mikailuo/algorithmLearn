//#include<iostream>
//#define SIZE 100
//using namespace std;
//
//int bubblesort(int a[],int size); 
//
//int main(void){
//	int a[SIZE];
//	int size,i=0,time=0;
//	cin>>size;
//	for(i=0;i<size;i++){
//		cin>>a[i];
//	}
//	time=bubblesort(a,size);
//	for(i=0;i<size;i++){
//		if(i) cout<<" ";
//		cout<<a[i];
//	}
//	cout<<endl;
//	cout<<time<<endl;	
//	return 0;
//}
//
//int bubblesort(int a[],int size){
//	int i,j,times=0;
//	int key;
//	while(size>1){
//		for(i=0;i<size-1;i++){
//			if(a[i]>a[i+1]){
//				key=a[i];
//				a[i]=a[i+1];
//				a[i+1]=key;
//				times++;
//			}
//		}
//		size--;
//	}
//	return times;
//}


#include<iostream>
#define SIZE 100
using namespace std;
typedef struct{
	int num;
	char word;
}card;
int selectsort(card a[],int size);
int bubblesort(card a[],int size);
void isstable(card a[],card b[],int size);

int main(void){
	card a[SIZE];
	card b[SIZE];
	int size,i=0,time=0;
	cin>>size;
	for(i=0;i<size;i++){
		cin>>a[i].word;
		cin>>a[i].num;
		b[i]=a[i];
	}
	time=selectsort(a,size);
	time=bubblesort(b,size);
	for(i=0;i<size;i++){
		if(i) cout<<" ";
		cout<<b[i].word<<b[i].num;
	}
	cout<<endl;
	isstable(b,b,size);
	
	for(i=0;i<size;i++){
		if(i) cout<<" ";
		cout<<a[i].word<<a[i].num;
	}
	cout<<endl;
	isstable(a,b,size);
	
	return 0;
}
int selectsort(card a[],int size){
	int i,j,pos,times=0;
	card pivot;
	for(i=0;i<size;i++){
		pos=i;
		for(j=i;j<size;j++){
			if(a[pos].num>a[j].num){
				pos=j;
			}
		}
		if(pos!=i){
			pivot=a[i];
			a[i]=a[pos];
			a[pos]=pivot;
			times++;			
		}

	}
	return times;
}

int bubblesort(card a[],int size){
	int i,j,times=0;
	card key;
	while(size>1){
		for(i=0;i<size-1;i++){
			if(a[i].num>a[i+1].num){
				key=a[i];
				a[i]=a[i+1];
				a[i+1]=key;
				times++;
			}
		}
		size--;
	}
	return times;
}

void isstable(card a[],card b[],int size){
	int i,judge=1;
	for(i=0;i<size;i++){
		if(a[i].word!=b[i].word){
			judge=0;
			break;
		}
	}
	if(judge){
		cout<<"Stable"<<endl;
	}
	else{
		cout<<"Not stable"<<endl;
	}
}
