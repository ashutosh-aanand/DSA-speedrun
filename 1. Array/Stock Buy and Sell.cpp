/*
Stock buy and sell

Say you have an array for which the ith element is the price of a given stock
on day i.

If you were only permitted to complete at most one transaction (i.e., buy one
and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)
// Time: O(n)
// Space:O(1)
// for each a[i], we need the min to it's left

void m1(vector<int>& a, int n)
{
	int ans=0;
	int mn=a[0];

	for(int i=1;i<n;i++)
	{
		if(a[i]<mn) mn=a[i];
		ans = max(ans, a[i]-mn);
	}

	cout<<ans<<" ";
}


int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	m1(a,n);
}
