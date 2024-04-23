//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int firstElement(int n) {
        if (n <= 2) return 1;
        long long a = 1, b = 1, c;
        for (int i = 3; i <= n; ++i) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return static_cast<int>(b);
    }
    
private:
    const int MOD = 1000000007;
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends