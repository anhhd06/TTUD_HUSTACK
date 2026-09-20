#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],n,k;
string request;
void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
}
int nextk(){
    int l=1,r=n;
    int mid;
    while(l<r){
        mid = (l+r)/2;
        if( a[mid] > k ){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return a[l];
}
void solve(){  
    while(1){
        cin >> request;
        if(request == "next"){
            cin >> k;
            if( a[n] <= k) cout << "-1"<<endl;
            else cout << nextk() <<endl;
        }
        else break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0; 
}