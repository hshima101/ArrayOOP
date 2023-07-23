class ArrayIterator
{
    private:
        const char* data_;
        int current_index_;
        int max_size_;
        bool ascending;

    public:
        ArrayIterator(const char* data, int max_size, bool ascending);

        char operator*();

        void operator++();

        bool operator!=(const ArrayIterator& other) const;

        void printArray(bool ascending = true);

};