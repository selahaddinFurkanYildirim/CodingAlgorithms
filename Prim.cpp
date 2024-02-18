#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;

vector<vector<pi>> adj;
vector<int> vis;
vector<pi> ans;

void prim(){
    int n=adj.size();
    vis.resize(n,0);
    priority_queue<pi> q;
    vector<pi> key(n,{INT_MAX,-1});
    q.push({0,1});
    vis[1]=1;
    while(q.size()){
        int x=q.top().S;
        int w=-q.top().F;
        q.pop();
        vis[x]=1;
        FOR(i,0,adj[x].size()){
            if(vis[adj[x][i].F]) continue;
            if(key[adj[x][i].F].F<=w) continue;
            q.push({-adj[x][i].S,adj[x][i].F});
            key[adj[x][i].F].F=w;
            if(key[adj[x][i].F].S+1){
                ans[key[adj[x][i].F].S]={x,adj[x][i].F};
            }
            else{
                key[adj[x][i].F].S=ans.size();
                ans.pb({x,adj[x][i].F});
            }
        }
    }
    return;
}

void f(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    FOR(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    prim();
    FOR(i,0,ans.size()){
        cout<<ans[i].F<<" "<<ans[i].S<<endl;
    }
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

