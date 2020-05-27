#include <iostream>
#include "NodeQueue.h"



std::ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue)
{
    nodeQueue.serialize(os);
    return os;
}


NodeQueue::NodeQueue()
{
    m_front = NULL;
    m_back = m_front;
}


NodeQueue::NodeQueue(size_t count, const DataType& value)
{
    if(count <= 0)
    {
        m_front = m_back = NULL;
    }
    else
    {
        m_front = new Node(value);
        Node * current = m_front;
        for(int i = 0;--count > 0; ++i)
        {

            current->m_next = new Node(value);
            current = current->m_next;
            m_back = current;
        }
        current = NULL;
        delete current;
    }
}

NodeQueue::NodeQueue(const NodeQueue& other)
{

    if(!other.m_front)
    {
        m_front = NULL;
        m_back = NULL;
    }
    else if(!other.m_front->m_next)
    {
        m_front = new Node(other.m_front->m_data);
        m_back = m_front;
    }
    else
    {
        Node * otherCurr = other.m_front;
        m_front = new Node (otherCurr->m_data);
        Node * current = m_front;
        otherCurr = otherCurr->m_next;

        while (otherCurr)
        {
            current->m_next = new Node(otherCurr->m_data);
            current = current->m_next;
            m_back = current;
            otherCurr = otherCurr->m_next;
        }
        current = NULL;
        otherCurr = NULL;
        delete current;
        delete otherCurr;
    }
}

NodeQueue::~NodeQueue()
{
    size_t count = 0;
    if(m_front)
    {
        m_back = NULL;
        Node * del = m_front;
        while(m_front)
        {
            m_front = m_front->m_next;
            del->m_next = NULL;
            delete del;
            del = m_front;
            ++count;
        }
        del = NULL;
        delete del;
    }
    m_front = NULL;
    delete m_front;

}


NodeQueue& NodeQueue::operator= (const NodeQueue& rhs) 
{
    if(this == &rhs)
        return *this;
    if(m_front)
    {
        m_back = NULL;
        Node * del = m_front;
        while(m_front)
        {
            m_front = m_front->m_next;
            del->m_next = NULL;
            delete del;
            del = m_front;
        }
        del = NULL;
        delete del;
    }

    if(!rhs.m_front)
    {
        m_front = m_back = NULL;
        return *this;
    }
    else if(!rhs.m_front->m_next)
    {
        m_front = new Node(rhs.m_front->m_data);
        m_back = m_front;
        return *this;
    }
    else
    {
        Node * otherCurr = rhs.m_front;
        m_front = new Node (otherCurr->m_data);
        Node * current = m_front;

        otherCurr = otherCurr->m_next;
        while (otherCurr)
        {
            current->m_next = new Node(otherCurr->m_data);
            current = current->m_next;
            m_back = current;
            otherCurr = otherCurr->m_next;
        }
        current = NULL;
        otherCurr = NULL;
        delete current;
        delete otherCurr;
        return *this;
    }
}


DataType& NodeQueue::front()
{
    return m_front->m_data;
}

const DataType& NodeQueue::front() const
{
    return m_front->m_data;
}


DataType& NodeQueue::back()
{
    return m_back->m_data;
}

const DataType& NodeQueue::back() const
{
    return m_back->m_data;
}

void NodeQueue::push(const DataType& value)
{
    if(!m_front)
    {
        m_front = new Node(value);
        m_back = m_front;
    }
    else
    {
        Node * temp = new Node(value);
        m_back->m_next = temp;
        m_back = temp;
        temp = NULL;
    }
}


void NodeQueue::pop()
{
    if(!m_front)
    {
        return;
    }
    else if(!m_front->m_next)
    {
        m_back = NULL;
        delete m_front;
        m_front = NULL;
    }
    else
    {
        Node * temp = m_front;
        m_front = m_front->m_next;
        delete temp;
        temp = NULL;
    }
}

size_t NodeQueue::size() const
{
    size_t count = 0;
    if(m_front)
    {
        Node * current = m_front;
        while(current)
        {
            ++count;
            current = current->m_next;
        }
        current = NULL;
        delete current;
    }
    return count;
}


bool NodeQueue::empty() const
{
    if(!m_front)
        return true;
    return false;
}

bool NodeQueue::full() const
{
    return false;
}


void NodeQueue::clear()
{
    if(m_front)
    {
        Node * del = m_front;
        while(m_front)
        {
            m_front = m_front->m_next;
            del->m_next = NULL;
            delete del;
            del = m_front;
        }
        del = NULL;
        delete del;
    }
}

void NodeQueue::serialize(std::ostream& os) const
{
    using std::endl;

    if(!m_front)
    {
        os << "No list to display" << endl;
    }
    else
    {
        Node * current = m_front;
        os << endl;

        size_t i = 1;
        while(current)
        {
            os << "Node " << i << " is: " << current->GetData()<< endl;
            ++i;
            current = current->getNext();
        }
    }
}