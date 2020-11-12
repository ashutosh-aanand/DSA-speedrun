/*
Given an array of integers arr[] and a number m, count the number of subarrays
having XOR of their elements as m.

Examples:

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Using prefix xor array

void m1(vector<int>& a, int n, int k)
{
	vector<int> pf(n,0);
	unordered_map<int,int> count;
    
    pf[0]=a[0];
    count[a[0]]=1;
    count[0]++;

    int ans=0;
	for(int i=1;i<n;i++){
		pf[i]=pf[i-1]^a[i];

		ans += count[pf[i]^k];
		count[pf[i]]++;
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
	int k; cin>>k;
	m1(a,n,k);

}
