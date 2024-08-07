//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
             int n=str.length();
             string s;
             vector<int>v(26,0);
             for(int i=0;i<n;i++){
                 if(v[str[i]-'a']){
                     continue;
                 }
                 else{
                     v[str[i]-'a']++;
                     s+=str[i];
                 }
             }
             return s;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends