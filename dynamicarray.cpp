// ***************************************************************************** \\
// Lab08::dynamicarray.cpp                                                       \\
// Author: Hailey Carson-Hull                                                    \\
//                                                                               \\
// This code writes the member functions to append, print, and edit an array.    \\
// Functions include ::append, ::at, ::sum, and ::remove, as well as a default   \\
// and custom constructor, and a destructor.                                     \\
// ***************************************************************************** \\

#include <iostream>
#include "dynamicarray.hpp"
#include <ostream>
using namespace std;

const int INITIAL_CAP = 10;

// Default Constructor
DynamicArray::DynamicArray()
{
  len = 0;
  capacity = 10;
  arr = new int[capacity];
}

// Destructor
DynamicArray::~DynamicArray()
{
// deallocate dynamically allocated memory
  delete [] arr;
}

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& arrayToCopy)
{
  capacity = arrayToCopy.capacity;
  len = arrayToCopy.len;
  arr = new int[capacity];
  for (int i=0; i < len; i++)
    {
      arr[i] = arrayToCopy.arr[i];
    }
}

// Equality Comparison Operator
bool DynamicArray::operator==(const DynamicArray& other) const
{
  if (len != other.len)
    return false;
  for (int i=0; i<len; i++)
    {
      if (arr[i] != other.arr[i])
	return false;
    }
}

// Assignment Operator
DynamicArray& DynamicArray::operator=(const DynamicArray& otherArray)
{
    // This part is the same as the copy constructor
    capacity = otherArray.capacity;
    len = otherArray.len;
    if (arr == otherArray.arr)
     {
       return *this;
     }

    delete [] arr;
    arr = new int[capacity];   
    for (int i = 0; i < len; i++) {
       arr[i] = otherArray.arr[i];
    }

    return *this;
}

// Output Operator
ostream& operator<< (std::ostream &out, const DynamicArray& pt)
{
   for (int i = 0; i < pt.len; i++)
     {
     out << pt.arr[i] << " ";
     if (i % 10 == 9) {
          out << endl;
      }
   }
    return out;
}

// Print all array elements
void DynamicArray::print(std::ostream& s) const {
   for (int i = 0; i < len; i++) {
      s << arr[i] << " ";
      if (i % 10 == 9) {
	  // newline every 10 elements 
          s << endl;
      }
   }
   s << endl;
}

// Append int value to the array
void DynamicArray::append(int value)
{
  if (len == capacity)
   {
//   allocate new array with x2 capacity
     int* arr2 = new int[capacity * 2];
     capacity = capacity*2;
     
     for (int i=0; i < len; i++)
       {
	 // copy contents of old array
	 arr2[i] = arr[i];
       }
     // delete the old array
     
     int* temppoint = arr;
     arr = arr2;
     delete [] temppoint;
   
// append to the array and update the length
      arr[len] = value;
      len++;
   }

  else if (len < capacity)
    {
    arr[len] = value;
    len++;
    }
  

}
// At() returns the element at the value provided
int DynamicArray::at(int index) const
{
  if (index >= capacity)
    {
      //    cout << "This value is outside of the index" << endl;
      return 9;
    }
  else
    {
      return arr[index];
    }

}

// Add all of the elements of the array together
int DynamicArray::sum() const
{
  int sum = 0;
  for (int i = 0;  i < len; i++)
    {
      //add elements together 
      sum += arr[i];
    }
  return sum;
}

// Remove the specified value from the array, ignore if the value is not there
bool DynamicArray::remove(int value)
{
  // traverse the array, break once the value is found

    bool found = false;
    int pos;
  //traverse the array, break once the value is found                                                    
    for(int i = 0; i < len; i++){
                if(value == arr[i]){
                        pos = i;
                        found = true;
                        len--;
                        break;
                }
    }

    if(found){
        for(int i = pos; i< len; i++)
                arr[i] = arr[i+1];

     }

    if (len < .5 * capacity && capacity >= INITIAL_CAP)
            {
              capacity = capacity * .8;
            }

   if (capacity < INITIAL_CAP)
                capacity = INITIAL_CAP;

   return found;

}

// Hopefully it works! Godspeed.
