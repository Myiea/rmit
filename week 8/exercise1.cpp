#include <iostream>
using namespace std;

class Node{
    private:
        int value;
        Node *next;
        Node *previous;

    public:
        Node(int value, Node *next, Node *previous){}

        void linkForward(Node *nextNode){
            this -> next = nextNode;

            if (nextNode){

            }
        }

        void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode){
            if(priorNode == nullptr){
                newNode -> linkForward(head);
                head = newNode;
            }else if (priorNode == tail){
                tail -> linkForward(newNode);
                tail = newNode;
            }else{
                newNode -> linkForward(priorNode -> next);
                priorNode = newNode;
            }
        }

        void showForward(Node *head){
            Node *temp = head;
            cout << "Forward connection: \n";
            while(temp != nullptr){
                cout << temp->value << "-->";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){}
