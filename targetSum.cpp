#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){

    int n;
    cout << "Number of element: ";
    cin >> n;

    int arr[n];
    cout << "Enter array element: ";
    forn(i,n){
        cin >> arr[i];
    }

    int target;
    cout << "Target sum: ";
    cin >> target;

    int start=0,current_sum=0;

    forn(last,n){

        current_sum += arr[last];

        while(current_sum>target && start<=last){
            current_sum-=arr[start];
            start++;
        }

        if(current_sum==target){
            cout << "Subarray found from index " << start << " to " << last << endl;
            cout<<"Subarray: ";
            for (int i = start; i <= last; i++) {  // Fix the loop to include `last`
                cout << arr[i] << " ";
            }
            cout << endl;
            return 0;
        }

    }

    cout << "No subarray with the given sum found." << endl;
    return 0;


}
