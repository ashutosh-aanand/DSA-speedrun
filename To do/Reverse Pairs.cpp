/*
Reverse Pairs:

Given an array nums, we call (i, j) an important reverse pair
if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)

void m1()
{
	int n=a.size(), ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i]+1)/2>a[j]) ans++;
        }
    }
    return ans;
}

// m2) Using merge sort

int count(vector<int>& a, int l, int r)
{
	if(l==r) return 0;

	int left_count = count(a,l,m);
	int right_count= count(a,m+1,r);

	int merge_count = merge(a,l,m,r);

	return left_count + right_count + merge_count;
}



int main()
{
	fast_IO();
	test_locally();

	// input

}
