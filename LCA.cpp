/* 
 * bu kod sadece tree için çalışır aksi takdirde dfs içinde tek bir atdan daha fazlası tutulmalıdır
 * (işler karışır)
 * */
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<vector<int>> fa;//father
vector<vector<int>> adj;
vector<int> der;//derinlik
int n;

void dfs(int node,int ata){
	fa[node][0]=ata;
	der[node]=der[ata]+1;
	for(auto go:adj[node]){
		if(go==ata) continue;
		dfs(go,node);
	}
}

void build(){
	for(int j=1;j<20;j++){
		for(int i=1;i<n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
}

int lca(int x,int y){
	if(der[x]<der[y]) swap(x,y);
	int fark=der[x]-der[y];
	for(int i=19;i>=0;i--){
		if((1<<i)<=fark){
			fark-=(1<<i);
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]==fa[y][i]) continue;
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}

signed main() {
	printf("\033[2J\033[H");
	fio;
	cin>>n;
	//1 indisli hale getirmek için falan herhalde
	n++;
	adj.resize(n);
	fa.resize(n,vector<int>(20));//edge sayisi 2^20 yi gecmedigi için
	der.resize(n);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	//root olmasını istediğin düğüm önce
	dfs(1,0);
	build();
	cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
/*
10
0 2
0 3
0 6 
0 9 
2 4
2 5
5 8
3 7 
9 1


 * */
