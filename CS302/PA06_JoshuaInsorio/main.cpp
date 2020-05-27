
#include <iostream>
#include <cstddef>
#include "LLRB.hpp"

//Constants definitions
#define SafeDelete(x)		{ if (NULL != (x)) { delete (x);     (x) = NULL; } }
#define SafeDeleteArray(x)	{ if (NULL != (x)) { delete [] (x);  (x) = NULL; } }


//Performance function to generate the keys and put them into the tree
void Performance(void)
{
	srand(4310987);

	const int limit = 10;

	int *pKeys = new int[limit];

	for (int i = 0; i < limit; ++i) {
		pKeys[i] = rand()/1000000;
	}

    VoidRef_t ref;
	int dummy;
	ref.pContext = &dummy;
    int temp4;

	LeftLeaningRedBlack<int> sort4;
        sort4.FreeAll();
		for (int i = 0; i < limit; ++i) {
			ref.Key = pKeys[i];
            if(i == 4)
            {
                temp4 = pKeys[i];
            }
			sort4.Insert(ref);
		}
		for (int i = 0; i < limit; ++i) {
			sort4.LookUp(pKeys[i]);
		}

		//Outputs the tree in terminal as it calls the traverse function
        std::cout << "Traverse LLRBT" << std::endl;
        sort4.Traverse();
        sort4.Delete(temp4);
        std::cout << "Traverse LLRBT after removal of 4th random variable inserted" << std::endl;
        sort4.Traverse();


		for (int i = 0; i < limit; ++i) {
			sort4.Delete(pKeys[i]);
        }

	//SafeDeleteArray(pFrame);
	SafeDeleteArray(pKeys);
}

int main(void)
{
    Performance();
    return 0;
}
