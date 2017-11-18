#include<iostream>
using namespace std;
const int N = 1e6 + 10; 
int phi[N],prime[N];
int tot;	//表示prime[]中有多少素数 

void Euler(){
	phi[1] = 1;
	for(int i = 2; i < N; i++){
		if(!phi[i]){
			phi[i] = i-1;
			prime[tot++] = i;
		}
		for(int j = 0; j < tot && 1ll * i * prime[j] < N; j++){
			if(i % prime[j])
				phi[i * prime[j]] = phi[i] * (prime[j]-1);
			else{
				phi[i * prime[j] ] = phi[i] * prime[j];
				break;
			}
		}
	}
} 


int main(){
	Euler();
	return 0;
}
