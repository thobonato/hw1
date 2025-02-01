#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  // case 0: empty list (head_ and tail_ == null)
  // put it at the front of the array, choose whatever you'd like
  if (this->head_ == NULL){
    Item* item = new Item();
    item->val[0] = val;
    item->last = 0;
    item->last = 1;
    item->next = nullptr;
    item->prev = nullptr;
    this->head_ = item;
    this->tail_ = item;
  }
  else if(this->tail_->last < ARRSIZE) { // case 1: there is space
    this->tail_->val[this->tail_->last] = val;
    this->tail_->last++;
  } 
  else{ // case 2: there is no space, allocate new Item(), add it to the start that new Item's array
    Item* item = new Item();
    
    // set up item correctly
    item->val[0] = val;
    item->first = 0;
    item->last = 1;
    item->prev = this->tail_;

    // place it in the linked list
    this->tail_->next = item;
    this->tail_ = item;
  }
  this->size_++;

}

void ULListStr::pop_back(){
  if (this->size_ < 1){
    return;
  }

  int diff = this->tail_->last - this->tail_->first;
  if (diff > 1){ // case 1: pop front without having to deallocate an item
    this->tail_->last--;
  } 
  else{ // case 2: pop front having to deallocate an item
    Item* tmp = this->tail_;  
    // if popping front will erase whole array, 
    if (this->tail_->prev == nullptr){
      std::cout << "nullified!!!" << std::endl;
      this->head_ = nullptr;
      this->tail_ = nullptr;
    }
    else {
      this->tail_ = this->tail_->prev;
    }

    delete tmp;
  }
  this->size_--;
}

void ULListStr::push_front(const std::string& val){
  // case 0: empty list (head_ and tail_ == null)
  // put it at the front of the array, choose whatever you'd like
  if (this->head_ == NULL){
    Item* item = new Item();
    item->val[0] = val;
    item->first = 0;
    item->last = 1;
    item->next = nullptr;
    item->prev = nullptr;
    this->head_ = item;
    this->tail_ = item;
  }
  else if(this->head_->first > 0) { // case 1: there is space
    this->head_->val[this->head_->first - 1] = val;
    this->head_->first--;
  } 
  else{ // case 2: there is no space, allocate new Item(), add it to the back that new Item's array
    Item* item = new Item();
    
    // set up item correctly
    item->val[ARRSIZE - 1] = val;
    item->first = ARRSIZE - 1;
    item->last = ARRSIZE;
    item->next = this->head_;

    // place it in the linked list
    if (this->head_ != NULL){
      this->head_->prev = item;
    }
    this->head_ = item;
  }
  this->size_++;
}

void ULListStr::pop_front(){
  if (this->size_ < 1){
    return;
  }

  int diff = this->head_->last - this->head_->first;
  if (diff > 1){ // case 1: pop front without having to deallocate an item
    this->head_->first++;
  } 
  else{ // case 2: pop front having to deallocate an item
    Item* tmp = this->head_;
    
    std::cout << "trying to nullify..." << std::endl;
    std::cout << "this->head_" << this->head_ << std::endl;
    std::cout << "this->size_" << this->size_ << std::endl;

    // if popping front will erase whole array, 
    if (this->head_->next == nullptr){
      std::cout << "nullified!!!" << std::endl;
      this->head_ = nullptr;
      this->tail_ = nullptr;
    }
    else{
      this->head_ = this->head_->next;
    }

    delete tmp;
  }
  this->size_--;
}

std::string const & ULListStr::back() const{
  return this->tail_->val[this->tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return this->head_->val[this->head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* item = this->head_;


  // go to right item
  while (item != nullptr && item->first + loc > ARRSIZE - 1){
    loc = loc - item->last + item->first;
    item = item->next;
  }

  // cases when null
  if (item == nullptr || item->val == NULL){
    return NULL;
  }
  // return item
  return &item->val[item->first + loc];
}


// CODE WRITTEN ABOVE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
