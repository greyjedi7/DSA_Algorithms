#include<bits/stdc++.h>
using namespace std;

/*
    class Node acts a node to store the linked list elements
    1. Value -> Stores the value of the Node
    2. next -> Stores the address of it's successor node
*/

class Node {
    public:
        int value;
        Node *next;
};

/*
    add() pushes the node element to the top

    value -> ..... -> lastElement
*/

void addNode(Node** node, int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = (*node);
    (*node) = newNode;
}


/*
    reverseList() reverses the list
*/

void revereList(Node** head){
    Node* prev = NULL;
    Node* curr = (*head);
    Node* nxt = (*head)->next;
    while(nxt!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;
    (*head) = curr;
}

/*
    print() prints the linked list
*/

void print(Node* node){
    while(node != NULL){
        cout<<node->value<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);  
    print(head);
    revereList(&head);
    print(head);
    return 0;
}