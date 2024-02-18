//strongly connected component
#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define ppi pair<pair<int,int>,int>
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;

int n,m;
vector<pi> edge;
vector<vector<int>> adj;
vector<vector<int>> adjtr;
vector<bool> vis;
vector<int> sira;

void dfs(int x){
    if(vis[x]) return;
    vis[x]=1;
    FOR(i,0,adj[x].size()){
        dfs(adj[x][i]);
    }
    sira.pb(x);
    return;
}
void dfstr(int x){
    if(vis[x]) return;
    cout<<x<<" ";
    vis[x]=1;
    FOR(i,0,adjtr[x].size()){
        dfstr(adjtr[x][i]);
    }
    return;
}

void Kosaraju(){
    vis.resize(adj.size());
    FOR(i,0,adj.size()){
        if(!vis[i]) dfs(i);
    }
    vis=vector<bool>(adj.size(),0);
    int ans=0;
    for(int i=sira.size()-1;i>0;i--){
        if(!vis[sira[i]]){
            dfstr(sira[i]);
            cout<<endl;
            ans++;
        }
    }
    cout<<ans;
}

void f(){
    cin>>n>>m;
    adj.resize(n+1);
    adjtr.resize(n+1);
    edge.resize(m);
    FOR(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adjtr[b].pb(a);
        edge[i]={a,b};
    }
    //cout<<"Okuma tamamlandi."<<endl;
    Kosaraju();
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

