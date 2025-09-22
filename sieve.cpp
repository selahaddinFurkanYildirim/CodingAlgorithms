#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define MAXN ((int)3e8+37)
#define MAXP 23333333
using namespace std;

using u64 = unsigned long long;

//bitset alternative because why not?
u64 bits[(MAXN + 63) / 64];
inline void setbit1(int x) {
    bits[x / 64] |= (1ULL << (x % 64));
}
inline void setbit0(int x) {
    bits[x / 64] &= ~(1ULL << (x % 64));
}
inline bool getbit(int x) {
    return bits[x / 64] & (1ULL << (x % 64));
}

int p[MAXP],inp=0;

int main(){
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		for(int i=2;i<=MAXN;i++){
			if(getbit(i)==0){
				p[inp++]=i;
			}
			for(int j=0;j<inp && i*p[j]<=MAXN;j++){
				setbit1(i*p[j]);
				if(i%p[j]==0) break;
			}
		}
	}
	cout<<endl;
	int l=124124,r= 1235125;
	// cin>>l>>r;
	int ans=l<=2 && r>=2;
	for(int i=0;i<inp;i++){
		if(p[i]>=l && p[i]<=r && p[i]%4==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
