//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1256/C
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, m, d;
	cin>>n>>m>>d;
	vector<int> l(m), res(n);
	int sum = 0;
	for(int i = 0; i < m; i++){
		cin>>l[i];
		sum += l[i];
	}
	if((d - 1) * (m + 1) < n - sum){
		cout<<"NO"<<endl;
		return;
	}
	int blank = n - sum;
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < n){
		
		int tmp;
		if(blank > 0){
			tmp = min(blank + 1, d) - 1;
			blank -= tmp;
			while(tmp--){
				res[i++] = 0;
			}
		}
		if(i < n){
			tmp = l[k];
			while(tmp--){
				res[i++] = j + 1;
			}
		}
		j++;
		k++;
	}

	cout<<"YES"<<endl;
	for(i = 0; i < n; i++)
		cout<<res[i]<<" ";
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
