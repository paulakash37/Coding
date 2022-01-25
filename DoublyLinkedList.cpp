#include<iostream>
using namespace std;
class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    //Destructor
    ~Node(){
        int value = this ->data;
        if(this->next !=NULL){
            delete next;
            this->next = NULL;
            } cout << "Memory is free for node with data " << value << endl;
    }
};

//Traversing a LinkedList
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " " ;
        temp = temp->next;
    }cout << endl;
}
int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len ++;
        temp= temp->next;
    } return len;
}
void insertAthead(Node* &head,Node* &tail,int data){
    //Empty List
    if(head== NULL){
        Node* temp =new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }

}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp= new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp; 
    }
}

void insertAtposition(Node* &head,Node* &tail,int position,int data)
{
    //insert at start
    if(position==1){
        insertAthead(head,tail,data);
        return;
        }
    Node* temp=head;
    int cnt=1;
    while(cnt < position-1)
    {
        temp=temp->next;
        cnt ++;
     }

        //insert at lastposition
     if(temp->next== NULL){
         insertAtTail(head,tail,data);
         return;
         }

         //create a newnode
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev= nodetoinsert;
    temp->next= nodetoinsert;
    nodetoinsert->prev=temp;

}

void deletenode(Node* &head,int position){
    //delete first node
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head= temp->next;
         temp->next=NULL;
         delete temp;
    }
    else {
    Node* curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt < position){
        prev=curr;
        curr = curr->next;
        cnt ++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next->prev= curr;
    curr->next = NULL;
    delete curr;
    }
}

int main()
{
    Node* node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
   /* Node* head= NULL;
    Node* tail=NULL;*/
    print(head);
    cout << getLength(head) << endl;
    insertAthead(head,tail,76);
    print(head);
    cout << getLength(head) << endl;
    insertAtTail(head,tail,67);
    print(head);
    insertAtposition(head,tail,2,3);
    print(head);
  insertAtposition(head,tail,3,81);
    print(head);
    deletenode(head,2);
    print(head);
    deletenode(head,3);
    print(head);
   

   return 0;

}