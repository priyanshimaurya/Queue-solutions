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
        } else {
            Node* oldhead = head;
            head = head->next;
            delete oldhead;
            size--;
            if (head == NULL) {
                tail = NULL;
            }
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
   void removeduplicate() {
    Node* current = head;
    while (current != NULL) {
        Node* nextnode = current;
        while (nextnode->next != NULL) {
            if (nextnode->next->val == current->val) {
                Node* duplicate = nextnode->next;
                delete duplicate;
                size--;
            } else {
                nextnode = nextnode->next;
            }
        }
        current = current->next;
    }
}


};
int main() {
    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(3);
    qu.push(2);
    qu.push(6);
   
    qu.removeduplicate();
    cout << "Elements in the queue:" << endl;
    while (!qu.isempty()) {
        cout << qu.front() << endl;
        qu.pop();
    }

    return 0;
}
