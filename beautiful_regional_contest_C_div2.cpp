//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1265/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	int mid = n / 2;
	while(v[mid] == v[n / 2])
		mid--;
	if(mid < 3){
		cout<<0<<" "<<0<<" "<<0<<"\n";
		return;
	}
	int g = 0;
	int s = 0;
	int b = 0;
	int i = 0;
	while(i < mid && v[i] == v[i + 1]){
		g++;
		i++;
	}
	g++;
	i++;
	while(s <= g){
		while(i < mid && v[i] == v[i + 1]){
			s++;
			i++;
		}
		s++;
		i++;
	}
	b = mid + 1 - g - s;
	if(g < s && g < b){
		cout<<g<<" "<<s<<" "<<b<<"\n";
	}
	else cout<<0<<" "<<0<<" "<<0<<"\n";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}
