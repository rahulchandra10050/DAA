4. Aim : Apply the concept of Linked list and write code to Insert and Delete an element at the beginning and atend in Doubly and Circular Linked List.

#include <iostream>
using namespace std;

class SurajDoubly {
    struct Node {
        int data;
        Node *prev, *next;
    };
    Node *head;
public:
    SurajDoubly() { head = NULL; }
    void insertBegin(int x) {
        Node *n = new Node{x, NULL, head};
        if (head) head->prev = n;
        head = n;
    }
    void insertEnd(int x) {
        Node *n = new Node{x, NULL, NULL};
        if (!head) { head = n; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }
    void deleteBegin() {
        if (!head) return;
        Node *temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }
    void deleteEnd() {
        if (!head) return;
        Node *temp = head;
        while (temp->next) temp = temp->next;
        if (temp->prev) temp->prev->next = NULL;
        else head = NULL;
        delete temp;
    }
    void display() {
        Node *t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

class SurajCircular {
    struct Node {
        int data;
        Node *next;
    };
    Node *last;
public:
    SurajCircular() { last = NULL; }
    void insertBegin(int x) {
        Node *n = new Node{x, NULL};
        if (!last) { last = n; n->next = n; }
        else { n->next = last->next; last->next = n; }
    }
    void insertEnd(int x) {
        Node *n = new Node{x, NULL};
        if (!last) { last = n; n->next = n; }
        else { n->next = last->next; last->next = n; last = n; }
    }
    void deleteBegin() {
        if (!last) return;
        Node *temp = last->next;
        if (last == temp) last = NULL;
        else last->next = temp->next;
        delete temp;
    }
    void deleteEnd() {
        if (!last) return;
        Node *temp = last->next;
        if (last == temp) { delete last; last = NULL; return; }
        while (temp->next != last) temp = temp->next;
        temp->next = last->next;
        delete last;
        last = temp;
    }
    void display() {
        if (!last) return;
        Node *temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    SurajDoubly d;
    d.insertBegin(10);
    d.insertEnd(20);
    d.insertBegin(5);
    d.display();
    d.deleteBegin();
    d.display();
    d.deleteEnd();
    d.display();

    SurajCircular c;
    c.insertBegin(10);
    c.insertEnd(20);
    c.insertBegin(5);
    c.display();
    c.deleteBegin();
    c.display();
    c.deleteEnd();
    c.display();
    return 0;
}
