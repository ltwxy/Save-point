#include<bits/stdc++.h>
#define ll long long
using namespace std;
char dt[10][10];
int t;
struct node{
    int h,l,f;
};
int fh[4]={-1,0,1,0};
int fl[4]={0,1,0,-1};
bool cf(node f0,node c0,node f,node c){
    if(f0.h==f.h&&f0.l==f.l&&c0.h==c.h&&c0.l==c.l&&f0.f==f.f&&c0.f==c.f){
        return 1;
    }
    return 0;
}
bool ch(node f,node c){
    if(f.h==c.h&&f.l==c.l){
        return 1;
    }
    return 0;
}
bool zq(node a){
    if(a.h<0||a.h>=10||a.l<0||a.l>=10||dt[a.h][a.l]=='*'){
        return 1;
    }
    return 0;
}
node yd(node a){
    node na;
    na.h=a.h+fh[a.f];
    na.l=a.l+fl[a.f];
    na.f=a.f;
    if(zq(na)){
        na.h=a.h;
        na.l=a.l;
        na.f=(a.f+1)%4;
    }
    return na;
}
void solve(){
    node f0,c0;
    node f,c;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>dt[i][j];
            if(dt[i][j]=='F'){
                f0.h=i;
                f0.l=j;
                f0.f=0;
            }
            if(dt[i][j]=='C'){
                c0.h=i;
                c0.l=j;
                c0.f=0;
            }
        }
    }
    f=f0; 
    c=c0;
    int cnt=0;
    do{
        c=yd(c);
        f=yd(f);
        cnt++;
        if(ch(f,c)){
            break;
        }
    }while(cnt<=1000000);
    if(ch(f,c)){
        cout<<cnt<<'\n';
    }else{
        cout<<0<<'\n';
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