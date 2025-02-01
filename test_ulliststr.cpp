#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr list = ULListStr();
  
  //  ListRemove.AtARRSIZEPlusOne 
  list.push_back("oldfront");
	list.push_back("oldback");

	std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");

	std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");

	std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

	// now, the original head should get deleted
	list.pop_back();

	std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

	list.pop_front();

	std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

	list.push_front("newback");

  std::cout << "list size " << list.size() << std::endl;
  for(size_t index = 0; index < list.size(); ++index){
    std::cout << list.get(index) << ", ";
  }
  std::cout << std::endl;

  // ListRemove.SongOfBackAndFront
  // tried to free something impossible
  // Value of: checkListContent(&list, {"newback"})
  //   Actual: false (List content mismatch: Expected value at index 0 was newback, but element was actually 
  // )

 

}
