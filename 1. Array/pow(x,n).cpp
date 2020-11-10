#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Binary exponentiation
// Time: O(log(n))
//Space: O(1)
int pow(int x, int n)
{
	int ans=1;
	while(n>0)
	{
		if(n&1) ans*=x;
		x*=x;
		n/=2;
	}
	return ans;
}

int main()
{
	fast_IO();
	test_locally();

	// input
	int x,n; cin>>x>>n;
	cout<<pow(x,n);

}
