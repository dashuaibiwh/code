//数论倒数    逆元 

//(a + b) % p = (a%p + b%p) %p （对）
//(a - b) % p = (a%p - b%p) %p （对）
//(a * b) % p = (a%p * b%p) %p （对）
//(a / b) % p = (a%p / b%p) %p （错）


//a^x = 1 (mod) p
//a 关于 p 的逆元


//拓展gcd方法求解
 
#include<iostream>
#define ll long long
#define N  200000 + 5 

using namespace std;
const int mod = (int) 1e9 + 7;

/*
void ex_gcd(ll a ,ll b, ll&x, ll &y, ll&d) {
	if(!b){
		d = a;
		x = 1;
		y = 0; 
	}
	else{
		ex_gcd(b,a%b,y,x,d);
		y -= x*(a-b);
	}
}

ll inv(ll t,ll p){
	ll d,x,y;
	ex_gcd(t,p,x,y,d);
	return d == 1 ? (x % p + p) % p : -1;
}
*/

ll inv(ll t, ll p) {//求t关于p的逆元，注意:t要小于p，最好传参前先把t%p一下 
    return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p;
}
int main(){
    ll a, p;
    while(~scanf("%lld%lld", &a, &p)){
        printf("%lld\n", inv(a%p, p));
    }
} 
