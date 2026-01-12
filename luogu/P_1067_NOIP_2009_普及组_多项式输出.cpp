#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++){
        cin>>a[i];
        if(i==0){
            if(a[i]==1){
            cout<<"+x^"<<n-i;
            }else if(a[i]==-1){
                cout<<"-x^"<<n-i;
            }else{
                cout<<a[i]<<"x^"<<n-i;
            }
        }else if(i!=n){
            if(a[i]==1){
                cout<<"+x^"<<n-i;
            }
            if(a[i]==-1){
                cout<<"-x^"<<n-i;
            }
            if(a[i]>0&&a[i]!=1){
                cout<<'+'<<a[i]<<"x^"<<n-i;
            }
            if(a[i]<0&&a[i]!=-1){
                cout<<a[i]<<"x^"<<n-i;
            }
        }else{
             if(a[i]>0){
                cout<<'+'<<a[i];
            }
            if(a[i]<0){
                cout<<a[i];
            }
        }
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