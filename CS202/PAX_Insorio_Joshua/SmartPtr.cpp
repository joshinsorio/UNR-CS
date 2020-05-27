
#include<iostream>
using namespace std;
#include "SmartPtr.h"
#include "DataType.h"

//Default Ctor
SmartPtr::SmartPtr( )
{
    m_ptr = new DataType;
    m_refcount = new size_t(1);
    cout << "SmartPtr Default Constructor from data pointer, RefCount =  " << *m_refcount << endl;
}

//Parameterized ctor
SmartPtr::SmartPtr( DataType * data )
{
    m_ptr = data;
    m_refcount = new size_t;
    if(m_ptr)
    {
        *m_refcount = 1;
    }
    else
    {
        *m_refcount = 0;
    }

	cout << "SmartPtr Paramaterized Constructor for new allocation, RefCount = " << *m_refcount << endl << endl;
}

//Copy Ctor
SmartPtr::SmartPtr( const SmartPtr& other )
{
    if(other.m_ptr)
    {
        m_ptr = other.m_ptr;
        m_refcount = other.m_refcount;
        ++(*m_refcount);
    }
    else
    {
        m_refcount = new size_t(0);
    }
    cout << "SmartPtr Copy Constructor, RefCount = " << *m_refcount << endl; 
}

//Dtor
SmartPtr::~SmartPtr( )
{
    cout << "SmartPtr Destructor, RefCount = " << *m_refcount << endl; 
    (*m_refcount)--;
    if(!(*m_refcount))
    {
       
        delete m_refcount; 
        delete m_ptr; 
    }
}

//Assignment operator
SmartPtr& SmartPtr::operator=( const SmartPtr& rhs )
{
    if(this == &rhs)
        return *this;


    if(*m_refcount == 0)
    {
        delete m_refcount;
        delete m_ptr;
    }

    if(!rhs.m_ptr)
    {
        //m_ptr = NULL;
        m_refcount = new size_t (0);
    }
    else
    {
        //m_ptr = NULL;
        m_ptr = rhs.m_ptr;
        m_refcount = rhs.m_refcount;
        ++(*m_refcount);
    }
    cout << "SmartPtr Assignment, RefCount = " << *m_refcount << endl;
    return *this;
}

//Overloaded dereference operator
DataType& SmartPtr::operator*( )
{
    return *m_ptr;
}

//overloaded indirect member access operator
DataType* SmartPtr::operator->( )
{
    return m_ptr;
}