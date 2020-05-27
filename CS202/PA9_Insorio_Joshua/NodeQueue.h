#ifndef NodeQueue_H_
#define NodeQueue_H_

#include "DataType.h"
#include "NodeList.h"


class NodeQueue{
    friend std::ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue);
public:
    NodeQueue();
    NodeQueue(size_t count, const DataType& value); 
    NodeQueue(const NodeQueue& other);
    ~NodeQueue();  

    NodeQueue& operator= (const NodeQueue& rhs);

    DataType& front();
    const DataType& front() const;

    DataType& back();
    const DataType& back() const;

    void push(const DataType& value);
    void pop();

    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream& os) const;

private:
    Node *m_front;
    Node *m_back;
};

#endif //NodeQueue_H_