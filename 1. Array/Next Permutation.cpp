/*
Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the
lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)

void m1(vector<int> a, int n)
{
	int i,p=-1;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]>a[i-1]){ p=i-1; break;}
	}

	if(p==-1)
	{
		sort(a.begin(), a.end());
	}
	else
	{
		int g;

		for(int j=p+1;j<n;j++)
			if(a[j]>a[p]) g=j;

		swap(a[p], a[g]);
		sort(a.begin()+p+1, a.end());
	}

	for(int x: a) cout<<x<<" ";
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