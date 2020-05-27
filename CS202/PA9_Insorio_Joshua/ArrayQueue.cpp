#include <iostream>
#include "ArrayQueue.h"
#include "DataType.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, const ArrayQueue& arrayQueue)
{
    arrayQueue.serialize(os);
    return os;
}

ArrayQueue::ArrayQueue()
{
    m_size = 0;
    m_back = -1;
    m_front = m_back;
}


ArrayQueue::ArrayQueue(size_t count, const DataType& value)
{
    if (count <= 0 || count > ARRAY_MAX)
    {
        m_size = 0;
        m_front = -1;
        m_back = -1;
    }
    else
    {
        size_t i = 0;
        m_size = count;
        m_front = i;
        for(;i < m_size;i++)
        {
            m_back = i;
            m_array[i] = value;
        }
    }
}

ArrayQueue::ArrayQueue(const ArrayQueue& other)
{
    if(other.m_size <= 0 || other.m_size > ARRAY_MAX)
    {
        m_size = 0;
        m_front = -1;
        m_back = -1;
        return;
    }
    else
    {
        m_size = other.m_size;
        m_front = other.m_front;
        m_back = other.m_back;

        for(size_t i = m_front; i < m_size; ++i)
        {
            m_array[i] = other.m_array[i];
        }
    }
}


ArrayQueue::~ArrayQueue() 
{
    clear();
}


ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs)
{
    if(this != &rhs)
    {
        clear();
        m_size = rhs.m_size;
        m_front = rhs.m_front;
        m_back = rhs.m_back;
        size_t i = m_front;
        while (i < m_size)
        {
            m_array[i] = rhs.m_array[i];
            ++i;
        }
    }
    return *this;
}

DataType& ArrayQueue::front()
{
    return m_array[m_front];
}


const DataType& ArrayQueue::front() const
{
    return m_array[m_front];
}

DataType& ArrayQueue::back()
{
    return m_array[m_back];
}

const DataType& ArrayQueue::back() const
{
    return m_array[m_back];
}

void ArrayQueue::push(const DataType& value)
{
    if(full())
    {
        return;
    }
    else if(empty())
    {
        m_back = 0;
        m_front = 0;
        m_size = 1;
    }
    else
    {
        m_back = (m_back+1) % ARRAY_MAX;
        ++m_size;
    }
    m_array[m_back] = value;
}

void ArrayQueue::pop()
{
    if(empty())
        return;
    else if(m_back == m_front)
    {
        m_size = 0;
        m_front = m_back = -1;
    }
    else
    {
        m_front=(m_front+1)% ARRAY_MAX;
        --m_size;
    }
}

size_t ArrayQueue::size() const
{
    return m_size;
}


bool ArrayQueue::empty() const
{
    return (m_front == -1 && m_back == -1);
}


bool ArrayQueue::full() const
{
    return (m_size == ARRAY_MAX);
}


void ArrayQueue::clear()
{
    if(empty())
        return;
    else
    {
        DataType dummy;
        while(m_size--)
        {
            m_array[m_size] = dummy;
        }
    }
}


void ArrayQueue::serialize(std::ostream& os) const
{
    if(m_size > 0)
    {
        os << endl;
        for(size_t i = m_front; i <= m_back; ++i)
        {
            os << m_array[i] << endl;
        }
    }
    else
        std::cout << "Array Empty!" << std::endl;
}
