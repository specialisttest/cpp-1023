#include <iostream>
#include "Date.h"

using namespace std;

int main(int argc, char** argv) {
	Date* d1 = new Date;
    //d1->read();
    d1->print();

    PDate d2 = new Date(2021, 5, 1);
    d2->set(2023, 9, 22);
    d2->print();

    cout << IsGreater(*d1, *d2) << endl;
    cout << d1->CompareTo(*d2) << endl;
    cout << d1->Equal(d2) << endl;
    cout << d1->Less(d2) << endl;
    cout << d1->Greater(d2) << endl;

    delete d1;
    delete d2;
    
    
    return 0;
}