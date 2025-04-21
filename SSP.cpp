//Stock Span Problem
#include<bits/stdc++.h>
using namespace std;

void SSP(int arr[],int n){
    stack<int> st;
    vector<int> res(n,1);

    for(int i = 0; i < n; i++){
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }
    for(int val: res){
        cout<<val<<" ";
    }
    cout<<endl;

}


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    SSP(arr,n);

}
