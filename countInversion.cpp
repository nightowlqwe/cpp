#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int merg(vector<int> &arr,int st,int mid,int en){
    vector<int>temp;
    int i=st,j=mid+1;
    int cnt=0;
    while(i<=mid&&j<=en){
        if(arr[i]>arr[j]){
          cnt+=mid-i+1;
          temp.pb(arr[j]);
          j++;
        }
        else{
            temp.pb(arr[i]);
            i++;
        }
    }

    while(i<=mid){
        temp.pb(arr[i]);
        i++;
    }

    while(j<=en){
        temp.pb(arr[j]);
        j++;
    }
    for(int k=0;k<temp.size();k++){
        arr[st+k]=temp[k];
    }
    return cnt;
}

int countInv(vector<int> &arr,int st,int en){
    int inv=0;
    if(st<en){
        int mid=st+(en-st)/2;

        inv+=countInv(arr,st,mid);
        inv+=countInv(arr,mid+1,en);
        inv+=merg(arr,st,mid,en);
    }
    return inv;
}

int main(){
    vector<int> arr = {3,2,1,4,6,5};
    cout<<countInv(arr,0,arr.size()-1);
}
