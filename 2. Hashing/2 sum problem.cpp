/*
Two sums:

Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use
the same element twice.

You can return the answer in any order.
Constraints:

2 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Using hashtable
// Time: O(n),    Worst case: O(n*n) if all elements are equal,
// 									 there will be n-1 collisions
// Space: O(n)

void m1(vector<int>& a, int n, int x)
{
	unordered_map<int,int> indx;
	for(int i=0;i<n;i++) indx[a[i]]=i+1;

	pair<int,int> ans;
	for(int i=0;i<n;i++)
	{
		int req=x-a[i];
		if(indx[req]>0 && indx[req]!=(i+1)){ ans = {i,indx[req]-1}; break;}
	}
	cout<<ans.first<<" "<<ans.second<<"\n";
}

// reduced some lines of m1
void m2(vector<int>& a, int n, int x)
{
	unordered_map<int,int> indx;
	pair<int,int> ans;
	for(int i=0;i<n;i++)
	{
		int req=x-a[i];
		if(indx[req]>0){ ans = {i,indx[req]-1}; break;}
		indx[a[i]]=i+1;
	}
	cout<<ans.first<<" "<<ans.second<<"\n";
}

int main()
{
	fast_IO();
	test_locally();

	// input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	m1(a,n,5);
	m2(a,n,5);

}
