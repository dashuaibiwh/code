#include<vector>
#include<iostream>
using namespace std;

int main(){
	vector <int> a;
	int b;
	for(int i=0;i<5;i++){
		cin>>b;
		a.push_back(b);
	}
	
	cout<<a[a.size()-1]<<endl;
	cout<<a.size()<<' '<<a.capacity()<<endl;
	
	a.pop_back();
	cout<<a[a.size()-1]<<endl;
	cout<<a.size()<<' '<<a.capacity()<<endl;
	return 0;
} 
