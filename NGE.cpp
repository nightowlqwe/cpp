#include<bits/stdc++.h>
using namespace std;

void NGE(int arr[],int n){
    stack<int> st;
    vector<int> res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i]=st.top();
        }
         st.push(arr[i]);
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
    NGE(arr,n);

}
