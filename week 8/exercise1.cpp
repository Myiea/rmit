#include <iostream>
#include <iomanip>
using namespace std;

class Node{
    private:
        int value;
        Node *next;
        Node *prev;

    public:
        Node(int value): value(value), next(nullptr), prev(nullptr) {}

        void linkedNextNode(Node *nextNode){
            next = nextNode;
            nextNode -> prev = this;
        }

        void linkedPrevNode(Node *prevNode){
            prev = prevNode;
            prevNode -> next = this;
        }

        friend void showForthLinks(Node *head);
        friend void showPrevLinks(Node *tail);
};

// Function to show links
void showForthLinks(Node *head){
    cout << "Forward links: ";
    Node *temp = head;
    while(temp != nullptr){
        cout << setw(3) << temp -> value << "--->";
        temp = temp -> next;
    } 
    cout << endl;
}

void showPrevLinks(Node *tail){
    cout << "Backward links: ";
    Node *temp = tail;
    while(temp != nullptr){
        cout << setw(3) << temp -> value << "--->";
        temp = temp -> prev;
    } 
    cout << endl;
}

void showLinks(Node *head, Node *tail){
    showPrevLinks(tail);
    showForthLinks(head);
}


// Functions to insert Node
// Note: '*&' is pass-by-reference for the pointer variable
// (same as pass-by-reference for a normal data type)
insertNode(head, tail, nullptr, &newNode1);
void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode){
    if (priorNode == nullptr){
        newNode -> linkedNextNode(headNode); // link newNode to current head
        headNode = newNode; // the newNode becomes the new head
    }

    // Insert at another position
}

int main(){
    //Testing code

    // part a
    Node node1(8), node2(5), node3(3), node4(6);

    // connect the nodes
    Node *head = &node1; // pointer variable
    
    node1.linkedNextNode(&node2);
    node2.linkedNextNode(&node3);
    node3.linkedNextNode(&node4);

    Node *tail = &node4; // pointer variable

    // show connections
    cout << "Original linked list: \n";
    showLinks(head, tail);

    // part b
    // Test insert node at the front
    cout << "\nInsert 200 after at the front: \n";
    Node newNode1(200);
    insertNode(head, tail, nullptr, &newNode1);
    showLinks(head, tail);
}
