/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0.
Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


eg.,
Input: matrix = [[1,1,1],
				 [1,0,1],
				 [1,1,1]]

Output: 		[[1,0,1],
				 [0,0,0],
				 [1,0,1]]
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Inplace algo
// Time: O(n*m)
// Space: O(1)

void m1(vector<vector<int> > a)
{
	int n=a.size();
    int m=a[0].size();

    //info gathering
    bool first_row_0 = false, first_col_0 = false;

    for(int i=0;i<n;i++) if(a[i][0]==0){ first_col_0 = true; break;}
    for(int j=0;j<m;j++) if(a[0][j]==0){ first_row_0 = true; break;}

    // marking

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==0){
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        if(a[i][0]==0)
        {
            //make whole row zero
            for(int j=0;j<m;j++) a[i][j]=0;
        }
    }
    for(int j=1;j<m;j++)
    {
        if(a[0][j]==0)
        {
            //make whole column zero
            for(int i=0;i<n;i++) a[i][j]=0;
        }
    }

    if(first_row_0){
    	for(int j=0;j<m;j++) a[0][j]=0;
    }
	if(first_col_0){
		for(int i=0;i<n;i++) a[i][0]=0;
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