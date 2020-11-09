/*
Rotate matrix

You are given an n x n 2D matrix representing an image, rotate the image by
90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

eg.,
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

void m1(vector<vector<int> >& a)
{
	int n=a.size(), m=a[0].size();

	//mirror image about middle row
	for(int i=0;i<n/2;i++)
	{
		swap(a[i],a[n-i-1]);
	}

	//transpose
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			swap(a[i][j],a[j][i]);
		}
	}


	//output
	for(auto x: a)
	{
		for(int y: x) cout<<y<<",";
		cout<<"\n";
	}
}

int main()
{
	fast_IO();
	test_locally();

	//input
	int n,m; cin>>n>>m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>a[i][j];

	m1(a);
}
