/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <map>

#include "split.h"

Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;
	
	if(!content.empty())
	{
		// create head
		head = new Node(content[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(content.cbegin());
		++nextValIter;

		for(; nextValIter != content.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}
	}

	return head;

}

int main(int argc, char* argv[])
{
  Node* list = makeList({1,2,3,4});
	Node* odds = nullptr;
	Node* evens = nullptr;
    
    split(list, odds, evens);

    for(int i = 0; i < 2; i++){
        std::cout << "odds->val " << odds->value << std::endl;
        std::cout << "evens->val " << evens->value << std::endl;
        evens = evens->next;
        odds = odds->next;
    }
    std::cout << "list" << list << std::endl;
    // std::cout << "list->value" << list->value << std::endl;
}
