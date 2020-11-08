#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Dutch National Flag Algorithm OR 3-way Partitioning
// time: O(n)
// space: O(1)
void m1(vector<int>& a, int n)
{
	int low,mid,high;
	low = mid = 0;
	high = n-1;

	for(int i=0;i<n;i++)
	{
		if(mid>high) break;

		if(a[i]==0){
			swap(a[i],a[low]);
			low++, mid++;
		}
		else if(a[i]==1){
			swap(a[i],a[mid]);
			mid++;
		}
		else if(a[i]==2){
			swap(a[i],a[high]);
			high--;
			i--;
		}
	}
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
	for(int x: a) cout<<x<<" ";
}