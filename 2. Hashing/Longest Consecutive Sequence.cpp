/*
Given an unsorted array of integers nums, return the length of the 
longest consecutive elements sequence.

Follow up: Could you implement the O(n) solution? 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)sorting
// Time: O(nlog(n))
//Space: O(1)
void m1(vector<int> a, int n)
{
	int n=a.size();
    if(n==0) return 0;

    sort(a.begin(), a.end());
    int count=1, ans=1;
    for(int i=1;i<n;i++)
    {
        while(i<n && a[i]==a[i-1])i++;// skip the repeating
        if(i==n) break;

        if(a[i]==a[i-1]+1) count++;
        else count=1;
        ans=max(ans,count);
    }
	cout<<ans;
}

// m2) using unordered set
// Time: O(n), O(n*n) in worst case
//Space: O(n)

void m2(vector<int>& a, int n)
{
	if(n==0) return 0;

	unordered_set<int> s;
    for(int i=0;i<n;i++) s.insert(a[i]);

    int ans=1;
    for(int i=0;i<n;i++)
    {
        if(s.count(a[i]-1)) continue;
        else{
            int t=a[i];
            int ct=0;
            while(s.count(t++)) ct++;

            ans=max(ans, ct);
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

}
