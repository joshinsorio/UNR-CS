#ifndef NodeStack_HPP_
#define NodeStack_HPP_

template <class T>
class Node;

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& srcNode);

template <class T>
class NodeStack;

template <class T>
std::ostream& operator<<(std::ostream& os, const NodeStack<T>& NodeStack);

//template class declaration
template <class T>
class Node{

  friend class NodeStack<T>;  //allows direct accessing of link and data from class NodeStack

  friend std::ostream& operator<< (std::ostream& os, const Node<T>& srcNode)
  {
    os << "Data value is: " << srcNode.m_data << std::endl;
    return os;
  }

  public:
    Node() : m_next( NULL ){}
    Node(const T& data, Node<T>* next = NULL) : m_next( next ), m_data( data )
    {}

    Node(const Node<T>& other) : m_next( other.m_next ), m_data( other.m_data )
    {}
    
    T& GetData()
    {  
	    return m_data;
    }

    const T& GetData() const
    { 
      return m_data;
    }

    T& SetData(int intVal, double doubleVal)
    {
      m_data.SetIntVal(intVal);
      m_data.SetDoubleVal(doubleVal);
      return m_data;
    }

    Node<T>* GetNext() const {
      return m_next;
    }

  private:
    Node<T>* m_next;
    T m_data;
};

//templated class declaration
template <class T>
class NodeStack{
  friend std::ostream& operator<< < >(std::ostream& os, const NodeStack<T>& NodeStack);
  public:
    NodeStack();
    NodeStack(size_t count, const T& value);
    NodeStack(const NodeStack<T>& other);
    ~NodeStack();
    NodeStack<T>& operator= (const NodeStack<T>& rhs);
    T& top();
    const T& top() const;
    void push(const T& value);
    void pop();
    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream& os) const;

  private:
    Node<T>* m_top;
};

//template class implemenations

//operator<<:
template <class T>
std::ostream& operator<<(std::ostream& os, const NodeStack<T>& srcstack)
{
  srcstack.serialize(os);
  return os;
}


//Default constructor:
template <class T>
NodeStack<T>::NodeStack()							    		//(1)
{
  m_top = NULL;
}

//Parameterized constructor:
template <class T>
NodeStack<T>::NodeStack(size_t count, const T& value)
{
  if(count <= 0)
  {
    m_top = NULL;
  }
  else
  {
    m_top = new Node<T>(value);
    Node<T>* temp = m_top;
    while (--count > 0)
    {
      temp = new Node<T>(value);
      temp->m_next = m_top;
      m_top = temp;
    }
    //deallocate current
    temp = NULL;
  }
}


//Copy constructor:
template <class T>
NodeStack<T>::NodeStack(const NodeStack<T>& other)					//(3)
{
  if(!other.m_top)
  {
    m_top = NULL;
  }
  else if(!other.m_top->m_next)
  {
    m_top = new Node<T>(other.m_top->m_data);
  }
  else
  {
    Node<T>* otherCurr = other.m_top;
    m_top = new Node<T>(otherCurr->m_data);
    Node<T>* current = m_top;
    otherCurr = otherCurr->m_next;

    while (otherCurr)
    {
      current->m_next = new Node<T>(otherCurr->m_data);
      current = current->m_next;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
  }
}

//dtor 
template <class T>
NodeStack<T>::~NodeStack()							   			//(4)
{
  std::cout << std::endl << "NodeStack D-tor called!" << std::endl;
  size_t count = 0;
  //convert into a LLL, then delete it
  if(m_top)
  {
    Node<T>* del = m_top;
    while(m_top)
    {
      m_top = m_top->m_next;
      del->m_next = NULL;
      delete del;
      del = m_top;
      ++count;
    }
    del = NULL;
    delete del;
  }
    m_top = NULL;
    delete m_top;

}

//operator=
template <class T>
NodeStack<T>& NodeStack<T>::operator= (const NodeStack<T>& rhs)			//(5)
{
  if(this == &rhs)
    return *this;
//delete any list that current exists
    if(m_top)
      clear();

  if(!rhs.m_top)
  {
    m_top = NULL;
  }
  else if(!rhs.m_top->m_next)
  {
    m_top = new Node<T>(rhs.m_top->m_data);
  }
  else
  {
    Node<T>* otherCurr = rhs.m_top;
    m_top = new Node<T>(otherCurr->m_data);
    Node<T>* current = m_top;

    otherCurr = otherCurr->m_next;
    while (otherCurr)
    {
      current->m_next = new Node<T>(otherCurr->m_data);
      current = current->m_next;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
  }
  return *this;
}

//top method
template <class T>
T& NodeStack<T>::top()
{
  std::cout << "top() method called" << std::endl;
  return m_top->m_data;
}

//const top method
template <class T>
const T& NodeStack<T>::top() const
{
  std::cout << "Const top() method called" << std::endl;
  return m_top->m_data;
}

//push method
template <class T>
void NodeStack<T>::push(const T& value)
{
  if(!m_top)
  {
    m_top = new Node<T>(value);
  }
  else
  {
    Node<T> * temp = new Node<T>(value);
    temp->m_next = m_top;
    m_top = temp;
    temp = NULL;
  }
}

//pop method
template <class T>
void NodeStack<T>::pop()
{
  if(!m_top)
    return;
  else if(!m_top->m_next)
  {
    delete m_top;
    m_top = NULL;
  }
  else
  {
    Node<T>* temp = m_top;
    m_top = m_top->m_next;
    delete temp;
    temp = NULL;
  }
}

//size method
template <class T>
size_t NodeStack<T>::size() const               //(13)
{
  size_t count = 0;
  if(m_top)
  {
    Node<T> * current = m_top;
    while(current)
    {
      ++count;
      current = current->m_next;
    }
    current = NULL;
  }
  return count;
}

//empty method
template <class T>
bool NodeStack<T>::empty() const									//(14)
{
  if(!m_top)
    return true;
  return false;
}

//full method
template <class T>
bool NodeStack<T>::full() const
{
  return false;
}

//clear method
template <class T>
void NodeStack<T>::clear()										//(15)
{
  if(m_top)
  {
    Node<T> * del = m_top;
    while(m_top)
    {
      m_top = m_top->m_next;
      del->m_next = NULL;
      delete del;
      del = m_top;
    }
    del = NULL;
  }
}

//serialize method
template <class T>
void NodeStack<T>::serialize(std::ostream& os) const
{
  using std::endl;

  if(!m_top)
  {
    os << "No list" << std::endl;
  }
  else
  {
    Node<T> * current = m_top;
    //display first node on a new line
    os << endl;

    size_t i = 1;
    while(current)
    {
      os << "Value of Node " << i << " is: " << current->m_next<< std::endl;
      ++i;
      current = current->m_next;
    }
  }
}

#endif
