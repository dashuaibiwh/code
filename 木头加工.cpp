#include<iostream>
#include<algorithm>
using namespace std;
struct wooden{
	int l;		//长度 
	int w;		//重量 
};

bool cmp(wooden a,wooden b){
	if(a.l!=b.l)
		return a.l>b.l;
	else
		return a.w>b.w;
} 

wooden wood[5005];
int flag[5005];

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>wood[i].l>>wood[i].w;
			flag[i]=0;
		}									//输入木棒的长度和重量 
		sort(wood,wood+n,cmp);
		int count=0;
		int min;
		for(int i=0;i<n;i++){
			if(flag[i])
				continue;
			min=wood[i].w;
			for(int j=i+1;j<n;j++){
				if(min>=wood[j].w&&!flag[j]){
					min=wood[j].w;
					flag[j]=1;
				}
			}
			count++;
		}
		cout<<count<<endl;
		
	}
	
	return 0;
}
