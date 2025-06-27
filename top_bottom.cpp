#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        val = data;
        next = NULL;
    }
};
class Queue {
    Node* head;
    Node* tail;
    int size;
public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push(int data) {
        Node*newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail =newnode;
        } else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    } 
    void pop() {
        if (head == NULL){
            return;
        } else { 
            Node* oldhead=head;
            head = head->next;
       
            delete oldhead;
            size--;
            if (head == NULL) {
                tail = NULL;
            }
        }
}    int getsize() {
        cout << "Current size of queue: " <<size << endl;
        return size;
    }
    bool isempty() {
        return head == NULL;
    }
    int front(){
                if (head == NULL) {
            return -1;
        }
        return head->val;
    }
    void topele(){
        if (head == NULL){
            return;  
        }
        cout<<"top element: "<< head->val<<endl;    
    }
    void bottomele(){
        if(isempty()){ 
            cout<<"Queue is empty: "<<endl;
        }
        else{ 
        cout<<"Bottom element of the queue: "<<tail->val<<endl;
    }
} 
}; 
int main() {
    Queue qu;
    qu.bottomele();
    qu.push(1);  
    qu.push(2);
    qu.push(3);
    qu.push(4); 
    qu.push(5); 
    qu.bottomele();
    qu.push(6);
    qu.topele();
    qu.bottomele();
    cout << "Elements in the queue:" <<endl;
    while (!qu.isempty()) {
        cout << qu.front() <<endl; 
        qu.pop();
    }
    return 0;
}