/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if(root==NULL)
        {
            return root;
        }
        queue<Node*>s;
        s.emplace(root);
        while(!s.empty())
        {
            int n=s.size();
            vector<Node*>v(n,0);
            for(int i=0;i<n;i++)
            {
                auto c=s.front();
                s.pop();
                if(c->left)
                {
                    s.emplace(c->left);
                }
                if(c->right)
                {
                    s.emplace(c->right);
                }
                v[i]=c;
            }
            for(int i=0;i<n-1;i++)
            {
               v[i]->next=v[i+1];
            }
            v[n-1]->next=NULL;
        }
        return root;
        
    }
};