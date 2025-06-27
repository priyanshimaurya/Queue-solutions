#include <iostream>
#include <deque>
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
            throw runtime_error("Queue is empty");
        }
        return head->val;
    }

    void window_max(int k) {
        if (k <= 0 || k > size) {
           cout<<"invalid size"<<endl;
        }

        deque<int> dq;
        Node* current = head;
        int index = 0;

        
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && dq.back() < current->val) {
                dq.pop_back();
            }
            dq.push_back(current->val);
            current = current->next;
        }

        cout << "Max in window of size " << k << ": " << dq.front() << endl;

        
        for (int i = k; i < size; ++i) {
            while (!dq.empty() && dq.back() < current->val) {
                dq.pop_back();
            }
            dq.push_back(current->val);

            if (dq.front() == head->val) {
                dq.pop_front();
            }

            head = head->next;
            current = current->next;

            cout << "Max in window of size " << k << ": " << dq.front() << endl;
        }
    }
};

int main() {
    Queue qu;
    qu.push(1);
    qu.push(3);
    qu.push(-1);
    qu.push(-3);
    qu.push(5);
    qu.push(3);
    qu.push(6);
    qu.push(7);
    int k = 3;
    qu.window_max(k);

    return 0;
}
