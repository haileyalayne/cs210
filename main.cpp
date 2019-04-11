#include <iostream>
#include <sstream>
#include "dynamicarray.hpp"
using namespace std;

bool RunLab7Tests(DynamicArray& a);
bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel);

int main( ) {
   DynamicArray a;
   DynamicArray b(a);

   cout << "*** Lab 7 tests on original array a: "
        << (RunLab7Tests(a) ? "passed" : "failed") << endl;

   cout << "*** Lab 7 tests on array created with copy constructor: "
        << (RunLab7Tests(b) ? "passed" : "failed") << endl;


   // Equality comparison
   cout << "Testing equality comparison operator: "
        << (a == b ? "passed" : "failed") << endl;
   b.append(1); // add a new element to b
   cout << "Retesting after modifying 1 array: "
        << (a == b ? "failed" : "passed") << endl;
       
   // Assignment operator
   b = b; // make sure this doesn't break
   cout << "Testing assignment operator on self-assignment: "
        << (b == b ? "passed" : "failed") << endl;
   a = b;
   cout << "Testing assignment operator: "
        << (a == b ? "passed" : "failed") << endl;
   
   // ...and print
   cout << "Testing output operator; should print 152 1 twice" << endl;
   cout << a << endl;
   cout << b << endl;

   return 0;
}

bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel) {
    if (desiredOutput != actualOutput) {
        cout << "TEST FAILED: " << testLabel << endl;
        return false;
    }
    return true;
}

bool RunLab7Tests(DynamicArray& a){
   stringstream testoutput;
   bool pass = true;

   // Print array before any data is added
   a.print(testoutput);
   pass &= RunIndividualTest("\n", testoutput.str(), "Print empty array");

   // Append 100 through 110 to a (11 elements total)
   for (int i = 100; i < 111; i++) {
      a.append(i);
   }
   testoutput.str(""); // Reset test output string
   a.print(testoutput);
   pass &= RunIndividualTest("100 101 102 103 104 105 106 107 108 109 \n110 \n",
      testoutput.str(), "Appending 100 through 110");

   // Check capacity of new array
   pass &= RunIndividualTest("20", to_string(a.cap()),
       "Capacity after adding 11 elements to empty array");

   // Append 111 through 120 (21 elements total):
   for (int i = 111; i < 121; i++) {
      a.append(i);
   }
   testoutput.str(""); // Reset test output string
   a.print(testoutput);
   pass &= RunIndividualTest(
      "100 101 102 103 104 105 106 107 108 109 \n110 111 112 113 114 115 116 117 118 119 \n120 \n",
      testoutput.str(), "Appending 111 through 120");

   // Check capacity of new array
   pass &= RunIndividualTest("40", to_string(a.cap()),
       "Capacity after adding 10 elements to 11-element array");

   // Test at()
   int indices[] = { 9, 3, 5, 0, 18 };
   for (int i = 0; i < 5; i++) {
       pass &= RunIndividualTest(to_string(100+indices[i]),
                to_string(a.at(indices[i])),
                "Accessing index " + to_string(indices[i]));
   }
   // Shouldn't crash
   int yourchosenvalue =  a.at(10000000);

   // Test sum
   pass &= RunIndividualTest(to_string(2310), to_string(a.sum()),
               "First sum test");

   // Test remove:
   //   Remove (a) 102 (should return true)
   //          (b) 122 (should return false)
   pass &= RunIndividualTest("1", to_string(a.remove(102)), "Remove 102");
   pass &= RunIndividualTest("0", to_string(a.remove(122)), "Remove 122");

   // More tests: first, add 102 back in
   a.append(102);

   // Test resizing
   int capacities[] = {40,             // len is 20
                       32, 32, 32, 32, // len is 19, 18, 17, 16
                       25, 25, 25,     // len is 15, 14, 13
                       20, 20, 20,     // len is 12, 11, 10,
                       16, 16, 12, 12, 10, // len is 9, 8, 7, 6, 5
                       10, 10, 10, 10, 10 // 4, 3, 2, 1, 0
                      };
   for (int i = 0; i < 21; i++) {
      a.remove(100 + i);
      pass &= RunIndividualTest(to_string(capacities[i]), to_string(a.cap()),
          "Resize test; removed " + to_string(100 + i) + ", capacity is " +
             to_string(a.cap()) + ", should be " + to_string(capacities[i]));
   }

   // Array is now empty. Add and print one value.
   a.append(152);
   testoutput.str(""); // Reset test output string
   a.print(testoutput);
   pass &= RunIndividualTest("152 \n", testoutput.str(), "Final append to empty array");

   return pass; 
}
