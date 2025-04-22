//String Reverse using Stack
#include<bits/stdc++.h>
using namespace std;

void SSP(string s){
   stack<char> st;
   for(char ch: s){
    st.push(ch);
   }
   for(char ch: s){
    cout<<st.top();
    st.pop();
   }
   cout<<endl;


}


int main(){
    string s;
    cin >> s;
    SSP(s);

}
