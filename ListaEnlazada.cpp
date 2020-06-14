#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *head,*tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertar(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }
    void print() {
        Node *ptr;
        ptr = head;
        while (ptr != NULL) {
            cout<< ptr->data <<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    void remove(int n)
    {
        Node *temp1 = head;
        if(n == 1)
        {
            head = temp1->next;
            delete temp1;
            return;
        }
        for(int i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }


};
int main()
{
    LinkedList a;
    a.insertar(3);
    a.insertar(5);
    a.insertar(2);
    a.insertar(6);
    a.print();
    a.remove(3);
    a.print();
}
