//Palindrome Check
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
   stack<char> st;
   string pal="";
   for(char ch: s){
    st.push(ch);
   }
   for(char ch: s){
    pal+=st.top();
    st.pop();
   }
   if(pal == s){
    return true;
   }
   return false;
}


int main(){
    string s;
    cin >> s;
    cout << (isPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;
}
