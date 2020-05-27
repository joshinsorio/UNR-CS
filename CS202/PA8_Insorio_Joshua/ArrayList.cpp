#include "ArrayList.h"

//Ctors
//Default ctor
ArrayList::ArrayList()
{
    m_array = NULL;
    m_size = 0;
    m_maxsize = 0;
}     

//Parameterized ctor
ArrayList::ArrayList(size_t count, const DataType& value)
{
	m_size = count;
	m_maxsize = m_size;
	m_array = new DataType[m_size];
    for (int i = 0; i < m_maxsize; i++)
    {
        m_array[i] = value;
    }
}

//Copy ctor
ArrayList::ArrayList(const ArrayList& other)
{
    m_maxsize = other.m_maxsize;
    m_size = other.m_size;
    m_array = new DataType [m_maxsize];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = other.m_array[i];
    }
}

//Dtor
ArrayList::~ArrayList()
{

    delete [] m_array;
    m_array = NULL;
    m_maxsize = 0;
    m_size = 0;
}

//Operator=
ArrayList& ArrayList::operator= (const ArrayList& rhs)
{
	if (m_array)
	{
		delete[] m_array;
	}
    if (this != &rhs)
    {
        this->m_size = rhs.m_size;
        this->m_maxsize = rhs.m_maxsize;
        this->m_array = new DataType [m_maxsize];
        for (size_t i = 0; i < this->m_size; i++)
        {
            this->m_array[i] = rhs.m_array[i];
        }
    }
    return *(this);
}

//Operator<<
std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList)
{
    for (int i = 0; i < arrayList.m_size; i++)
    {
        os << arrayList.m_array[i] << " ";
    }
    return os;
}

//Operator[]
DataType& ArrayList::operator[] (size_t position)
{
    return m_array[position];
}       

//Methods
DataType* ArrayList::front()
{
	if (!m_array || m_size == 0)
	{
		return m_array;
	}
    return NULL;
}

DataType* ArrayList::back()
{
	if (!m_array || m_size == 0)
	{
		return &m_array[m_maxsize - m_size];
	}
	else
    return NULL;
}

DataType* ArrayList::find(const DataType& target, DataType* &previous, const DataType * start)
{
	for (size_t i = 0; i < m_maxsize; i++)
	{
		if (m_array[i] == target)
		{
		
			if (i > 0)
			{
				previous = &m_array[--i];
			}
			else
			{
				previous = NULL;
			}
			return &m_array[i];
		}

	}
    previous = NULL;
    return NULL;
}

DataType* ArrayList::insertAfter(const DataType& target, const DataType& value)
{
	if (m_size == m_maxsize)
	{
		resize(m_maxsize++);
	}

	int insertIndex = 0;
	DataType *pt;
	for (size_t i = 0; i < m_maxsize; i++)
	{
		if (m_array[i] == target)
		{
			insertIndex = i + 1;
			pt = &m_array[insertIndex];
			break;
		}

	}

	DataType *tempArray = new DataType[m_maxsize];
	for (size_t i = 0; i < m_maxsize; i++)
	{
		tempArray[i] = m_array[i];
	}

	m_array[insertIndex] = value;


	for (size_t i = insertIndex; i < m_maxsize - 1; i++)
	{
		m_array[i+1] = tempArray[i];
	}


	m_size++;
	delete[] tempArray;
	tempArray = NULL;

	if (m_array[insertIndex] == target)
	{
		return pt;
	}
	else
	{
		return NULL;
	}

}
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value)
{
	if (m_size == m_maxsize)
	{
		resize(m_maxsize++);
	}

	int insertIndex = 0;
	DataType *pt;
	for (size_t i = 0; i < m_maxsize; i++)
	{
		if (m_array[i] == target)
		{
			insertIndex = i;
			pt = &m_array[insertIndex];
			break;
		}
		
	}

	DataType *tempArray = new DataType[m_maxsize];
	for (size_t i = 0; i < m_maxsize; i++)
	{
		tempArray[i] = m_array[i];
	}

	m_array[insertIndex] = value;

	for (size_t i = insertIndex; i < m_maxsize - 1; i++)
	{
		m_array[i + 1] = tempArray[i];
	}

	m_size++;
	delete[] tempArray;
	tempArray = NULL;

	if (m_array[insertIndex] == target)
	{
		return pt;
	}
	else
	{
		return NULL;
	}
}      

size_t ArrayList::size() const
{
    return m_size;
}      

bool ArrayList::empty() const
{
	if (!m_array)
    {
        return true;
    }
	else
    return false;
}

void ArrayList::clear()
{
    if (m_array != NULL)
    {
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}   

void ArrayList::resize(size_t count)
{
	if (m_array == NULL) 
	{
		m_size = count;
		m_maxsize = count;
		m_array = new DataType[m_maxsize];
		return;
	}

    DataType* tempArray = new DataType [m_size + count];
    for (size_t i = 0; i < m_size; i++)
    {
        tempArray[i] = m_array[i];
    }
    delete [] m_array;
	m_array = NULL;

    m_maxsize += count;
    m_array = new DataType [m_maxsize];
    for (size_t i = 0; i < m_size; i++)
    {
        m_array[i] = tempArray[i];
    }
    delete[] tempArray;
} 

DataType * ArrayList::erase(const DataType &target)
{
	int eraseIndex = 0;
	DataType *pt;
	for (size_t i = 0; i < m_maxsize; i++)
	{
		if (m_array[i] == target)
		{
			eraseIndex = i;
			pt = &m_array[eraseIndex];
			break;
		}

	}

	if (m_array[eraseIndex] == m_array[m_maxsize - 1])
	{
		pt = NULL;

		resize(m_maxsize--);
		m_size--;
	}
	else
	{
		for (size_t i = eraseIndex; i < m_maxsize - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		pt++;

		resize(m_maxsize--);
		m_size--;
	}

	if (pt == &m_array[eraseIndex])
	{
		return pt;
	}
	else
	{
		return NULL;
	}

}