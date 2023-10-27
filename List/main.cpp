#include <iostream>

#include "List.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	List<int>* pList = new List<int>;
	
	try
	{
		pList->add(new int(5));
		pList->add(new int(7));
		pList->add(new int(3));
		
		
		
		cout << "Print int list begin" << endl;
		pList->start();
	
		int* pi;
		while ( (pi = pList->next()) != NULL )
			cout << *pi << endl;
		
		cout << "Print int list end" << endl;
		
		//pList->clear();
		pList->remove(11);
		
		cout << "Print int list begin" << endl;
		while ( (pi = pList->next()) != NULL )
			cout << *pi << endl;
		cout << "Print int list end" << endl;		
	}
	catch(invalid_remove_object& ex)
	{
		cout << ex.what() << " Invalid data: " << ex.getInvalidData() << endl;
	}
	//  Visual studio
	//__finally {
	//}

	delete pList;	
	

	return 0;
}
