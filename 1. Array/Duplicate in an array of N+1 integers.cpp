#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

void fun()
{
	//input
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	//processing
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int indx = abs(a[i])-1;
		if(a[indx]<0){ ans = abs(a[i]); break;}
		else{
			a[indx]=-a[indx];
		}
	}

	//output
	cout<<ans;
}

int main()
{
	fast_IO();
	test_locally();

	fun();
}