
#include <iostream>
#include "ArrayStack.hpp"
#include "NodeStack.hpp"


int main()
{

    std::cout << "Array stack tests --------------------------------------" << std::endl;
    std::cout << "Default Constructor Test" << std::endl;
    ArrayStack<float> arraytest;
    std::cout << arraytest << std::endl;

    std::cout << "Parameterized Constructor Test" << std::endl;
    ArrayStack<float> parameterArray(5, 6.02);
    std::cout << parameterArray << std::endl;

    std::cout << "Copy Constructor Test" << std::endl;
    ArrayStack<float> copyArray(parameterArray);
    std::cout << copyArray << std::endl;

    std::cout << "Assignment Operator Test" << std::endl;
    arraytest = parameterArray;
    std::cout << arraytest << std::endl;

    std::cout << "Push Function Test" << std::endl;
    arraytest.push(62.202);
    std::cout << arraytest << std::endl;

    std::cout << "Top Function Test" << std::endl;
    std::cout << arraytest.top() << std::endl << std::endl;

    std::cout << "Pop Function Test" << std::endl;
    arraytest.pop();
    std::cout << arraytest << std::endl;

    std::cout << "Clear and Empty Function Test" << std::endl;
    arraytest.clear();
    std::cout << arraytest.empty() << std::endl << std::endl;

    std::cout << "Full Function Test" << std::endl;
    ArrayStack<float> fullTest(1000, 123.1);
    std::cout << fullTest.full() << std::endl << std::endl;

    std::cout << "Size Function Test" << std::endl;
    std::cout << parameterArray.size() << std::endl << std::endl;


    std::cout << "Node stack tests --------------------------------------" << std::endl;
    std::cout << "Default Constructor" << std::endl;
    NodeStack<int> nodetest;
    std::cout << nodetest << std::endl;

    std::cout << "Parameterized Constructor" << std::endl;
    NodeStack<int> parameterNode(4, 200);
    std::cout << parameterNode << std::endl;

    std::cout << "Copy Constructor" << std::endl;
    NodeStack<int> copyNode(parameterNode);
    std::cout << copyNode << std::endl;

    std::cout << "Assignment Operator Test" << std::endl;
    nodetest = copyNode;
    std::cout << nodetest << std::endl;

    std::cout << "Push Function Test" << std::endl;
    nodetest.push(30);
    std::cout << nodetest << std::endl;

    std::cout << "Top Function Test" << std::endl;
    std::cout << nodetest.top() << std::endl << std::endl;

    std::cout << "Pop Function Test" << std::endl;
    nodetest.pop();
    std::cout << nodetest << std::endl;

    std::cout << "Clear and Empty Function Test" << std::endl;
    nodetest.clear();
    std::cout << nodetest.empty() << std::endl << std::endl;

    std::cout << "Full Function Test" << std::endl;
    std::cout << parameterNode.full() << std::endl << std::endl;

    std::cout << "Size Function Test" << std::endl;
    std::cout << parameterNode.size() << std::endl << std::endl;

    return 0;
}
