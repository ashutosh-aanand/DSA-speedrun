/*
Given an array having both positive and negative integers.
The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5

Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Using prefix sum array
//   15,-2,2,-8,1,7,10,23
// 0,15,13,15,7,8,15,25,48 -> prefix sum
//    :            :

void m1(vector<int>& a, int n)
{
	vector<int> pf(n,0);
	unordered_map<int,int> indx;
    
    pf[0]=a[0];
    indx[a[0]]=1;

    int ans=0;
	for(int i=1;i<n;i++){
		pf[i]=pf[i-1]+a[i];

		if(indx[pf[i]]==0){
			indx[pf[i]]=i+1;
		}
		else{
			if(pf[i]==0) ans = max(ans, i+1);
			else ans = max(ans, i+1-indx[pf[i]]);
		}
	}
	cout<<ans;
}

int main()
{
	fast_IO();
	test_locally();

	// input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	m1(a,n);

}
