#include <string>
#include <iostream>
#include <cmath> // used for the find next prime function.
#include "htable.h"
//using namespace std;

//constructors and destructors
htable::htable(int LEN, int a, int b){
	this->LEN = LEN;
	this->a = a;
	this->b = b;
	this->stable = new std::string[LEN];
	for(int i = 0;i<this->LEN;i++){
		this->stable[i] = "NIL";
	}
}
htable::htable(const htable& source){
    this->a = source.a;
    this->b = source.b;
    this->LEN = source.LEN;
    this->stable = new std::string[LEN];
    for(int i=0;i<source.LEN;i++){
        this->stable[i] = source.stable[i];
    }
}
htable::~htable(){
    delete[] this->stable;
}

//operator overides
void htable::operator=(const htable& source){
    this->a = source.a;
    this->b = source.b;
    this->LEN = source.LEN;
    this->stable = new std::string[LEN];
    for(int i=0;i<source.LEN;i++){
        this->stable[i] = source.stable[i];
    }
}
//void htable::operator+=(const htable& source);
//void htable::operator-=(const htable& source);
//bool htable::operator==(const htable& source);

//htable member functions
bool htable::insert(const std::string x){
    if(this->search(x)){
        std::cout << x << " is already in the table" << std::endl;
        return false;
    }
    int index = this->h(x);
    if(this->stable[index] == "NIL"){
        stable[index] = x;
        return true;
    }
    else if (this->stable[index] != x){
        //std::cout << "collision detected!!:"<< this->stable[index] << " & "<< x << std::endl;
        // chaining routine
        int checked = 0;
        while(checked < this->LEN){
            //std::cout << "chaining..." << std::endl;
            index = (index + nextPrime(this->LEN/2)) % this->LEN;
            if(this->stable[index] == "NIL"){
                stable[index] = x;
                return true;
            }
            checked++;
        }
        std::cout << "table is full" << std::endl;
        return false;
    }
    else{
        std::cout << x << " is already in the table" << std::endl;
        return false;
    }
}
bool htable::search(const std::string x){
    int index = this->h(x);
    if(this->stable[index] == x){
        return true;
    }
    else{
        int checked = 0;
        while(checked < this->LEN){
            //cout << "searching..." << endl;
            index = (index + nextPrime(this->LEN/2)) % this->LEN;
            if(this->stable[index] == x){
                return true;
            }
            checked++;
        };
        return false;
    }
}
bool htable::del(const std::string x){
    if(!this->search(x)){
    std::cout<<"cannot delete, "<< x << " is not in the table." << std::endl;
    return false;
    }
    int index = this->h(x);
    if(this->stable[index] == x){
        this->stable[index] = "NIL";
        return true;
    }
    else{
        int checked = 0;
        while(checked < this->LEN){
            index = (index + nextPrime(this->LEN/2)) % this->LEN;
            if(this->stable[index] == x){
                stable[index] = "NIL";
                return true;
            }
            checked++;
        }
        return false;
    }
}
/* sums up each character in string x.
and stores the number in k. then uses that */
int htable::h(const std::string x){
	int k = 0;
	for(int i = 0; i<x.length();i++){
        k += (int)x[i];
	}
	return ((this->a*k + this->b) % nextPrime(this->LEN)) % this->LEN;
}
void htable::print(){
    int counter = 1;
    for(int i=0;i<this->LEN;i++){
        if(this->stable[i] != "NIL"){
            std::cout << counter << ") " << this->stable[i] << std::endl;
            counter++;
        }
        else{
            //cout << "-0-"<<endl;
        }
    }
    std::cout<<"table is " << ((double)counter)/((double)this->LEN) * 100.0 << "% full."<< std::endl;
}

//auxilliary functions
int nextPrime(int a){
    int i, j, cnt;
    i = a + 1;
    while(1){
        cnt = 0;
        for(j = 2; j<std::sqrt(i)+1;j++){
            if(i%j == 0){
                cnt++;
                break;
            }
        }
        if(cnt == 0){
            return i;
        }
        i++;
    }
}
