#include "NodeList.h"

//Constructors
//Default ctor
NodeList::NodeList()
{
    m_head = NULL;
}

//Parameterized ctor
NodeList::NodeList(size_t count, const DataType& value)
{
    if (count <= 0)
    {
        m_head = NULL;
    }

    else
    {
        m_head = new Node (value, NULL);
        Node* temp = m_head;
        for (size_t i = 0; i < count - 1; i++)
        {
            temp->m_data = value;
            temp->m_next = new Node;
            temp = temp->m_next;
        }
        temp->m_data = value;
        temp->m_next = NULL;
    }
}
//Copy ctor
NodeList::NodeList(const NodeList& other)
{
	m_head = new Node;

	Node *curr1 = m_head;
	for (Node *curr = other.m_head; curr != NULL; curr = curr->m_next)
	{
		Node *curr2 = curr->m_next;
		curr1->m_data = curr->m_data;

		if (curr2 != NULL)
		{
			curr1->m_next = new Node;
		}
		else 
		{
			curr1->m_next = NULL;
		}
		
		curr1 = curr1->m_next;
	}
}

//Dtor
NodeList::~NodeList()
{
    delete m_head;
}

//Operator= 
NodeList& NodeList::operator= (const NodeList& rhs)
{
    if (m_head)
	{
		delete[] m_head;
	}

	m_head = new Node;

	Node *curr1 = m_head;
	for (Node *curr = rhs.m_head; curr != NULL; curr = curr->m_next)
	{
		Node *curr2 = curr->m_next;
		curr1->m_data = curr->m_data;

		if (curr2 != NULL)
		{
			curr1->m_next = new Node;
		}
		else
		{
			curr1->m_next = NULL;
		} 
		
		curr1 = curr1->m_next;
	}
    return *this;
}

//Operator<<
std::ostream& operator<<(std::ostream& os, const NodeList& nodeList)
{
    for (int i = 0; i < nodeList.size(); i++)
    {
        os << nodeList[i] << " ";
    }
    return os;
}

//Operator []
DataType& NodeList::operator[] (size_t position)
{
    Node* curr = m_head;
    for (int i = 0; i < position; i++)
    {
        curr = curr->m_next;
    }
    return curr->m_data;
}

//Const Operator []
const DataType& NodeList::operator[] (size_t position) const
{
    Node* curr = m_head;
    for (int i = 0; i < position; i++)
    {
        curr = curr->m_next;
    }
    return curr->data();
}

//Methods
Node* NodeList::front()
{
	if (m_head == NULL)
	{
		return NULL;
	}
	else
	{
		return m_head;
	}
}

Node* NodeList::back()
{
    if (m_head == NULL)
	{
		return NULL;
	}

    Node* temp = m_head;
    while (temp != NULL)
    {
        temp = temp->m_next;
    }
    return temp;
}

Node* NodeList::find(const DataType& target, Node* &previous, const Node * start)
{
	int counter = 0;

	for (Node *curr = m_head; curr != NULL; curr = curr->m_next, counter++)
	{
		if (curr->m_data == target)
		{
			if(counter > 0)
			{
				previous = m_head;
				
				for (int i = 0; i < counter - 1; i++)
				{
					previous = previous->m_next;
				}

				return curr;
			}
			else
			{
				previous = NULL;
				return curr;
			}

		}

	}
	previous = NULL;
	return NULL;
}

Node* NodeList::insertAfter(const DataType& target, const DataType& value)

{
    Node* temp = m_head;
    while (temp != NULL)
    {
        temp = temp->m_next;
        if (temp->m_data == target)
        {
            Node *insertNode = new Node(value);
			Node *tempPt = temp->m_next;
			temp->m_next = insertNode;
			insertNode->m_next = tempPt;
			return insertNode;
        }
    }
    return NULL;
}
Node* NodeList::insertBefore(const DataType& target, const DataType& value)

{

	Node *insertNode;
	Node *curr;
	for (curr = m_head; curr != NULL; curr = curr->m_next)
	{
		if (curr->m_data == target)
		{
			Node *temp = insertNode;
			insertNode = new Node(value, curr);
			temp->m_next = insertNode;
			break;
        }

		insertNode = curr;
	}

	return curr->m_next;
}

Node * NodeList::erase(const DataType &target)
{
	Node* temp1 = m_head;
	Node* temp2 = m_head->m_next;

	if (temp1->m_data == target) 
	{
		m_head = temp2;
		delete temp1;
		return m_head;
	}

	while (!(temp2->m_data == target)) 
	{
		if (temp2 == NULL) 
		{
			return NULL;
		}
		temp1 = temp1->m_next;
		temp2 = temp2->m_next;
	}

	temp1->m_next = temp2->m_next;
	delete temp2;

	return temp1->m_next;
}

size_t NodeList::size() const
{
    size_t counter = 0;
    Node* temp = m_head;
    while (temp != NULL)
    {
        counter++;
        temp = temp->m_next;
    }
    return counter;
}
bool NodeList::empty() const
{
    if (m_head == NULL)
    {
        return true;
    }
    return false;
}
void NodeList::clear()
{
	for (Node *temp = m_head; temp != NULL; m_head = m_head->m_next)
	{
		temp = m_head;
		delete temp;
	}

}