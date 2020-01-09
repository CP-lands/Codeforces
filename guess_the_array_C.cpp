//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/727/problem/C
#include<bits/stdc++.h>
 
//this is an interactive problem, if u want to use fflush(stdout), u should turn off ios_base...
//otherwise, u should use endl instead

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n + 1);
	int sum12, sum23, sum13;
	cout<<"? "<<1<<" "<<2<<"\n";
	fflush(stdout);
	cin>>sum12;
	cout<<"? "<<2<<" "<<3<<endl;
	cin>>sum23;
	cout<<"? "<<1<<" "<<3<<endl;
	cin>>sum13;
	v[1] = (sum12 - sum23 + sum13) / 2;
	v[2] = sum12 - v[1];
	v[3] = sum13 - v[1];
	for(int i = 3; i < n; i++){
		int sum;
		cout<<"? "<<i<<" "<<i + 1<<endl;
		cin>>sum;
		v[i + 1] = sum - v[i];
	}
	cout<<"! ";
	for(int i = 1; i <= n; i++)
		cout<<v[i]<<" ";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}