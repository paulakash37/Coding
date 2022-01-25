#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
   //Constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }cout << "memory is free for node with data" << value << endl;
         }
};

void print(Node* tail){
    Node* temp=tail;
    do{
        cout << tail->data << " ";
        tail=tail->next;
    }while(tail!=temp);
     cout << endl; 
     }

void insertNode(Node* &tail,int element,int data){
    //list is empty
    if(tail==NULL){
        Node* newNode = new Node(data);
        tail=newNode;
        newNode->next= newNode;
      }
      // assuming that element is present in the list
    else {
          Node* curr=tail;
          while(curr->data!=element){
              curr = curr->next;
          }
          Node* temp=new Node(data);
          temp->next= curr->next;
          curr->next=temp;
      }
}
void deleteNode(Node* &tail,int value){
    //list is empty
    if(tail == NULL){
        cout << "List is empty,please check other options" << endl;
        return;
    }
    else{
        //non - empty
        //assuming value is present in the list
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        // 1 NodeLL
        if(curr==prev){
            tail=NULL;
        }
        // >2 NodeLL
        else if (tail==curr) {
        tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}



int main(){
    Node* tail=NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    /*insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
      insertNode(tail, 9, 10);
    print(tail);
      insertNode(tail, 3, 4);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,10);
    print(tail); */
     deleteNode(tail,3);
    print(tail);

    return 0;
}