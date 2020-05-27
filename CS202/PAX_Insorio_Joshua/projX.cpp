#include <iostream>
#include "SmartPtr.h"

using namespace std;


int main(){

    cout << endl << "Testing SmartPtr Dflt-ctor" << endl;
    SmartPtr sp1;
    //cout << "Default-ctor worked!" << endl;
    sp1->setIntVal(1);
    sp1->setDoubleVal(0.25);
    cout << "Dereference Smart Pointer 1: " << *sp1 << endl;

    cout << endl << "Testing SmartPtr Copy-ctor" << endl;
    SmartPtr sp2 = sp1;
    //cout << "Copy Initilization worked" << endl;
    sp2->setIntVal(2);
    sp2->setDoubleVal(0.5);
    cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
    cout << "Dereference Smart Pointer 2: " << *sp2 << endl;

    cout << endl << "Testing SmartPtr Assignment Operator" << endl;
    SmartPtr sp3;
    //cout << "Default Ctor SmartPtr sp3 worked!" << endl;
    sp3 = sp1;
    //cout <<"Assignment Operator Works!" << endl;
    sp3->setIntVal(4);
    sp3->setDoubleVal(0.0);
    cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
    cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
    cout << "Dereference Smart Pointer 3: " << *sp3 << endl;

    cout << endl << "Testing SmartPtr Parametrized ctor with NULL data" << endl;
    SmartPtr spNull( NULL );
    //cout << "SmartPtr NULL Parameterized-ctor Works!" << endl;

    cout << endl << "Testing SmartPtr Copy ctor with NULL data SmartPtr" << endl;
    SmartPtr spNull_cpy( spNull );
    //cout << "SmartPtr Copy-ctor spNull_cpy worked" << endl;

    cout << endl << "Testing SmartPtr Assignment with NULLdata SmartPtr" << endl;
    SmartPtr spNull_assign;
    spNull_assign = spNull;
    cout << endl << "End-of-Scope, Destructors called in reverse order of SmartPtr creation\n (spNull_assign, spNull_cpy, spNull, sp3, sp2, sp1): " << endl;
    return 0;
}