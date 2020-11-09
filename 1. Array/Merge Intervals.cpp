/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) using stack
// Time: O(nlog(n)) (due to sorting in the beginning)
// Space: O(n)

void m1(vector<pii> a, int n)
{
	// sort intervals in ascending order of starting time
	sort(a.begin(), a.end());

	stack<pii> s;
	s.push(a[0]);

	for(int i=1;i<n;i++)
	{
		pii curr = a[i];
		pii top = s.top();

		if(curr.first<=top.second)
		{
			s.pop();
			top.second = max(curr.second, top.second);
			s.push(top);
		}
		else s.push(curr);
	}

	vector<pii> ans;
	while(!s.empty()) ans.push_back(s.top()), s.pop();

	reverse(ans.begin(), ans.end());

	for(pii x: ans) cout<<x.first<<" "<<x.second<<"\n";
	
}


// m2) a space optimised solution 		**
// Time : O(nlog(n))
// Space : O(1)

// writing the above alogrithm inplace

void m2(vector<pii> a, int n)
{
	// sort intervals in ascending order of starting time
	sort(a.begin(), a.end());

	int ind=0;

	for(int i=1;i<n;i++)
	{
		if(a[ind].second>=a[i].first)
		{
			//merge the intervals
			a[ind].second = max(a[ind].second, a[i].second);
		}
		else
		{
			//leave that interval at ind and move forward
			ind++;
			a[ind]=a[i];
		}
	}

	// now a[0] to a[ind] has the required interval.
	for(int i=0;i<=ind;i++)	cout<<a[i].first<<" "<<a[i].second<<"\n";
}








int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<pii> a(n);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	// m1(a,n);
	m2(a,n);
}