/*
Given an array nums of n integers and an integer target, are there elements
a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Constraints:

0 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)

void m1(vector<int>& a, int n, int x)
{
	unordered_map<int,int> indx;
	vector<vector<int> > ans;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int req = x-(a[i]+a[j]+a[k]);
				if(indx[req]>0) ans.push_back({req,a[i],a[j],a[k]});
			}
		}
		indx[a[i]]=i+1;
	}
	for(auto x: ans){
		for(int y: x) cout<<y<<",";
			cout<<"\n";
	}
}

int main()
{
	fast_IO();
	test_locally();

	// input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int x; cin>>x;

	m1(a,n,x);
}
