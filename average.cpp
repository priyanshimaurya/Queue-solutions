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
    
    void average() {
        int sum = 0;
        float avg;
        Node* temp = head;
        
        while (temp != NULL) {
            sum += temp->val;
            temp = temp->next;
        }
        
        if (size != 0) {
            avg = static_cast<float>(sum) / size;
            cout << "Average number of queue elements is: " << avg << endl;
        } else {
            cout << "Queue is empty."<< endl;
        }
    }
};
int main() {
    Queue qu;
    
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.average();
    
    cout << "Front element: " << qu.front() << endl;
    
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
