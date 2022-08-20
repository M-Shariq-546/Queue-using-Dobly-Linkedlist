#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;
    Node *previous;

public:
    Node() {}
    Node(int data, Node *next = NULL, Node *previous = NULL)
    {
        setData(data);
        setNext(next);
        setPrevious(previous);
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    void setPrevious(Node *previous)
    {
        this->previous = previous;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
    Node *getPrevious()
    {
        return previous;
    }
};
class linkedList
{
private:
    Node *head;
    Node *last;

public:
    bool isEmpty()
    {
        while (head->getNext() == NULL && head->getPrevious() == NULL)
        {
            return true;
        }
        return false;
    }
    void insertAtBegin(int val)
    {
        if (head->getNext() == NULL && head->getPrevious() == NULL)
        {
            head = new Node(val);
            cout << head->getData() << " ";
        }
        else
        {
            Node *t = new Node(val);
            t->setNext(head);
            head->setPrevious(t);
            head = t;
            cout << head->getData() << " ";
        }
    }
    void getLastElement()
    {
        last = head;
        Node * t = last->getPrevious();
        while (t != NULL)
        {
            t = t->getPrevious();
            last = last->getPrevious();
        }
        cout << last->getData();
    }
    void removeFromLast()
    {
        if(!isEmpty())
        {
        Node *t = head;
        Node *t1 = t->getNext();
        while (t1->getNext() != NULL)
        {
            t = t->getNext();
            t1 = t1->getNext();
        }
        t->setPrevious(NULL);
        delete t;
        }
    }
    int count()
    {
        int count =0;
        while(head->getNext() != NULL)
        {
            count++;
            head->getNext();
        }
        return count;
    }
};
class Queue
{
    private:
        linkedList l;
        int size;
    public:
        void setSize(int size)
        {
            this->size = size;
        }
        int getSize()
        {
            return size;
        }
        Queue(int size = 10)
        {
            setSize(size);
        }
        bool isEmpty()
        {
            return (l.isEmpty())?true:false;
        }
        bool isFull()
        {
            int count = l.count();
            return (count == size) ? false:true;
        }
        bool enqueue(int val)
        {
            if((isEmpty()))
            {
                l.insertAtBegin(val);
                return true;
            }
            return false;
        }
        void removalFromQueue()
        {
            if((isFull()))
            {
                l.getLastElement();
                l.removeFromLast();
            }
        }
        void Peek()
        {
            if((isFull()))
            {
                l.getLastElement();
            }
            else{
                cout<<"The Queue is Empty.";
            }
        }
};
int main()
{
    Queue q;
    cout<<"Queue is Empty or not ( 1 for Empty & 0 for Non-Empty) : ";
    cout<<q.isEmpty()<<endl;
    cout<<"The Data in Queue is : "<<endl;
    for(int i=0 ; i<10 ; i++)
    q.enqueue(100 + i);
    
    cout<<endl;
    cout<<"Queue is Full or not( 1 for Yes or 0 for NO) : ";
    cout<<q.isFull();
    cout<<endl;
    cout<<"The last entered number is and is still in the Queue is : ";
    q.Peek();
    cout<<endl;
    cout<<"The Element that will be eliminated on the last is and is no more in the queue: ";
    q.removalFromQueue();
    return 0;
}