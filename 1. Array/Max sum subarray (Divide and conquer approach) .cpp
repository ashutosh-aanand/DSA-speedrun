#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

int max_sum(vector<int>& a, int l, int r)
{
	if(l==r) return a[l];

	int mid = l+(r-l)/2;
	int left_max = max_sum(a, l,mid);
	int right_max= max_sum(a, mid+1,r);

	int mid_left, mid_right;
	mid_left = mid_right = INT_MIN;

	int sum=0;
	for(int i=mid;i>=l;i--)
	{
		sum+=a[i];
		mid_left = max(mid_left, sum);
	}
	sum=0;
	for(int i=mid+1;i<=r;i++)
	{
		sum+=a[i];
		mid_right = max(mid_right, sum);
	}

	int mid_max = max(mid_left + mid_right, max(mid_left, mid_right));

	return max(mid_max, max(left_max, right_max));
}

int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	cout<<max_sum(a,0,n-1);
}