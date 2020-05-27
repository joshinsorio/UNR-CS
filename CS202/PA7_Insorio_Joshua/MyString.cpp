#include <iostream>
#include <fstream>
#include "MyString.h"
using namespace std;

//Default ctor
MyString::MyString()
{
    m_buffer = NULL; 
    buffer_allocate(0);
}
//Parameterized ctor
MyString::MyString(const char * str)
{
    m_buffer = NULL;
    size_t len = strlen(str);
    buffer_allocate(len);
    strcpy(m_buffer, str);
}
//Copy ctor
MyString::MyString(const MyString & other_myStr)
{
    buffer_allocate (other_myStr.m_size); 
    strcpy (m_buffer, other_myStr.m_buffer);
}
//Dtor
MyString::~MyString()
{
    delete [] m_buffer;
}
//Allocate method
void MyString::buffer_allocate(size_t size)
{
    //char *p = NULL;
    if(m_buffer != NULL)
    buffer_deallocate();
    m_size = size;
    m_buffer = new char [m_size + 1];
    m_buffer[0] = '\0';

}
//Deallocate method
void MyString::buffer_deallocate()
{
    if(m_buffer != NULL)
    {
        delete [] m_buffer;
        m_buffer = NULL;
        m_size = 0;
    }
    else
    {
    return;
    }
}
//Get Size Method
size_t MyString::size() const
{
    return (sizeof(m_buffer));
}
//Get Length Method
size_t MyString::length() const
{
    size_t len = strlen(m_buffer);
    return len;
}
//C_str method
const char* MyString::c_str() const
{
    if(m_buffer)
    {
        return m_buffer;
    }
    else
    {
        char * cstr = new char [1];
        cstr[0] = '\0';
        return cstr;
    }
}
//Equality operator
bool MyString::operator==(const MyString & other_myStr) const
{
    return (strcmp(m_buffer, other_myStr.m_buffer) == 0);
}
//Assignment operator
MyString & MyString::operator= (const MyString & other_myStr)
{
    if(this == &other_myStr)
    {
    return *this;
    }
    buffer_deallocate();
    buffer_allocate(other_myStr.m_size);
    strcpy(m_buffer, other_myStr.m_buffer);
    return *this;
}
//Operator+
MyString MyString::operator+ (const MyString & other_myStr) const
{

    MyString temp;
    temp.m_size = m_size + other_myStr.m_size;
    temp.m_buffer = new char [temp.m_size + 1];
    strcpy(temp.m_buffer, m_buffer);
    strcat(temp.m_buffer, other_myStr.m_buffer);
    return temp;
}
//Operator[] methods
char & MyString::operator[](size_t index){return m_buffer[index];}
const char & MyString::operator[](size_t index) const{return m_buffer[index];}
//Operator<< method
std::ostream & operator<<(std::ostream & os, const MyString & myStr)
{
    os << myStr.m_buffer;
    return os;
}
