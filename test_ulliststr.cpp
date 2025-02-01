#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  std::cout << "running" << std::endl;
  ULListStr list = ULListStr();
  
  // insert front threeitemadd
  // Value of: checkListContent(populatedList, contents)
  //   Actual: false (List content mismatch: Expected value at index 0 was 768, but element was actually 
  // Expected value at index 1 was 1024, but element was actually 
  // Expected value at index 2 was 1536, but element was actually 
  // )
  // Expected: true

  
  // insert back then front
  // grade_ulliststr.cpp:205: Failure
  // Value of: checkListContent(&list, {"fred", "bob"})
  //   Actual: false (List content mismatch: Expected value at index 0 was fred, but element was actually 
  // Expected value at index 1 was bob, but element was actually 
  // )

  list.push_back("bob");
	list.push_front("fred");

  

  // head3 elements
  // "foo", "BAR", "baz"
  // pop_front();

  // ListRemove.SongOfBackAndFront
  // tried to free something impossible
  // Value of: checkListContent(&list, {"newback"})
  //   Actual: false (List content mismatch: Expected value at index 0 was newback, but element was actually 
  // )

  std::cout << "list.back()" << list.back() << std::endl;
  std::cout << "list.front()" << list.front() << std::endl;

  int sz = list.size();
  std::cout << "list size " << sz << std::endl;
  for(size_t index = 0; index < sz; ++index){
    std::cout << list.get(index) << std::endl;
  }

}
