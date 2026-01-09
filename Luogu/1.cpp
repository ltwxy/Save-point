#include<bits/stdc++.h>
using namespace std;
int n,m;
bool yj(int h,int l){
	if(h<0||h>=n||l<0||l>=m){
		return 0;
	}
	return 1;
} 
void solve(){
	cin>>n>>m;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='?'){
				int cnt=0;
				for(int h=i-1;h<=i+1;h++){
					for(int l=j-1;l<=j+1;l++){
						if(yj(h,l)&&a[h][l]=='*'){
							cnt++;
						}
					}
				}
				a[i][j]=cnt+'0';
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
