#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
    class Node;

public:
    LinkedList<T>()
    {

        m_spRoot = nullptr;
    }


    class Iterator;


    Iterator begin()
    {
        return Iterator(m_spRoot);
    }


    Iterator end()
    {
        return Iterator(nullptr);
    }


    void push_back(T data);

    void Traverse();

    // Iterator class can be used to
    // sequentially access nodes of linked list
    class Iterator
    {
    public:
    Iterator() noexcept :
        m_pCurrentNode (m_spRoot) { }

    Iterator(const Node* pNode) noexcept :
        m_pCurrentNode (pNode) { }

        Iterator& operator=(Node* pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }


        Iterator& operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }


        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator)
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        int operator*()
        {
            return m_pCurrentNode->data;
        }

    private:
        const Node* m_pCurrentNode;
    };

private:

    class Node
    {
        T data;
        Node* pNext;


        friend class LinkedList;
    };


    Node* GetNode(T data)
    {
        Node* pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }


    Node*& GetRootNode()
    {
        return m_spRoot;
    }

    static Node* m_spRoot;
};

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::m_spRoot = nullptr;

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node* pTemp = GetNode(data);
    if (!GetRootNode())
    {
        GetRootNode() = pTemp;
    }
    else
    {
        Node* pCrawler = GetRootNode();
        while (pCrawler->pNext)
        {
            pCrawler = pCrawler->pNext;
        }

        pCrawler->pNext = pTemp;
    }
}

template <typename T>
void LinkedList<T>::Traverse()
{
    Node* pCrawler = GetRootNode();

    while (pCrawler)
    {
        cout << pCrawler->data << " ";
        pCrawler = pCrawler->pNext;
    }

    cout << endl;
}

int main()
{
    LinkedList<int> list;


    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout << "Traversing LinkedList through method" << endl;
    list.Traverse();

    cout << "Traversing LinkedList through Iterator" << endl;
    for ( LinkedList<int>::Iterator iterator = list.begin();
            iterator != list.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    cout << endl;

    return 0;
}

