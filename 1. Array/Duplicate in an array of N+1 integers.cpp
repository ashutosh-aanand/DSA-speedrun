#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

//m1) using negative indexing. Time: O(n), Space: O(1)
int m1(int a[], int n)
{
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int indx = abs(a[i])-1;
		if(a[indx]<0){ ans = abs(a[i]); break;}
		else{
			a[indx]=-a[indx];
		}
	}
	return ans;
}

// m2) Using Tortoise and Hare (cycle detection)
// time : O(n), Space: O(n) without affecting the data
int m2(int a[], int n)
{
	int slow=a[0], fast = a[a[0]];

	while(fast!=slow)
	{
		fast = a[a[fast]];
		slow = a[slow];
	}

	fast=0;
	while(fast!=slow)
	{
		fast = a[fast];
		slow = a[slow];
	}
	return slow;
}

int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans;
	// ans = m1(a,n);
	ans = m2(a,n);

	cout<<ans;
}