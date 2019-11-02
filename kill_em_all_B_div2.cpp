#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int q;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		int n, r, tmp;
		cin>>n>>r;
		set<int> res;
		int count = 0;
		for(int j = 0; j < n; j++)
		{
			cin>>tmp;
			res.insert(tmp);
		}
		while(!res.empty())
		{
			count++;
			tmp = *res.rbegin();
			res.erase(tmp);
			while(!res.empty() && *res.begin() - r * count <= 0)
				res.erase(*res.begin());
		}
		cout<<count<<endl;
	}
}