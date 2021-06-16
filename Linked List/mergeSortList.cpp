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
        Node* next;
};

/*
    push() pushes the node element to the top

    value -> ..... ->lastElement
*/

void push(Node** node, int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = (*node);
    (*node) = newNode;
}


/*
    print() prints the linked list
*/
void print(Node* node){
    while(node!=NULL){
        cout<<node->value<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 8);
    push(&head, 3);
    cout<<"Before Sorting :";
    print(head);
    return 0;
}