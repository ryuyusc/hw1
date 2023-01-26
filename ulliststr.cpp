#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


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
void ULListStr::push_back(const std::string& val) {
  //Case for when the list is empty
    if (head_ == NULL) {
      Item* toAdd = new Item;   //allocates new Item
      toAdd->first = 0;
      toAdd->last = 0;
      toAdd->val[toAdd->first] = val;
      toAdd->last++;
      head_ = toAdd;
      tail_ = toAdd;
    }
    //Case for when the list is not empty
    else {
      //Case for when the tail is at the last index
      if (tail_->last == ARRSIZE) {
        Item* toAdd = new Item;   //allocate new Item
        toAdd->val[0] = val;    
        toAdd->last++;
        tail_->next = toAdd;    //sets current tail's next as new Item
        toAdd->prev = tail_;    //sets Item's prev to tail
        tail_ = toAdd;    //tail is now the new Item
      }
      else {
        //Case where the array inside the list is empty
        if (tail_->first == tail_->last) {
          tail_->last++;
          tail_->val[0] = val;
        }
        else{
          tail_->val[tail_->last] = val;
          tail_->last++;
        }
      }
    }
    size_++;
}

void ULListStr::pop_back() {
  //checks if there is anything to remove
  if (head_ != NULL) {
    //checks if the array of tail is not empty
    if (tail_->first != tail_->last) {
      tail_->last--; //changes the last index
      size_--;
    }
    //checks if the array is now empty
    if (tail_->first == tail_->last) {
      //Case where there is only one Item
      if (head_ == tail_) {
        Item* temp = tail_;
        head_ = NULL;
        tail_ = NULL;
        delete temp;
      }
      //Case where there is more than one Item in list
      else {
        Item* temp = tail_;
        tail_ = tail_->prev;
        delete temp;
        tail_->next = NULL;
      }
    }
  }
}

void ULListStr::push_front(const std::string& val) {
    //Case for when the list is empty
    if (head_ == NULL) {
      Item* toAdd = new Item;   //allocates new Item
      toAdd->val[ARRSIZE - 1] = val;
      toAdd->last = ARRSIZE;
      toAdd->first = ARRSIZE - 1;
      head_ = toAdd;
      tail_ = toAdd;
    }
    //Case for when the list is not empty
    else {
      //Case for when the head first is at the first index
      if (head_->first == 0) {
        //Checks if the array inside the Item is empty
        if (head_->first == head_->last) {
          head_->val[ARRSIZE - 1] = val;
          head_->last = ARRSIZE;
          head_->first = ARRSIZE - 1;
        }
        else {
          Item* toAdd = new Item;  //allocates new Item
          toAdd->val[ARRSIZE - 1] = val;
          toAdd->last = ARRSIZE;
          toAdd->first = ARRSIZE - 1;
          head_->prev = toAdd;
          toAdd->next = head_;
          head_ = toAdd;
        }
      }
      else {
        head_->val[head_->first - 1] = val;
        head_->first--;
      }
    }
    size_++;
}

void ULListStr::pop_front() {
  //checks if there is anything to remove
  if (head_ != NULL) {
    //checks if the array of head is empty
    if (head_->first != head_->last) {
      head_->first++;  //changes the index
      size_--;
    }
    //checks if the array is now empty
    if (head_->first == head_->last) {
      //Case where there is only one Item
      if (head_ == tail_) {
        Item* temp = head_;
        head_ = NULL;
        tail_ = NULL;
        delete temp;
      }
      //Case where there is more than one Item in list
      else {
        Item* temp = head_;
        head_ = head_->next;
        delete temp;
      }
    }
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
 return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  //checks if loc is a valid index 
  if (loc >= 0 && loc < size_) {
    Item* temp = head_;
    size_t index = 0;
    size_t innerIndex = 0;
    while (index != loc) {
      if (temp->first + innerIndex == temp->last - 1) {
        temp = temp->next;
        innerIndex = 0;
      }
      else {
        innerIndex++;
      }
      index++;
      if (index == loc) {
        return &(temp->val[temp->first + innerIndex]);
      }
    }
    return &(temp->val[temp->first + innerIndex]);
  }
  return NULL;
}


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
