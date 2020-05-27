#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"
using namespace std;

int main(){

  // Vector creation
  std::vector<int> vecInt;
  
  // Vector population with input values
  std::ifstream fin("RandomData.txt");
  while(fin){
    int fin_in;
    fin >> fin_in;
    if (!fin)
      break;
    vecInt.push_back( fin_in );
  }
    
  std::vector<int> vecIntCpy(vecInt); //Creating the new vecIntCpy and copying all the values from the vecInt
  vector_resort(vecInt, 0, vecInt.size() - 1);
  cout << "Now printing out the sorted vector:" << endl;

  // Vector indexing and output ( using operator[] or at() )
  for (size_t i=0; i<vecInt.size(); ++i)
  {
    cout << vecInt[i] << " in comparison to the original: "<< vecIntCpy[i] << endl;
  }

  int key;
  cout << "What number would you like to search for?" << endl;
  cin >> key;
  int result = vector_research(vecInt, 0, vecInt.size() - 1, key);
  (result == -1)? printf("Element is not present in array") : printf("Element is present at index %d", result);
  cout << endl; 


  return 0;
}
