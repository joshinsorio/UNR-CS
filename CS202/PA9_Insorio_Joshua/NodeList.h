#ifndef NODELIST_H_
#define NODELIST_H_

#include "DataType.h"

class Node
{

    friend class NodeQueue;
    friend std::ostream& operator<< (std::ostream& os, const Node& srcNode);
public:
    Node();
    Node(const DataType& data, Node* next = NULL);
    Node(const Node& other);
    DataType& getData();
    DataType& setData(int intVal, double doubleVal);
    const DataType& GetData() const;
    Node* getNext() const;

private:
    Node* m_next;
    DataType m_data;
};

#endif //NODELIST_H_
