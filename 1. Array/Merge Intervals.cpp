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

void m1(vector<pii>& a, int n)
{
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

int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<pii> a(n);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	sort(a.begin(), a.end());
	m1(a,n);
}