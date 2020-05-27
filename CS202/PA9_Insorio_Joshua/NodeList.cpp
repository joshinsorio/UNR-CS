#include <iostream>
#include "NodeList.h"


std::ostream& operator<< (std::ostream& os, const Node& otherNode)
{
    os << "Data value is: " << otherNode.m_data << std::endl;
    return os;
}

Node::Node() : m_next( NULL )
{}    

Node::Node(const DataType& data, Node* next) : m_next( next ), m_data( data )
{}

Node::Node(const Node& other) : m_next( other.m_next ), m_data( other.m_data )
{}

DataType& Node::getData()
{ 
	return m_data;
}


DataType& Node::setData(int intVal, double doubleVal)
{
    m_data.setIntVal(intVal);
    m_data.setDoubleVal(doubleVal);
    return m_data;
}

const DataType& Node::GetData() const
{ 
    return m_data;
}

Node* Node::getNext() const 
{
    return m_next;
}
