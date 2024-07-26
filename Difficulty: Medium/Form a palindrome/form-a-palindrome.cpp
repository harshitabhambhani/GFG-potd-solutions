//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[501][501];
    int lcs(string s,string rev,int i,int j)
    {
        if(i == s.size() || j == rev.size())    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i] == rev[j]){
            return dp[i][j] = 1 + lcs(s,rev,i+1,j+1);
        }
        else{
            return dp[i][j] = max(lcs(s,rev,i+1,j),lcs(s,rev,i,j+1));
        }
    }
    int countMin(string str){
        string rev = str;
        reverse(rev.begin(),rev.end());
        memset(dp,-1,sizeof(dp));
        return str.size() - lcs(str,rev,0,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends