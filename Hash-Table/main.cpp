#include <iostream>
#include "htable.h"

using namespace std;

int main(){

	htable tab1(40,2,6);
	tab1.insert("boy");
	tab1.insert("girl");
	tab1.insert("man");
	tab1.insert("running");
	tab1.insert("woman");
	tab1.insert("cold");
	tab1.insert("dash");
	tab1.insert("fly");
	tab1.insert("trample");
	tab1.insert("charge");
	tab1.insert("cow");
	tab1.insert("rabbidy doodle");
	tab1.insert("jace");
	tab1.insert("rabbit");
	tab1.insert("aircraft");
	tab1.insert("the most boring line of text");
	tab1.insert("boy");

	cout << "checking boy.........";
	cout << tab1.search("boy") << endl;

	cout << "checking test.........";
	cout << tab1.search("test") << endl;

	cout << "checking boy after deleting it.........";
	tab1.del("boy");
	cout << tab1.search("boy") << endl;

	tab1.insert("boy");
	tab1.insert("crabby");
	tab1.del("boy");
	tab1.insert("rabid");

	htable tab2 = tab1;

	tab1.print();
	tab2.print();

	return 0;
}
