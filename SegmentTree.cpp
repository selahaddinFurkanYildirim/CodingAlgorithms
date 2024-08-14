#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

vector<int> tree;

void build(vector<int> &ar){
    int n=ar.size();
    tree.resize(n*2);
    for(int i=0;i<n;i++) tree[i+n]=ar[i];
    for(int i=n-1;i>0;i--){
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
}

void update(int i, int val) {
    i+=tree.size()/2;
    while(i){
        tree[i] += val;
        i>>=1;
    }
}

int query(int l, int r) {
    int res = 0;
    int n=tree.size()/2;
    l+=n;
    r+=n;
    while(l<=r){
        if(l&1) res+=tree[l++];
        if((r&1)==0) res+=tree[r--];
        l>>=1;
        r>>=1;
    }
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Program derlenme tarihi: "<<__DATE__<<endl
        <<"Program derlenme saati: "<<__TIME__<<endl;
    int n;
    cin>>n;
    vector<int> ar(n);
    for(auto & i:ar) cin>>i;
    build(ar);
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        cout<<query(x-1,y-1)<<endl;
    }
    return 0;
}
