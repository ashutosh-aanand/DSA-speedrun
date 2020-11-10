#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)
int fact(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++) ans*=i;
	return ans;
}
void m1(int n, int m)
{
	int ans;
	ans = fact(m+n-2)/(fact(n-1)*fact(m-1));
	cout<<ans<<"\n";
}

// m2) Dynamic Programming

void m2(int n, int m)
{
	vector<vector<int> > dp(n, vector<int>(m,1));

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	cout<<dp[n-1][m-1]<<"\n";
}


int main()
{
	fast_IO();
	test_locally();

	// input
	int n,m; cin>>n>>m;
	m1(n,m);
	m2(n,m);
}
