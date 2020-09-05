#include<iostream>
#include<queue>

using namespace std;

int main(){
	int n,k1,k2,tmp;
	int count = 0;
	cin>>n;
	queue<int> a,b;
	cin>>k1;
	for(int i = 0; i < k1; i++){
		cin>>tmp;
		a.push(tmp);
	}
	cin>>k2;
	for(int i = 0; i < k2; i++){
		cin>>tmp;
		b.push(tmp);
	}
	while(!a.empty() && !b.empty()){
		count++;
		if(count == 1000){
			cout<<-1<<endl;
			return 0;
		}
		int a_temp = a.front();
		a.pop();
		int b_temp = b.front();
		b.pop();
		if(a_temp > b_temp){
			a.push(b_temp);
			a.push(a_temp);
		}
		else{
			b.push(a_temp);
			b.push(b_temp);
		}
	}
	if(a.empty())
		cout<<count<<" "<<2<<endl;
	if(b.empty())
		cout<<count<<" "<<1<<endl;
	return 0;
}
