#include <iostream>
using namespace std;
 
char ar[1005][1005];
int ans=0,n,m;
 
void gez(int x,int y){
    if(x<0 || x>=n) return;
    if(y<0 || y>=m) return;
    if(ar[x][y]=='#') return;
    ar[x][y]='#';
    gez(x,y+1);
    gez(x,y-1);
    gez(x+1,y);
    gez(x-1,y);
    return;
}
 
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ar[i][j]!='#'){
                ans++;
                gez(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
