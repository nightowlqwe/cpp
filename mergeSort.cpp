#include<bits/stdc++.h>
using namespace std;

void merg(vector<int>&arr,int left,int mid,int right){
    vector<int> temp;
    int i = left, j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= right){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[left+idx]=temp[idx];
    }

}

void mergeSort(vector<int>&arr , int left,int right){
    if(left<right){
        int mid = left + (right - left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merg(arr,left,mid,right);
    }
}

int main(){
    vector<int> arr ={12,31,35,8,32,17};
    int st=0,en=arr.size()-1;

    mergeSort(arr,st,en);

    for(int it : arr){
        cout<<it<< " ";
    }
    cout<<endl;

}
