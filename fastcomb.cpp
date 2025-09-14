#pragma GCC optimize("O3")
#include <bits/stdc++.h>
typedef long long ll;
#define int ll
#define S second
#define F first
#define all(v) v.begin(),v.end()
#define MID ((l+r)/2)
using namespace std;
const int MAXN=1e6+5; 
const int PMOD=1e9+7;
/*
 * a^-1=a^(PrimeMOD-2)(mod PrimeMOD)
 * */
vector<int> fact(MAXN),divfact(MAXN);

int binpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%PMOD;
		a=a*a%PMOD;
		b>>=1;
	}
	return ans;
}
int comb(int n,int r){
	return (fact[n]*divfact[r]%PMOD)*divfact[n-r]%PMOD;
}

void f(){
	int n;
	cin>>n;
	cout<<(2*comb(n*2-1,n)-n)%PMOD<<endl;
}

signed main(){
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		fact[0]=1;
		for(int i=1;i<MAXN;i++) fact[i]=fact[i-1]*i%PMOD;
		divfact[0]=1;
		divfact[1]=1;
		for(int i=2;i<MAXN;i++) divfact[i]=binpow(fact[i],PMOD-2);
	}
	int t=1;
	//~ cin>>t;
	while(t--){
		f();
		cout<<"\n";
	}
	cout<<flush;
	return 0;
}
