//#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define int ll
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;

void f(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> ind(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //cout<<u<<" "<<v<<endl;
        u--,v--;
        adj[u].push_back(v);
        ind[v]++;
    }
    priority_queue<int> q;
    vector<int> res;
    res.reserve(n);
    for(int i=0;i<n;i++){
        if(ind[i]==0) q.push(-i);
    }
    while(q.size()){
        int t=-q.top();
        q.pop();
        res.push_back(t);
        for(int e:adj[t]){
            ind[e]--;
            if(ind[e]==0) q.push(-e);
        }
    }
    if(res.size()!=n) cout<<"Sandro fails."<<"\n";
    else{
        for(int e:res) cout<<e+1<<" ";
        cout<<"\n";
    }
    return;
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
