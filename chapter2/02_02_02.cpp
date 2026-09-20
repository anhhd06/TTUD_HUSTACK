#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, M = 1e3+5;
int a[N][M],m,n,Q;
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;i<=m;j++){
            cin >> a[i][j];
        }
    }
}