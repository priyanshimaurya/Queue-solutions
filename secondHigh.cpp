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
    
   
void secondhigh() {
    if (size < 2) {
        cout << "Queue does not have enough elements to find the second highest." << endl;
        return;
    }

    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    Node* current = head;

    while (current != NULL) {
        if (current->val > firstMax) {
            secondMax = firstMax;
            firstMax = current->val;
        } else if (current->val > secondMax && current->val != firstMax) {
            secondMax = current->val;
        }
        current = current->next;
    }

    if (secondMax == INT_MIN) {
        cout << "There is no second highest element." << endl;
    } else {
        cout << "Second highest element: " << secondMax << endl;
    }
}


};
int main() {
    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);
    qu.secondhigh();
    cout << "Popped element: " << qu.front() << endl;
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
