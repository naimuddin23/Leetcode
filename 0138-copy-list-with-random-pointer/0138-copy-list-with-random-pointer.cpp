/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert(Node * &head, Node* &tail , int data){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node *> m;
        Node * original = head, *cloneHead = NULL, *cloneTail = NULL;

        while(original != NULL){
            insert(cloneHead,cloneTail,original->val);
            original = original -> next;
        }

        original = head;
        Node * temp = cloneHead;

        while(original != NULL){
            m[original] = temp;
            original = original -> next;
            temp = temp -> next;
        }

        original = head;
        temp = cloneHead;

        while(temp != NULL){
            temp -> random = m[original->random];
            temp = temp -> next;
            original = original -> next;
        }





        return cloneHead;
        
    }
};