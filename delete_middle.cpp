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
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }
    void pop() {
        if (head == NULL) {
            return;
        }
        else {
            Node* oldhead = head;
            head = head->next;
            delete oldhead;
            size--;
            if (head == NULL){
                tail = NULL; 
            }
        }
    }
    void getempty(){
        if(head==NULL){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"queue is not empty"<<endl;
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
            return 1;
        }
        return head->val;
    }
    void deletemid() {
        if (isempty()) return; 
        int target = size / 2;
        Node* prev = NULL;
        Node* curr = head;
        for (int i = 0; i < target; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) { 
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        if (curr == tail){
            tail = prev;
        } 
        delete curr;
        size--;
    }
};
int main() {
    Queue qu;
    qu.getempty();
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.getempty();
    cout << "Front element in queue: " << qu.front() << endl;
    qu.deletemid();
    cout << "Elements in the queue after deleting the middle element:" << endl;
    while (!qu.isempty()) {
        cout << qu.front() << endl;
        qu.pop();
    }
    return 0;
}
