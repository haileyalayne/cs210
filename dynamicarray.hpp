
class DynamicArray {
   public:
      DynamicArray();
      ~DynamicArray();
      DynamicArray(const DynamicArray& arrayToCopy);
      void append(int newVal);
      int at(int index) const;
      int sum() const;
      bool remove(int valToDelete); 
      void print(std::ostream& s) const;
      int cap() const { return capacity; }
      bool operator==(const DynamicArray& other) const;
      DynamicArray& operator=(const DynamicArray& otherArray);
      friend std::ostream& operator<<(std::ostream &out, const DynamicArray& pt);
  
   private:
      int* arr;
      int len; // Number of elements actually populated
      int capacity; // New variable - this is the current capacity of the array

};
