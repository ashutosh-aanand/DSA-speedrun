#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Moore's voting algo.
// Time: O(n)
// Space: O(1)
void m1(vector<int>& a, int n)
{
	int max = a[0], f=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==max) f++;
		else
		{
			f--;
			if(f==0){ max = a[i]; f=1;}
		}
	}
	f=0;
	for(int i=0;i<n;i++) if(a[i]==max)f++;
	if(f>n/2) cout<<max<<"\n";
	else cout<<"No Majority element\n";

}

int main()
{
	fast_IO();
	test_locally();

	// input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	m1(a,n);

}
