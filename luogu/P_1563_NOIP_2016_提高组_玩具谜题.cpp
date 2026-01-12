#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
struct node{
    int f;
    string s;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].f>>a[i].s;
    }
    int tap=0;
    for(int i=0;i<m;i++){
        int op,x;
        cin>>op>>x;
        if(op==a[tap].f){
            tap=(tap+n-x)%n;
        }else{
            tap=(tap+x)%n;
        }
    }
    cout<<a[tap].s<<'\n';
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