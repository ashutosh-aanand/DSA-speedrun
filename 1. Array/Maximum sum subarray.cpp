/*
Given an integer array nums, find the contiguous subarray (containing at least one
number) which has the largest sum and return its sum.

Follow up:
If you have figured out the O(n) solution,
try coding another solution using the divide and conquer approach,
which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) brute force
// Time: O(n*n)
// Space: O(1)
void m1(vector<int>& a, int n)
{
	int ans=INT_MIN;

	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=a[j];
			ans= max(ans, sum);
		}
	}
	cout<<ans<<"\n";
}

// m2) Dynamic programming
// Time: O(n)
// Space: O(n)

// let dp[i] =  max. sum till ith index.
void m2(vector<int>& a, int n)
{
	int dp[n];
	dp[0]= a[0];

	int ans= a[0];
	for(int i=1;i<n;i++)
	{
		dp[i]= max(dp[i-1]+a[i], a[i]);
		ans = max(ans, dp[i]);
	}
	cout<<ans<<"\n";
}

// m3) Kadane's algo. (space optimised version of dp)
// Time: O(n)
// Space: O(1)

// since for dp[i] we need only dp[i-1]
// so, we can use a variable to store dp[i-1]

void m3(vector<int>& a, int n)
{
	int ans=a[0], sum=a[0];
	for(int i=1;i<n;i++)
	{
		sum = max(sum + a[i], a[i]);
		ans = max(ans, sum);
	}
	cout<<ans<<"\n";
}

// this is how kadane's alog looks 
int kadanesAlog(vector<int> &a, int n)
{
	int curr_max, global_max;
	curr_max = global_max = INT_MIN;

	for(int i=0;i<n;i++)
	{
		curr_max = max(curr_max+a[i], a[i]);
		global_max = max(global_max, curr_max);
	}
	return global_max;
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
	m2(a,n);
	m3(a,n);
}