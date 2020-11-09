/*
Given a non-negative integer numRows, generate the first numRows of
Pascal's triangle.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)
// Time: O(n*n)
// Space: O(n*n)
/*
nth row has n no. of elements
=> Time and space complexity:
 = 1+2+3+4+...+n => O(n*n)
*/

vector<vector<int> > m1(int n)
{
	vector<vector<int> > p(n);
	p[0].push_back(1);
	if(n==1) return p;

	p[1].push_back(1);
	p[1].push_back(1);
	if(n==2) return p;

	for(int i=2;i<n;i++)
	{
		p[i].push_back(1);
		for(int j=1;j<p[i-1].size();j++)
		{
			p[i].push_back(p[i-1][j-1]+p[i-1][j]);
		}
		p[i].push_back(1);
	}
	return p;
}


int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;

	vector<vector<int> > ans = m1(n);
	for(auto x: ans)
	{
		for(int y: x) cout<<y<<",";
		cout<<"\n";
	}
}