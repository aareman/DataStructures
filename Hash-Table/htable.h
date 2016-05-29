#include <string>

int nextPrime(int a);

/*
note the hash table should be about twice the size of the
input so that collisions are reduced
*/
class htable {
    /*  !!!!!!!!!!!!!!!!! TODO: !!!!!!!!!!!!!!!!!!!!!!!!!!

            -add operator overloads for =, ==,
            -[DONE] add a copy constructor
            -add a randomization of a & b
            -change the table to dynamically resize when table is over 50% full.
                ->need to adjust the use of this->LEN to something that won't be changing
                    for the chaining to work properly.
            -change from strings to template.
    */
	public:
		htable(int LEN, int a, int b); // constructor
		htable(const htable& source);
		~htable();
		bool insert(const std::string x); // insert x into the hash table
		bool search(const std::string x); // search for x in the table
		bool del(const std::string x); // del x from the table
		int h(const std::string x); //the hash function

        void operator=(const htable& source);
        //htable operator+(const htable& source);
        //htable operator-(const htable& source);
        void operator+=(const htable& source);
        void operator-=(const htable& source);
        bool operator==(const htable& source);

		void print(); // prints out all elements in the table.

	private:
		int LEN, a, b;
		std::string* stable;

};
