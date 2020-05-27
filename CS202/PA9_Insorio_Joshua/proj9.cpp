
#include <iostream>

#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main()
{
cout << "--------------------------------------------------------" << endl;
cout << endl << "DataType class test" << endl;

DataType myData;
cout << "Testing default ctor" << endl;
cout << "Value is: " << myData << endl;

DataType otherData(5, 10.0);
cout << endl << "Testing parameterized ctor" << endl;
cout << "Value is: " << otherData << endl;

DataType copyData(otherData);
cout << endl << "Testing copy ctor" << endl;
cout << "Value is: " << copyData << endl;

cout << endl << "Testing operator==" << endl;
if(copyData == otherData)
    cout << endl << "They are the same" << endl;
else
    cout << endl << "They are the different" << endl;

cout << endl << "Testing getIntVal() method" << endl;
cout << "Value is: " << copyData.getIntVal() << endl;

cout << endl << "Testing setIntVal() method" << endl;
copyData.setIntVal(10);
cout << "Value is: " << copyData.getIntVal() << endl;

cout << endl << "Testing getDoubleVal() method" << endl;
cout << "Value is: " << copyData.getDoubleVal() << endl;

cout << endl << "Testing setDoubleVal() method" << endl;
copyData.setDoubleVal(1.0);
cout << "Value is: " << copyData.getDoubleVal() << endl;


cout << "--------------------------------------------------------" << endl;
cout << endl << "Node class test" << endl;

Node myNode;
cout << endl << "Testing default ctor" << endl;
cout << "Value is: " << myNode << endl;

cout << endl << "Testing parameterized ctor" << endl;
Node otherNode(copyData);
cout << "Value is: " << otherNode << endl;

cout << endl << "Testing copy ctor" << endl;
Node copyNode(otherNode);
cout << "Value is: " << copyNode << endl;

cout << endl << "Testing GetData() method " << endl;
cout << "Value is: " << copyNode.getData() << endl;


cout << "--------------------------------------------------------" << endl;
cout << endl << "NodeQueue class test" << endl;

cout << endl << "Testing default ctor" << endl;
NodeQueue newList;
cout << "Value is: " << newList << endl;

cout << endl << "Testing parameterized ctor" << endl;
NodeQueue otherList(10, copyData);
cout << "Value is: " << otherList << endl;

cout << endl << "Testing copy ctor" << endl;
NodeQueue copiedList(otherList);
cout << "Value is: " << copiedList << endl;

cout << endl << "Testing operator=" << endl;
NodeQueue assignList(10, copyData);
assignList = otherList;
cout << "Value is: " << assignList << endl;

cout << endl << "Testing First() method" << endl;
DataType front = assignList.front();
cout << "Value is: " << front << endl;

cout << endl << "Testing Last() method" << endl;
DataType last = assignList.back();
cout << "Value is: " << last << endl;

DataType toFront(45, 10.0);
cout << endl << "Testing push() method" << endl;
assignList.push(toFront);
cout << "Value is: " << assignList << endl;

cout << endl << "Testing pop() method" << endl;
assignList.pop();
cout << "Value is: " << assignList << endl;

cout << endl << "Testing size() method" << endl;
cout << "List size is:" << assignList.size() << endl;

cout << endl << "Testing empty() method" << endl;
NodeQueue tempList;
if(tempList.empty())
    cout << "List is empty" << endl;
else
    cout << "Something in the list" << endl;

cout << endl << "Testing full() method" << endl;
assignList.full();
cout << "Full method works" << endl;

cout << endl << "Testing clear() method" << endl;
tempList.clear();
otherList.clear();
cout << tempList << endl;
cout << otherList << endl;

cout << "------------------------------------------------------" << endl;
cout << endl << "ArrayQueue class test" << endl;

cout << endl << "Testing default ctor" << endl;
ArrayQueue emptyArray;
cout << "Value is:" << endl;
cout << emptyArray << endl;
if(emptyArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
cout << emptyArray.front() << endl;

cout << endl << "Testing parameterized ctor" << endl;
ArrayQueue paramArray(10, copyData);
cout << "Value is:" << endl;
cout << paramArray << endl;

cout << endl << "Testing copy ctor" << endl;
ArrayQueue copyArray(paramArray);
cout << "Value is:" << endl;
cout << copyArray << endl;

cout << endl << "Testing operator=" << endl;
const ArrayQueue assignArray = paramArray;
cout << "Value is:" << endl;
cout << assignArray << endl;

DataType retData;
cout << endl << "Testing front() method" << endl;
if(paramArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
{
  retData = paramArray.front();
  cout << "Value is:" << endl;
  cout << retData << endl;
}

cout << endl << "Testing const front() method" << endl;
if(assignArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
{
  cout << "Value is:" << endl;
  const DataType constData = assignArray.front();
  cout << constData << endl;
}

if(paramArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
{
  cout << endl << "Testing back() method" << endl;
  retData = paramArray.back();
  cout << "Value of back data:" << endl;
  cout << retData << endl;
}
if(assignArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
{
  cout << endl << "Testing const back() method" << endl;
  const DataType conData = assignArray.back();
  cout << "Value is:" << endl;
  cout << conData << endl;
}

cout << endl << "Testing push() method" << endl;
cout << endl << "How many items you would like to add?" << endl;
size_t insert;
cin >> insert;
size_t i = 0;
while(i < insert)
{
  DataType temp((int)i, (double)i * 2.0);
  paramArray.push(temp);
  ++i;
}
cout << "New List after push is:" << endl;
cout << paramArray << endl;

if(paramArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
{
  cout << endl << "Back element is: " << endl;
  cout << paramArray.back() << endl;
}

cout << endl << "Testing pop() method" << endl;
paramArray.pop();
cout << "New List after pop()" << endl;
cout << paramArray << endl;

cout << endl << "Testing size() method" << endl;
cout << "Size is: " << paramArray.size();
cout << endl << "Back element is: " << endl;
   
if(paramArray.empty())
{
  cout << "The ArrayQueue is empty and cannot display an empty list." << endl;
}
else
cout << paramArray.back() << endl;

return 0;
}