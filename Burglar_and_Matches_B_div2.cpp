#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int tmp = 0;
	int res = 0;
	vector<vector<int>> v(m, vector<int> (2));
	for(int i = 0; i < m; i++)
		cin>>v[i][1]>>v[i][0];
	sort(v.begin(), v.end());
	for(int i = m - 1; i >= 0; i--)
	{
		res = res + v[i][0] * min(n - tmp, v[i][1]);
		tmp = tmp + min(n - tmp, v[i][1]);
		if(n - tmp <= 0)
			break;
	}
	cout<<res<<endl;
	return 0;	 
}