#pragma once

#include <cassert>
#include <iostream>

// a generic sparse quad tree.
template < typename T >
class QuadTree
{
public:
    QuadTree();
    ~QuadTree();

    // Insert an elemnt into the tree.
    // Increases the size-level if necessary.
    void insert(int x, int y, const T& element);
    
    // Returns the element at the given position and a nullptr if the leaf does not exist.
    const T* get(int x, int y) const;

    // Performs a pre traversel calling Processor::process() on every node
	// and Processor::processLeaf() on all leafes.
    template<class Processor>
    void traverse(Processor& proc) {
        m_rootNode->traverse(m_rootSize, proc);
        }
private:
    class Node
    {
    public:
        Node() : m_data{}, m_children{nullptr} {}
        ~Node();

        void insert(int x, int y, int size,  const T& element);

        const T* get(int x, int y, int size) const;

        template<class Processor>
        void traverse(int size, Processor& proc);

        Node* getChild(int x, int y) { return m_children[x + 2 * y]; }
        void setChild(int x, int y, Node* child) { m_children[x + 2*y] = child; }
    private:
        int getChildIndex(int x, int y, int size) const
        {
            int cx = (x >> size) & 1;
		    int cy = (y >> size) & 1;
            
            return cx + 2 * cy;
        }

        T m_data;
        Node* m_children[4];
    };

    Node* m_rootNode;
    int m_rootSize;
};

// ********************************************************************* //
// implementation
// ********************************************************************* //

template<typename T>
QuadTree<T>::QuadTree()
    : m_rootNode(new Node()),
    m_rootSize(1)
{

}

template<typename T>
QuadTree<T>::~QuadTree()
{
    if(m_rootNode) delete m_rootNode;
}

template<typename T>
void QuadTree<T>::insert(int x, int y, const T& element)
{
    int maxVal = 1 << m_rootSize;

    while(maxVal <= x || maxVal <= y)
    {
        Node* newRoot = new Node();
        newRoot->setChild(0,0, m_rootNode);
        m_rootNode = newRoot;
        maxVal <<= 1;
        ++m_rootSize;
    }

    m_rootNode->insert(x, y, m_rootSize, element);
}

template<typename T>
const T* QuadTree<T>::get(int x, int y) const
{
    return m_rootNode->get(x, y, m_rootSize);
}

// ********************************************************************* //
template<typename T>
QuadTree<T>::Node::~Node()
{
    for(int i = 0; i < 4; ++i)
        if(m_children[i]) delete m_children[i];
}

template<typename T>
void QuadTree<T>::Node::insert(int x, int y, int size,  const T& element)
{
    if(size == 0)
    {
        m_data = element;
    }
    else
    {
        int ind = getChildIndex(x, y, size-1);
        if(!m_children[ind]) m_children[ind] = new Node();
        m_children[ind]->insert(x, y, size-1, element);
    }
}

template<typename T>
const T* QuadTree<T>::Node::get(int x, int y, int size) const
{
    if(size == 0) 
        return &m_data;

    int ind = getChildIndex(x, y, size-1);
    if(!m_children[ind]) return nullptr;
    return m_children[ind]->get(x, y, size-1);
}

template<typename T>
template<class Processor>
void QuadTree<T>::Node::traverse(int size, Processor& proc)
{
    proc.process(size, &m_data);
    if(!size) proc.processLeaf(m_data);

    for(int i = 0; i < 4; ++i)
        if(m_children[i]) 
            m_children[i]->traverse(size-1, proc);
}