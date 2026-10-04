#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int M[N][N],n,m,maxArea = 0;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> M[i][j];
        }
    }

}
//tinh max S tai hang i
void tinh(int i){
    stack<int> st;

    for(int j = 0; j < m; j++){
        while( !st.empty() && M[i][j] <= M[i][st.top()]){
            int height = M[i][st.top()];
            st.pop();
            int width;
            width = st.empty() ? j : j - st.top() - 1;
            maxArea = max (maxArea,height*width);
        }
        st.push(j);
    }
    while(!st.empty()){
        int height = M[i][st.top()];
        st.pop();
        int width = st.empty() ? m : m - st.top() - 1;
        maxArea = max (maxArea,height*width);
    }
}


void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0) M[i][j] = M[i][j];
            else if(M[i][j]!=0) M[i][j] = M[i-1][j] + 1;

        }
        tinh(i);
    }
    cout << maxArea;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}