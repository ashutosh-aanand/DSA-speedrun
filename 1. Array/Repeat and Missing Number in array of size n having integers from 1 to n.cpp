/*
Given an unsorted array of size n. Array elements are in the range from 1 to n.
One number from set {1, 2, …n} is missing and one number occurs twice in the array.
Find these two numbers.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1) using sorting
// Time: O(nlogn)
// Space: O(1)

void m1(vector<int> a, int n)
{
	sort(a.begin(), a.end());
	int missing, repeating;

	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1]) repeating = a[i];
		else if(a[i]-a[i-1]==2) missing = a[i]-1;
	}
	cout<<missing<<" "<<repeating;
}

// m2) using frequency count array
// Time: O(n)
// Space: O(n)

// m3) using -ve indexing
// Time: O(n)
// Space: O(1)
// modifies data in the array
void m3(vector<int> a, int n)
{
	int missing, repeating;

	int indx;
	for(int i=0;i<n;i++)
	{
		indx = abs(a[i])-1;
		if(a[indx]<0) repeating = a[i];
		else{
			a[indx] = -a[indx];
		}
	}

	for(int i=0;i<n;i++)
		if(a[i]>0){ missing = i+1; break;}

	cout<<missing<<" "<<repeating;
}

// m4) Mathematical
// time: O(n)
// space: O(1)
/*
let Sum = 1+2+...+n
	Prod = 1*2*....*n

	S = a[0]+a[1]+...+a[n-1]
	  = Sum - mis + rep      - (i)

	P = a[0]*a[1]*...*a[n-1]
	  = Prod*rep/mis         - (ii)

	solve eqn. i and ii to get mis and rep.

	rep = p*(S-Sum)/(P-Prod)
	mis = Prod*(S-Sum)/(P-Prod)

	** This method can cause arithmetic overflow.
*/

// m5) Using bitwise XOR
// time: O(n)
// space: O(1)
// similar to 2 repeating no.s in an array
void m5(vector<int> a, int n)
{
	// eg., {1,2,3,3}
	int x1=0;
	for(int i=0;i<n;i++) x1^=a[i];

	for(int i=1;i<=n;i++) x1^=i;

	// x1=(1^2^3^3)^(1^2^3^4);
	// x1 = 3^4

	// now x1 = mis^rep;

	// making 2 sets based on rightmost set bit in x1
	int k=0;
	while(x1>0)
	{
		k++;
		if(x1&1) break;
		x1>>1;
	}

	int set= (1<<k);

	int x=0, y=0;

	// {1,2,3,3,1,2,3,4}
	// will be divided as {1,3,3,1,3}, {2,2,4}
	// in first set "3" is odd occuring, and "4" in 2nd set.
	// so they are one of missing and repeating numbers.
	for(int i=0;i<n;i++)
	{
		if(a[i]&set) x^=a[i];
		else y^=a[i];

		if((i+1)&set) x^=(i+1);
		else y^=(i+1);
	}

	// now one of x,y is missing and one is repeating.
	int missing, repeating;
	for(int i=0;i<n;i++)
	{
		if(a[i]==x){ repeating= x; break;}
		else if(a[i]==y){ repeating= y; break;}
	}
	if(repeating==x) missing = y;
	else missing = x;

	cout<<missing<<" "<<repeating;
}




int main()
{
	fast_IO();
	test_locally();

	//input
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	m5(a,n);
}