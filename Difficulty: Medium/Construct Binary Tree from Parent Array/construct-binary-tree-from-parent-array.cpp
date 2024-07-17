//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent)
    {   //Lets Now Analuse the Time and Space Complexity 
       //So Here It takes a theta(N) Time also for each Insertion O(1) so ~ O(N) On average
        unordered_map<int, vector<int>> m;
        //For the Map in worst Case O(N) 
        int rootValue;
        for (int i = 0; i < parent.size(); i++)
        {
            m[parent[i]].push_back(i);
            if(parent[i] == -1 ) rootValue = i ;
        }
        // Now I do have a map as it is sorted acc to the Keys so -1 Represents the ROOT
        // Query for the Children
        Node *root = new Node(rootValue);
        queue<Node *> q;
        //Queue Building the Tree Level Wise Fashion that Takes a O(H) 
        //Overall Time COmplexiy is O(H) + O(N) 
        //Space is O(N)
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            // Now To Attach the Children
            if (m.find(node->data) !=m.end())
            {
                vector<int>children = m[node->data];
                Node *newNode = new Node(children[0]);
                node->left = newNode;
                q.push(newNode);
                if (children.size() > 1)
                {
                    Node *mewMode = new Node(children[1]);
                    node->right = mewMode;
                    q.push(mewMode);
                }
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends