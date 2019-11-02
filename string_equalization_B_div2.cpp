#include<bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;
	string s, t;
	int tmp;
	for(int i = 0; i < q; i++)
	{
		tmp = 0;
		cin>>s>>t;
		for(int j = 0; j < s.size(); j++)
		{
			s[j] = toupper(s[j]);
			t[j] = toupper(t[j]);
		}
		for(int j = 0; j < s.size(); j++)
		{
			tmp = 0;
			for(int k = 0; k < s.size(); k++)
			{
				if(s[j] == t[k])
				{
					cout<<"YES"<<endl;
					tmp = 1;
					break;
				}
			}
			if(tmp == 1)
				break;
		}
		if(tmp == 0)
			cout<<"NO"<<endl;
	}
	return 0;
}