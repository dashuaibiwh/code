#include<iostream>
using namespace std;

#define LL long long

/*
//大数pow函数的精准 
LL pow_mod(LL a,LL b){
	if( b == 0)
		return 1;
	LL res = pow_mod(a,b/2);
	res = res * res % MOD;
	if(b%2==1)
		res = res * a % MOD;	
		
	return res; 
}
*/
//大数pow函数的精准
LL pow_mod(LL a,LL b,LL p){
	LL res = 1;
	while(b){
		if( b & 1){			//(b%2==1)
			res = (res * a) % p;
		}
		a = (a * a) % p;
		b >>= 1;   			//(b/=2)
	}
	return res;	
} //合并再做乘法、 a ^ b % p 

// 快速乘
LL mul(LL a,LL b, LL p){
	LL ret = 0;
	while(b){
		if(b & 1)
			ret = (ret + a) % p;
			a = (a + a) % p;
			b >>= 1;
	}
	return ret;
}	//快速乘  a * b % p 


int main(){
	LL a,b,p;
	cin>>a>>b>>p;
	cout<<pow_mod(a,b,p)<<endl;
	
	cout<<mul(a,b,p)<<endl; 
	
	
	return 0;
} 
