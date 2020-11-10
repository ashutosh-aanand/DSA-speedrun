#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) Moore's voting algo.
// Time: O(n)
// Space: O(1)
void m1(vector<int>& a, int n)
{
	int max1 = INT_MAX, max2= INT_MAX, c1=0, c2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==max1) c1++;
        else if(a[i]==max2) c2++;
        else if(c1==0)
        {
            c1=1;
            max1=a[i];
        }
        else if(c2==0)
        {
            c2=1;
            max2=a[i];
        }
        else{
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1=c2=0;
    for(int i=0;i<n;i++){
        if(a[i]==max1)c1++;
        else if(a[i]==max2)c2++;
    }
    if(c1>n/3) ans.push_back(max1);
    if(c2>n/3) ans.push_back(max2);
    
    for(int x: ans) cout<<x<<" ";
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
