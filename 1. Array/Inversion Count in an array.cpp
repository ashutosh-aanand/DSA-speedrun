/*
Count Inversions in an array
 
Inversion Count for an array indicates – how far (or close) the array is from
being sorted. If array is already sorted then inversion count is 0. If array is
sorted in reverse order that inversion count is the maximum.

Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j]
and i < j 

Example: 

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Brute force
// Time: O(n*n)
// Space: O(1)

// starting from every element a[i], count how many elements after it
// are < a[i].

void m1(vector<int> a, int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j]) ans++;
		}
	}
	cout<<ans<<"\n";
}

// m2) using merge sort algorithm

// TIme: O(nlog(n))
// Space: O(n), due to temp array

vector<int> temp;
int merge(vector<int>& a, int l, int m, int r)
{
	int count=0;

	int i=l, j=m+1;
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp.push_back(a[i]);
			i++;
		}
		else{
			temp.push_back(a[j]);
			j++;
			count+=(m-i+1);
		}
	}
	while(i<=m) temp.push_back(a[i++]);
	while(j<=r) temp.push_back(a[j++]);

	int k=0;
	for(i=l;i<=r;i++)
	{
		a[i]=temp[k];
		k++;
	}
	temp.clear();

	return count; 
}

int inversions(vector<int>& a, int l, int r)
{
	if(l==r) return 0;

	int mid = l+(r-l)/2;

	int inversions_left = inversions(a,l,mid);
	int inversions_right= inversions(a,mid+1,r);

	int inversions_merge = merge(a,l,mid,r);

	return inversions_left + inversions_right + inversions_merge;
}



int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	// m1(a,n);
	cout<<inversions(a,0,n-1);
}
