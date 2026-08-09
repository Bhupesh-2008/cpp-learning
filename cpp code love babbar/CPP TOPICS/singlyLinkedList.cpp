#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

void InsertAtHead(Node*&head,int d){
    //create new node
    Node* temp= new Node(d);
    temp->next= head;
    head=temp;
}

void InsertAtTail(Node*&tail, int d){
    //create new node
    Node* temp= new Node(d);
    tail->next= temp;
    tail=tail->next;
}

void InsertAtPosition(Node*&head, int position, int data){
    //inserting at head
    if(position==1){
        InsertAtHead(head,data);
        return;
    }

    //traverse till (n-1)th position
    Node*temp= head;

    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    } 

    //inserting at tail
    if(temp->next==NULL){
        InsertAtTail(head,data);
        return;
    }                

    //creating a new node for d
    Node*nodeToInsert= new Node(data);
    nodeToInsert->next= temp->next;
    temp->next= nodeToInsert;
}

void print(Node* &head){
    Node*temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }cout<<endl;
}

int main(){
    Node* node1= new Node(25);
    // cout<< node1->data<<endl;
    // cout<< node1->next<<endl;

    //head pointing to node1
    Node*head= node1;
    Node*tail= node1;
    print (head);

    InsertAtTail(tail,54);
    print(head);

    InsertAtTail(tail,48);
    print(head);

    InsertAtPosition(head,3,40);
    print(head);

    InsertAtPosition(head,1,40);
    print(head);

    // InsertAtHead(head,54);
    // print(head);

    // InsertAtHead(head,12);
    // print(head);

    return 0;
}