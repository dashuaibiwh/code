//���۵���    ��Ԫ 

//(a + b) % p = (a%p + b%p) %p ���ԣ�
//(a - b) % p = (a%p - b%p) %p ���ԣ�
//(a * b) % p = (a%p * b%p) %p ���ԣ�
//(a / b) % p = (a%p / b%p) %p ����


//a^x = 1 (mod) p
//a ���� p ����Ԫ


//��չgcd�������
 
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

ll inv(ll t, ll p) {//��t����p����Ԫ��ע��:tҪС��p����ô���ǰ�Ȱ�t%pһ�� 
    return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p;
}
int main(){
    ll a, p;
    while(~scanf("%lld%lld", &a, &p)){
        printf("%lld\n", inv(a%p, p));
    }
} 
