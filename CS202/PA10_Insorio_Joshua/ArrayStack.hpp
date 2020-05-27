
#ifndef ArrayStack_HPP_
#define ArrayStack_HPP_


const size_t MAX_STACKSIZE = 1000;

template <class T>
class ArrayStack;

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayStack<T>& arrayStack);

//templated class
template <class T>
class ArrayStack{

  friend std::ostream& operator<<(std::ostream& os,	const ArrayStack<T>& arrayStack)
  {
    arrayStack.serialize(os);
    return os;
  }

  public:
    ArrayStack();								    		//(1)
    ArrayStack(size_t count, const T& value);			//(2)
    ArrayStack(const ArrayStack<T>& other);				    	//(3)
    ~ArrayStack();							    			//(4)
    ArrayStack<T>& operator= (const ArrayStack<T>& rhs);			//(5)
    T& top();
    const T& top() const;
    void push(const T& value);
    void pop();
    size_t size() const;									//(13)
    bool empty() const;
    bool full() const;									//(14)
    void clear();
    void serialize(std::ostream& os) const;								//(15)

  private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
	};

//templated implementations
template <class T>
ArrayStack<T>::ArrayStack()	: m_top(0)			    		//(1)
{}

//parameterized ctor
template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T& value)			//(2)
{
  m_top = count;
  for(size_t i = 0; i < m_top; ++i)
  {
    m_container[i] = value;
  }
}

//copy ctor
template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other)				    	//(3)
{
  m_top = other.m_top;
  for(size_t i = 0;i < m_top; ++i)
  {
    m_container[i] = other.m_container[i];
  }
}

//dtor
template <class T>
ArrayStack<T>::~ArrayStack()							    			//(4)
{
  std::cout << std::endl << "ArrayStack D-tor Called!" << std::endl;
  clear();
}

//operator=
template <class T>
ArrayStack<T>& ArrayStack<T>::operator= (const ArrayStack<T>& rhs)			//(5)
{
  if(this != &rhs)
  {
    clear();
    m_top = rhs.m_top;
    for (size_t i = 0;i < m_top;++i)
    {
      m_container[i] = rhs.m_container[i];
    }
  }
  return *this;
}

//front method
template <class T>
T& ArrayStack<T>::top()
{
  std::cout << "top() called" << std::endl;
  return m_container[m_top-1];
}

//top method
template <class T>
const T& ArrayStack<T>::top() const
{
  std::cout << "const top() called" << std::endl;
  return m_container[m_top-1];
}

//push method
template <class T>
void ArrayStack<T>::push(const T& value)
{
  if(full())
  {
    std::cout << "The list is full" << std::endl;
    return;
  }
  m_container[m_top++] = value;
}

//pop method
template <class T>
void ArrayStack<T>::pop()
{
  if(empty())
    return;
  else
    --m_top;
}

//size method
template <class T>
size_t ArrayStack<T>::size() const									//(13)
{
  return m_top;
}

//empty method
template <class T>
bool ArrayStack<T>::empty() const										//(14)
{
  return m_top == 0;
}

//full method
template <class T>
bool ArrayStack<T>::full() const
{
  return m_top == MAX_STACKSIZE;
}

//clear method
template <class T>
void ArrayStack<T>::clear()											//(15)
{
  if(empty())
    return;
  else
  {
    T temp = '\0';
    while(m_top--)
      m_container[m_top] = temp;
  }
}

//serialize method
template <class T>
void ArrayStack<T>::serialize(std::ostream& os) const
{
  if(m_top > 0)
  {
    os << std::endl;
    for(size_t i = 0;i < m_top;++i)
    {
      os << m_container[i] << std::endl;
    }
  }
  else
    std::cout << "Empty!" << std::endl;
}

#endif
