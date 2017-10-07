//筛法  o(n)
#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;

const int N=100000 + 5;
bool prime[N];
int p[N],tot;//p数组用来存质数


//基本筛法 
void init(){
	for(int i=2;i<N;i++){
		prime[i]=true;
	}
	for(int i=2;i<N;i++){
		if(prime[i])
			p[tot++] = i;
		for(int j=0;j<tot && i*p[j]<N; j++){
			prime[i*p[j]]=false;
			if(i%p[j] == 0)
				break;
		}	
	} 
}
/*筛法的应用*/ 

//预处理每个数的所有质因数
vector<int> prime_factor[N];
void init1(){
	for(int i = 2; i < N; i++){
		if(prime_factor[i].size() == 0){
			for(int j = i; j < N; j += i){
				prime_factor[j].push_back(i);
			}
		}
	}
} 

//预处理每个数的所有因数 
vector<int> factor[N];
void init2(){
	for(int i = 2; i < N; i++){
		for(int j = i; j < N; j += i){
			factor[j].push_back(i);
		}
	}
}

//预处理每个数的质因数分解
vector<int> factor_prime[N];
void init3(){
	int temp;
	for(int i = 2; i < N; i++){
		if(factor_prime[i].size() == 0){
			for(int j = i; j < N; j+=i){
				temp=j;
				while(temp % i == 0){
					factor_prime[j].push_back(i);
					temp /= i;
				}
			}
		}
	}
} 

int main(){
	init(); 
/*	每个数的质因数 
	init1();
	for(int i=2;i<N;i++){
		for(int j=0;j<prime_factor[i].size();j++){
			cout<<prime_factor[i][j]<<" ";
		}
		cout<<endl;
	}
*/
/*每个数的因数 
	init2();
		for(int i=2;i<N;i++){
		for(int j=0;j<factor[i].size();j++){
			cout<<factor[i][j]<<" ";
		}
		cout<<endl;
	}
*/
/*每个数的质因数分解 
	init3();
	for(int i=2;i<N;i++){
		for(int j=0;j<factor_prime[i].size();j++){
			cout<<factor_prime[i][j]<<" ";
		}
		cout<<endl;
	}
*/	
 
	return 0;
} 
