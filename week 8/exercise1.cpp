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
            this -> prev = nextNode;
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

int main(){
    //Testing code
    Node node1(8), node2(5), node3(3), node4(6);

    Node *head = &node1; // pointer variable
    node1.linkedNextNode(&node2);
    node2.linkedNextNode(&node3);
    node3.linkedNextNode(&node4);

    Node *tail = &node4; // pointer variable

    // show connection
    cout << "Original linked list: \n";
    showLinks(head, tail);
}
