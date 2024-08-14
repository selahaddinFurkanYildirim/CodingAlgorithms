#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

vector<int> tree;

void update(int x,int val){
	x++;
	int n=tree.size();
	while(x<=n){
		tree[x]+=val;
		x+=x&(-x);
	}
}

void build(vector<int> &ar){
	int n=ar.size();
    tree.resize(n+1);
	for(int i=0;i<n;i++){
		update(i,ar[i]);
	}
}
int query(int x){
	int sum=0;
	x++;
	while(x){
		sum+=tree[x];
		x-=x&(-x);
	}
	return sum;
}
int rangeQuery(int l,int r){
	return query(r)-query(l-1);
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
		cout<<rangeQuery(x-1,y-1)<<endl;
	}
    return 0;
}
