#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define ppi pair<pair<int,int>,int>
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;
 
int n,m;
vector<pi> e;
vector<int> l;
vector<int> s;
 
int bul(int x){
    while(l[x]!=x) x=l[x];
    return x;
}
 
void Kruskal(){
    l.resize(n+1);
    s.resize(n+1,1);
    FOR(i,1,n+1){
        l[i]=i;
    }
    for(pi& i:e){
        int a=i.F,b=i.S;
        if(bul(a)!=bul(b)){
            a=bul(a);
            b=bul(b);
            if(s[a]<s[b]) swap(a,b);
            l[b]=a;
            s[a]+=s[b];
        }
    }
    vector<pi> ans;
    vector<bool> vis(n+1,0);
    int son=bul(1);
    vis[son]=1;
    FOR(i,1,n+1){
        if(vis[bul(i)]==0){
            ans.pb({son,bul(i)});
            son=bul(i);
            vis[bul(i)]=1;
        }
    }
    cout<<ans.size()<<endl;
    for(pi& it:ans){
        cout<<it.F<<" "<<it.S<<endl;
    }
    return;
}
 
void f(){
    cin>>n>>m;
    e.resize(m);
    FOR(i,0,m){
        int a,b;
        cin>>a>>b;
        e[i]={a,b};
    }
    //cout<<"Okuma tamamlandi."<<endl;
    Kruskal();
    return;
}
 
int main(){
    //freopen("input.txt", "r", stdin);
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
