#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> a;
int t;
void ssz(int h,int l,int r){
    for(int i=1;i<=r;i++){
        for(int j=0;j<=r;j++){
            int p1=a[h+i][l+j];
            int p2=a[h+j][l-i];
            int p3=a[h-i][l-j];
            int p4=a[h-j][l+i];
            a[h+i][l+j]=p4;
            a[h+j][l-i]=p1;
            a[h-i][l-j]=p2;
            a[h-j][l+i]=p3;
        }
    }
}
void nsz(int h,int l,int r){
    for(int i=1;i<=r;i++){
        for(int j=0;j<=r;j++){
            int p1=a[h+i][l+j];
            int p2=a[h+j][l-i];
            int p3=a[h-i][l-j];
            int p4=a[h-j][l+i];
            a[h+i][l+j]=p2;
            a[h+j][l-i]=p3;
            a[h-i][l-j]=p4;
            a[h-j][l+i]=p1;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    a.resize(n+1,vector<int>(n+1));
    int jl=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=jl;
            jl++;
        }
    }
    for(int i=0;i<m;i++){
        int h,l,r,z;
        cin>>h>>l>>r>>z;
        if(z==0){
            ssz(h,l,r);
        }else{
            nsz(h,l,r);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    
    return 0;
}