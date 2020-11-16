#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;


void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
void test_locally(){ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);}

// m1)

void m1(string s)
{
	int n = s.size();
	int indx[256]={0};

	int ans=1, ct=0;
	for(int i=0;i<n;i++)
	{
		if(indx[s[i]]==0){
			indx[s[i]]=i+1;
			ct++;
		}
		else{
			ct=min(ct+1,(i+1-indx[s[i]]));
			indx[s[i]]=i+1;
		}
		ans = max(ans,ct);	
		// cout<<s[i]<<":"<<ct<<", ";
	}
	// cout<<"\n";
	cout<<ans;
}

int main()
{
	fast_IO();
	test_locally();

	// input
	string s; cin>>s;
	
	m1(s);
}
