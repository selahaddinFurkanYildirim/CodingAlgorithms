//#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define int ll
typedef long long ll;
using namespace std;

int n;

void update(vector<int> &sa,vector<int> &rank,int k){
    vector<int> tmp(n);
    tmp[0]=0;
    for(int i=1;i<n;i++){
        int cur1=rank[sa[i-1]];
        int cur2=sa[i-1]+k<n?rank[sa[i-1]+k]:-1;
        int nxt1=rank[sa[i]];
        int nxt2=sa[i]+k<n?rank[sa[i]+k]:-1;
        tmp[sa[i]]=tmp[sa[i-1]]+(cur1!=nxt1 || cur2!=nxt2);
    }
    rank=tmp;
}

void f(){
    string s;
    cin>>s;
    n=s.size();
    vector<int> sa(n),rank(n);
    for(int i=0;i<n;i++){
        sa[i]=i;
        rank[i]=s[i];
    }
    for(int k=1;k<n;k<<=1){
        auto cmp=[&](int si,int sj){
            if(rank[si]!=rank[sj]) return rank[si]<rank[sj];
            int ri=si+k<n?rank[si+k]:-1;
            int rj=sj+k<n?rank[sj+k]:-1;
            return ri<rj;
        };
        sort(sa.begin(),sa.end(),cmp);
        update(sa,rank,k);
    }
    for(int i=0;i<n;i++) cout<<sa[i]<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        f();
    }
    cout<<flush;
    return 0;
}
