#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int q;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		int n,tmp;
		int count = 0;
		cin>>n;
		multiset<int> s;
	
		for(int j = 0; j < n; j++)
		{
			cin>>tmp;
			s.insert(tmp);
		}
		while(!s.empty())
		{
			tmp = *s.begin();
			if(tmp == 2048)
			{
				cout<<"YES"<<endl;
				count = 1;
				break;
			}
			s.erase(s.begin());
			if(!s.empty() && *s.begin() == tmp)
			{
				s.erase(s.begin());
				s.insert(2 * tmp);
			}
		}
		if(count == 0)
			cout<<"NO"<<endl;
	}
	return 0;
}