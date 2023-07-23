#include <iostream>
#include <cstring>
#include "Array.h"
#define DEFAULT 5

Array::Array()
{
    data_ = (new char[DEFAULT]);
    cur_size_ = DEFAULT;
    max_size_ = DEFAULT;
    //fill();
    std::cout<<"input number data"<<std::endl;
    for(int i = 0; i < this->max_size_; i++)
    {
        std::cin>>data_[i];
    }
    printArray();
    //sortArrayIntAsc(data_);
    //printArray();
}

Array::Array(size_t length)
{
    data_ = (new char[DEFAULT]);
    cur_size_ = length;
    max_size_ = length;
    //use resize function to change data_ length
    resize(length);
    printArray();
}

Array::Array(size_t length, char ch)
{
    data_ = (new char[DEFAULT]);
    cur_size_ = length;
    max_size_ = length;
    //use resize function to change data_ length
    resize(length);
    //use fill function
    fill(ch);
    printArray();
}

Array::Array(const Array & array)
{
    std::cout<<"Copy constructor has been implemented"<<std::endl;
    data_ = (new char[DEFAULT]);
    cur_size_ = 0;
    max_size_ = 0;

    cur_size_ = array.cur_size_;
    max_size_ = array.max_size_;
    data_ = (new char[max_size_]);

    for(int i = 0; i < max_size_; i++)
    {
        data_[i] = array.data_[i];
    }
}

Array::~Array(void)
{ 
    delete [] data_;
    std::cout<<"Array has been deleted"<<std::endl;
}

void Array::fill()
{
    for(int i = 0; i < this->max_size_; i++)
    {
        this->data_[i] = '#';
    }
}

void Array::fill(char ch)
{
    for(int i = 0; i < this->max_size_; i++)
    {
        this->data_[i] = ch;
    }
}

void Array::printArray()
{
    for(int i = 0; i < this->cur_size_; i++)
    {
        std::cout<<data_[i];
    }
    std::cout<<std::endl;
}

void Array::resize(size_t new_size_)
{
    std::cout<<"resizing the array"<<std::endl;
    char* temp = (new char[new_size_]);
    for(int i = 0; i < this -> max_size_; i++)
    {
        temp[i] = this -> data_[i];
    }
    //delete data
    delete[] this->data_;
    this -> cur_size_ = new_size_;
    this -> max_size_ = new_size_;
    //create new data and reference point to updated max size
    this -> data_ = (new char[this->max_size_]);
    for(int i = 0; i < this-> max_size_; i++)
    {
        this -> data_[i] = temp[i];
    }
    delete[] temp;
}

//figure out why bubble sort isn't functioning correctly
void Array::sortArrayIntAsc(char* data_)
{
    std::cout<<"Sorting ascending "<<std::endl;
    //make a new container object and print it out
    int* temp_data_ = (new int[this->max_size_]);
    for(int i = 0; i < this->max_size_; i++)
    {
        temp_data_[i] = static_cast<int>(data_[i]);
    }
    std::cout<<std::endl;

    std::cout<<"printing temporary data"<<std::endl;
    for(int i = 0; i < this-> max_size_; i++)
    {
        std::cout<<temp_data_[i];
    }

    for(int i = 0; i < this->max_size_ - 1; i++)
    {
        for(int j = 0; j < this->max_size_ - i - 1; j++)
        {
            if(temp_data_[j] > temp_data_[j + 1])
            {
                int temp = temp_data_[j];
                temp_data_[j] = temp_data_[j + 1];
                temp_data_[j + 1] = temp;
            }
        }
    }

    std::cout<<"printing temporary data"<<std::endl;
    for(int i = 0; i < this-> max_size_; i++)
    {
        std::cout<<temp_data_[i];
    }

    std::cout<<std::endl;
    delete[] temp_data_;
}

void Array::sortArrayIntDec(char* data_)
{
    for(int i = 0; i < this->max_size_ - 1; i++)
    {
        for(int j = i + 1; j < this-> max_size_; j++)
        {
            if(data_[j] < data_[j + 1])
            {
                int temp = data_[j];
                data_[j] = data_[j + 1];
                data_[j + 1] = temp;
            }
        }
    }
}