#include <bits/stdc++.h>
#define FOR(i,s,e) for(int i=int(s);i<int(e);i++)
#define pi pair<int,int>
#define pb push_back
#define S second
#define F first
using namespace std;

struct edge{
    int a,b,w;
};

vector<edge> e;
vector<edge> ans;
vector<int> l;
vector<int> s;

int bul(int a){
    while(l[a]!=a) a=l[a];
    return a;
}

vector<edge> kruskal(){
    sort(e.begin(),e.end(),[](const edge& a,const edge& b){
        return a.w<b.w;
    });
    vector<edge> ans;
    FOR(i,0,e.size()){
        int a=bul(e[i].a),b=bul(e[i].b);
        if(a!=b){
            ans.pb(e[i]);
            if(s[a]<s[b]) swap(a,b);
            l[b]=a;
            s[a]+=s[b];
        }
    }
    return ans;
}

void f(){
    int n,m;
    cin>>n>>m;
    l.resize(n+1);
    s.resize(n+1);
    e.resize(m);
    FOR(i,0,n+1){
        l[i]=i;
        s[i]=1;
    }
    FOR(i,0,m){
        cin>>e[i].a>>e[i].b>>e[i].w;
    }
    vector<edge> ans=kruskal();
    FOR(i,0,ans.size()){
        cout<<"\t"<<ans[i].w<<"\n"<<ans[i].a<<"\t-->\t"<<ans[i].b<<endl;
    }
    return;
}

int main(){
#ifdef DEVCPP
    freopen("input.txt", "r", stdin);
    cout<<"girdi(input.txt)"<<endl;
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
//  cin>>t;
    while(t--){
        f();
        cout<<endl;
    }
    return 0;
}
