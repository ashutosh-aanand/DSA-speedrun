/*
Given an n x n matrix and a number x, find the position of x in the matrix if
it is present in it. Otherwise, print “Not Found”. In the given matrix, every row
and column is sorted in increasing order.
The designed algorithm should have linear time complexity. 
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)

void m1(vector<vector<int> > a, int x)
{
	int n = a.size();
	if(n==0){ cout<<"Matrix is empty"; return;}
	int m = a[0].size();

	int i=0,j=m-1;
	bool found = false;
	while(i<n && j>=0)
	{
		if(x < a[i][j]) j--;
		else if(x > a[i][j]) i++;
		else{ found=true; break;}
	}
	if(found) cout<<i<<","<<j<<"\n";
	else cout<<"Not Found !\n";
}

int main()
{
	fast_IO();
	test_locally();

	// input
	int n,m; cin>>n>>m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>a[i][j];
	int x; cin>>x;

	m1(a,x);

}
