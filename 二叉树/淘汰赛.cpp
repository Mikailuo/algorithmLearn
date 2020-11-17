//题目详情：
 
//有 2^n(n<=7)个国家参加世界杯决赛圈且进入淘汰赛环节。我经知道各个国家的能力值，
//且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者
//晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠
//军。给出各个国家的能力值，请问亚军是哪个国家？

#include<iostream>
#include<cmath>
using namespace std;

typedef struct{							//将队伍编号和实力捆绑为结构体 
	int power;							//队伍的屎蛋都帕瓦！ 
	int id;
}sol;
sol arrange(sol a[],int length);		//安排函数 

int main(void){
	int i=0,n,length;
	sol answer;							//目标的队伍 
	cin>>n;
	length=pow(2,n);					//获得需要队伍总数 
	sol a[length];						//包含队伍关键信息的结构体数组 
	
	for(i=0;i<length;i++){
		a[i].id=i+1;
		cin>>a[i].power;              	//数据结构体化
	}
	answer=arrange(a,length);
	cout<<answer.id;					 
	return 0;
}

sol arrange(sol a[],int length){           //将a[length]视为比赛场，最终a[1]即为决赛的亚军 
	int i,k;
	sol num;
	while(length>=2){					 	//进行下一轮的比赛 
		k=0;
		for(i=0;i<length;i=i+2){					//每两支队伍在一轮中进行比赛，选出一队存到下一轮赛场 
			if(length==2){								//赛场有效长度等于二时说明比赛轮数已达到最后一轮，决战冠亚了 
				if(a[i].power>=a[i+1].power) break;				//此时a[1]就是我们的亚军了 
				else{											//将a[0]与a[1]交换，使得亚军为a[1] 
					num=a[i];
					a[i]=a[i+1];
					a[i+1]=num;
				}	
			}
			else{												//将两队中胜者安排到比赛场编号k处，准备下轮对决 	 
				if(a[i].power>=a[i+1].power) a[k++]=a[i];	
				else a[k++]=a[i+1];								
			}
		}
		length/=2;				//原比赛场折半（一半队伍淘汰了） 
	}
	return a[1];				//角逐出亚军，恭喜SN！！！233 
}



