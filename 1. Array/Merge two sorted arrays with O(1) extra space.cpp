/*
Merge two sorted arrays with O(1) extra space

We are given two sorted array. We need to merge these two arrays such that the 
initial numbers (after complete sorting) are in the first array and the remaining 
numbers are in the second array. Extra space allowed in O(1).

eg.,
Input: 
N = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)
// Time: O(n*m)
// space: O(1)

/*
worst case: when all elements of "a" are > all elements of "b"
eg.,
a={5,6,7},  b={1,2,3,4}
*/

void m1(vector<int>& a, int n, vector<int>& b, int m)
{
	int i=0;

	while(i<n)
	{
		if(a[i]<=b[0]){
			i++;
		}
		else if(a[i]>b[0]){
			swap(a[i],b[0]);
			i++;

			//send b[0] to it's correct position in array b
			// so that array b will be sorted.
			int j=0;
			while(j+1<m && b[j]>b[j+1]){
				swap(b[j],b[j+1]);
				j++;
			}
		}
	}
}

// m2) O(m+n) space solu.
// Time:  O(m+n)
// Space: O(m+n)

void m2(vector<int>& a, int n, vector<int>& b, int m)
{
	vector<int> ans(n+m);
	int i=0, j=0, k=0;
	while(i<n && j<m)
	{
		if(a[i]<=b[j]){
			ans[k]=a[i];
			k++, i++;
		}
		else{
			ans[k]=b[j];
			k++, j++;
		}
	}
	while(i<n) ans[k++]=a[i++];
	while(j<m) ans[k++]=b[j++];

	//filling answer
	for(int i=0;i<n;i++) a[i]=ans[i];
	for(int i=0;i<m;i++) b[i]=ans[n+i];
}

int main()
{
	fast_IO();
	test_locally();

	//input
	int n,m; cin>>n>>m;
	vector<int> a(n), b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];

	m2(a,n,b,m);
	
	for(int i=0;i<n;i++) cout<<a[i]<<", "; cout<<"\n";
	for(int i=0;i<m;i++) cout<<b[i]<<", "; cout<<"\n";
}