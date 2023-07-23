#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>

class Array
{
    public:
    //constructors 
    Array();

    Array(size_t length);

    Array(size_t length, char fill);

    Array(const Array & arr);

    ~Array(void);

    /**
     * Assignment Operation
     * 
     * param[in]   rhs   Right hand side of equal sign
     * return      reference to self
    */
    const Array & operator = (const Array & rhs);

    //return current size element of the array class
    size_t size (void) const;

    //return max size element of the array class
    size_t max_size (void) const;

    //return a character within a specific index
    char & operator [] (size_t index);

    //returned character is not modifiable
    const char & operator [] (size_t index) const;

    //get character in specific index
    //if character is not within index then 
    //out_of_rangee exception is thrown
    char get (size_t index) const;

    //set a character in a specified index
    void set (size_t index, char value);

    //set a new size for the array
    void resize(size_t new_size);

    //shrink the array to reclaim unused space
    void shrink();

    //find specific character within array
    int find (char ch) const;

    //find a specific character from a starting point
    int find (char ch, size_t start) const;
    /**
     * Test the array for equality
     * 
     * param[in] rhs   right hand side of the equal sign
     * return value  true Left side is equal to right side
     * return value  false   Left side is not equal to right side
    */
    bool operator == (const Array & rhs) const;

    /**
     * Test the array for equality
     * 
     * param[in] rhs   right hand side of the equal sign
     * return value  true Left side is not equal to right side
     * return value  false   Left side is equal to right side
    */
    bool operator != (const Array & rhs) const;

    /**
     * Fill the contents of the Array
     * 
     * param[in]   ch FIll the character
    */
    void fill();

    void fill (char ch);

    /// reverse the contents of the array
    void reverse(void);

    //print the array
    void printArray();  

    //Sorting Types
    void sortArrayIntAsc(char* data_);

    void sortArrayIntDec(char* data_);

    void sortArrayCharAsc(char* data_);

    void sortArrayCharDec(char* data_);

private:
    /////////////////////////
    //DEFINE ANY HELPER METHODS HERE

    /////////////////////////

    ///// Pointer to actual data
    char * data_;

    ///// Current size of the array
    size_t cur_size_;

    ///// Max size of the array
    size_t max_size_;

    friend class Iterator;
};



#endif