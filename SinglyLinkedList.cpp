#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor

    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        //Memory Free
        if(this->next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout << "Memory is free for node with data " << value << endl;

    }
};

void InsertAtHead(Node* &head,int data){
    //NewNode Create
    Node* temp=new Node(data);
    temp->next=head;
    head = temp;
}

void InsertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next =temp;
    tail=temp;
    }

void InsertAtPosition(Node* &head,Node* &tail,int position,int data){
    if(position ==1){
        InsertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt ++;
        }
        // Creating a newnode
        Node* nodetoinsert = new Node(data);
        nodetoinsert->next =temp->next;
        temp->next = nodetoinsert;

        if(temp->next == NULL)
        {
            InsertAtTail(tail,data);
            return;
        }
}

void deleteNode(Node* &head,int position){
    if(position ==1){
        Node* temp=head;
        head = head->next;
        //memory free
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last position
        Node* prev= NULL;
        Node* curr= head;
        int cnt=1;
        while(cnt < position)
        {
            prev=curr;
            curr= curr->next;
            cnt ++;
        }
        prev->next = curr ->next;
        curr->next = NULL;
        delete curr;
    }
    

}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;

}

int main(){
    Node* node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    InsertAtHead(head, 12);
     print(head);
    InsertAtHead(head, 19);
     print(head);
     InsertAtTail(tail, 46);
     print(head);
    InsertAtPosition(head,tail,3,98);
    print(head);
     InsertAtPosition(head,tail,2,167);
    print(head);
    cout << "head" << " " << head->data << endl;
    cout << "tail" << " " << tail->data << endl;
    deleteNode(head,2);
    print(head);
    cout << "head" << " " << head->data << endl;
    cout << "tail" << " " << tail->data << endl;
     deleteNode(head,1);
    print(head);
    cout << "head" << " " << head->data << endl;
    cout << "tail" << " " << tail->data << endl;
    deleteNode(head,3);
    print(head);
    cout << "head" << " " << head->data << endl;
    cout << "tail" << " " << tail->data << endl;









   /* Node* node1= new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl; */

    return 0;
}

