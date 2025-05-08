// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QString>

class Node {
public:
    QString email;
    QString password;
    Node *next;

    Node(const QString &email, const QString &password) : email(email), password(password), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addUser(const QString &email, const QString &password) {
        Node *newNode = new Node(email, password);
        newNode->next = head;
        head = newNode;
    }

    bool contains(const QString &email, const QString &password) const {
        Node *current = head;
        while (current != nullptr) {
            if (current->email == email && current->password == password) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

private:
    Node *head;
};

#endif // LINKEDLIST_H
