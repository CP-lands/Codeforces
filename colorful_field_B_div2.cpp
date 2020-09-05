//___1 WA == 5 Push up___
#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/79/B
using namespace std;

typedef long long ll; 

int main()
{
	int n, m, k, t, r, l;
	cin>>n>>m>>k>>t;
	vector<int> w;
	vector<int> v(n);
	for(int i = 0; i < k; i++)
	{
		cin>>r>>l;
		w.push_back((r - 1) * m + l);
		v[r - 1]++;
	}
	sort(w.begin(), w.end());
	for(int i = 0; i < t; i++)
	{
		cin>>r>>l;
		int pos = (r - 1) * m + l;
		int it = lower_bound(w.begin(), w.end(), pos) - w.begin();
		if(w[it] == pos) cout<<"Waste"<<endl;
		else
		{
			pos = pos - it;
			if(pos % 3 == 1) cout<<"Carrots"<<endl;
			if(pos % 3 == 2) cout<<"Kiwis"<<endl;
			if(pos % 3 == 0) cout<<"Grapes"<<endl;
		}
	}

	return 0;
}
