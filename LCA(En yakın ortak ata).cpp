#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define FORR(i,ar) for(auto& i:ar)
#define ppi pair<pair<int,int>,int>
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> d;
vector<int> road;// A dp list for dfs road

void dfs(int s,int a,int depth){
    road.pb(s);
    d[s]=depth;
    FORR(i,adj[s]){
        if(i!=a){
            dfs(i,s,depth+1);
            road.pb(s);
        }
    }
    return;
}

void ans(int x,int y){//lca func
    dfs(1,0,1);
    if(x>y) swap(x,y);
    int i=-1;
    while(road[++i]!=x);
    int val=INT_MAX;
    while(road[i++]!=y) val=min(val,d[road[i]]);
    cout<<val;
    return;
}

void f(){
    cin>>n>>m;
    adj.resize(n+1);
    d.resize(n+1,0);
    FOR(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //cout<<"Okuma tamamlandi."<<endl;
    ans(5,8);
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        f();
        cout<<endl;
    }
    return 0;
}
