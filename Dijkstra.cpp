#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define ppi pair<pair<int,int>,int>
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;

int n,m;
vector<ppi> edge;
vector<vector<pi>> adj;

void Dijkstra(int x){
    vector<bool> vis(adj.size());
    vector<int> dis(adj.size(),INT_MAX);
    priority_queue<pi> q;
    dis[x]=0;
    q.push({0,x});
    while(q.size()){
        int a=q.top().S;
        q.pop();
        if(vis[a]) continue;
        vis[a]=1;
        for(pi& i:adj[a]){
            if(dis[a]+i.S<dis[i.F]){
                dis[i.F]=dis[a]+i.S;
                q.push({-dis[i.F],i.F});
            }
        }
    }
    FOR(i,0,adj.size()){
        cout<<x<<" --> "<<i<<" = "<<dis[i]<<endl;
    }
    return;
}

void f(){
    cin>>n>>m;
    adj.resize(n+1);
    edge.resize(m);
    FOR(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
        edge[i]={{a,b},w};
    }
    Dijkstra(1);
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

