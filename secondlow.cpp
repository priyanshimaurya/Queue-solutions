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
    
   
void secondlow() {
    if (size < 2) {
        cout << "Queue does not have enough elements to find the second lowest." << endl;
        return;
    }

    int firstmin = INT_MAX;
    int secondmin = INT_MAX;
    Node* current = head;

    while (current != NULL) {
        if (current->val < firstmin) {
            secondmin= firstmin;
            firstmin = current->val;
        } else if (current->val < secondmin && current->val != firstmin) {
            secondmin = current->val;
        }
        current = current->next;
    }

    if (secondmin == INT_MIN) {
        cout << "There is no second lowest element." << endl;
    } else {
        cout << "Second lowest element: " << secondmin << endl;
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
    qu.secondlow();
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
