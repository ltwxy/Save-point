#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
struct score{
    int a,b;
    score(int a,int b):a(a),b(b){}
};
int gcd(int a,int b){
    if(!b){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int pd(int a,int b){
    if(a==b){
        return 0;
    }
    if(a==0){
        if(b==1||b==4){
            return -1;
        }else{
            return 1;
        }
    }
    if(a==1){
        if(b==2||b==4){
            return -1;
        }else{
            return 1;
        }
    }
    if(a==2){
        if(b==0||b==3){
            return -1;
        }else{
            return 1;
        }
    }
    if(a==3){
        if(b==1||b==0){
            return -1;
        }else{
            return 1;
        }
    }
    if(a==4){
        if(b==2||b==3){
            return -1;
        }else{
            return 1;
        }
    }
}
void solve(){
    int n,na,nb;
    cin>>n>>na>>nb;
    vector<int> a(na),b(nb);
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    score p(0,0);
    for(int i=0;i<n;i++){
        int aa=i%na;
        int bb=i%nb;
        if(pd(a[aa],b[bb])==1){
            p.a++;
        }
        if(pd(a[aa],b[bb])==-1){
            p.b++;
        }
    }
    cout<<p.a<<' '<<p.b<<'\n';
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