#include<iostream>
#include <climits> // for INT_MIN
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
        }
        else {
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
            if (head == NULL) {
                tail = NULL;
            }
        }
    }

    void getsize() {
        cout << "Size of queue is: " << size << endl;
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
    void shortqueue() {
    Node* curr = head;
    while (curr != NULL) {
        Node* nextnode = curr->next;
        while (nextnode != NULL) {
            if (curr->val > nextnode->val) {
                int temp = curr->val;
                curr->val = nextnode->val;
                nextnode->val = temp;
            }
            nextnode = nextnode->next;
        }
        curr = curr->next; 
    }
}


};

int main() {
    Queue qu;
    qu.push(-11);
    qu.push(-2);
    qu.push(13);
    qu.push(4);
    qu.push(57);
    qu.push(69);
    qu.push(-12);
    qu.push(8);
    qu.shortqueue();
    cout<<"popped element in queue:- "<<qu.front()<<endl;
    qu.pop();
    qu.getsize();
    qu.isempty();
    cout << "Elements in the queue:" << endl;
    while (!qu.isempty()) {
        cout << qu.front() << endl;
        qu.pop();
    }

    return 0;
}
