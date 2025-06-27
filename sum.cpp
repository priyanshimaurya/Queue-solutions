#include<iostream>
using namespace std;
class Node {
public:
    int val;      
    Node* next;   
    Node* prev;    
    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};
class Queue {
    Node* head;   
    Node* tail;   
    int size;     
public:
    Queue() {
        head = NULL;
        tail = NULL; 
        size = 0;
    }
    void push(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } 
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        size++;
    }
    void pop() {
        if (head==NULL) {
            return; 
        } else {
            Node* oldhead = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail=NULL; 
            }
            delete oldhead;
            size--;
        }
    }
    int getsize() {
        cout << "Current size of queue: " << size << endl;
        return size;
    }
    bool isempty() {
        return head == NULL;
    }
    int front() {
        if (head == NULL) {
            return -1; 
        }
        return head->val;
    }
    void SumofQueue(){
        int sum=0;
        Node* curr=head;
        while(curr!=NULL){
            sum+=curr->val;
            curr=curr->next;
        }
        cout<<"sum of element in queue:- "<<sum<<endl;
    }
};

int main() {
    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    
    qu.SumofQueue();
    cout << "Popped element: " << qu.front() << endl;
    qu.pop();
    cout<<"popped element: "<<qu.front()<<endl;
    qu.pop();
    qu.getsize();
    cout << "Front element: " << qu.front() << endl;
    
    
    
    cout << "Elements in the queue:" << endl;
    while (!qu.isempty()) {
        cout << qu.front() << endl;
        qu.pop();
    }
    return 0;
}
