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
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> nodeMap;
        Node* curr1 = head;
        while (curr1 != nullptr)
        {
	        Node* newnode = new Node(curr1->val);
	        nodeMap[curr1] = newnode;
	        curr1 = curr1->next;
        }
        Node* curr2 = head;

        while (curr2 != nullptr)
        {
	        nodeMap[curr2]->next = nodeMap[curr2->next];
	        nodeMap[curr2]->random = nodeMap[curr2->random];
	        curr2 = curr2->next;
        }
        
        return nodeMap[head];
    }
};
