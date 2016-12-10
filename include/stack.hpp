#include <new>
#include <exception>
#include <stdexcept>

class empty_stack: public std::exception
{
public:
    const char* what() const throw()
    {
        return "stack is empty";
    }
};

template <typename T>
class stack
{
public:
    stack():
        array_(array_ = static_cast<T*>(operator new[](start_size_ * sizeof(T)))),
        array_size_(start_size_),
        count_(0)
    {}

    ~stack()
    {
        operator delete[](array_);
    }

    std::size_t count() const noexcept
    {
        return count_;
    }

    void push(const T& elem) /* strong */
    {
        if(count_ == array_size_)
        {
            T* new_array = static_cast<T*>(operator new[](array_size_ * sizeof(T) * 2));
            for(std::size_t i = 0; i < count_; ++i)
            {
                try
                {
                    new(&new_array[i]) T(array_[i]);
                }
                catch(...)
                {
                    operator delete[](new_array);
                    throw;
                }
            }
            operator delete[](array_);
            array_ = new_array;
            array_size_ *= 2;
        }

        new(&array_[count_]) T(elem);
        ++count_;
    }

    auto pop() -> void /* strong */
    {
        if(count_ == 0)
        {
            throw empty_stack();
        }
        
        --count_;
        
    }
    
    const T& top() /* strong */
    {
        if(count_ == 0)
        {
            throw empty_stack();
        }

       return array_[count_-1];
    }

    auto empty() const noexcept -> bool
    {
        if (count_ == 0)
        {

             return true;

        }

        else
        {
            return false;
        }


    }


    bool operator==(const stack<T>& rhs)
    {
        if(count_ != rhs.count_)
        {
            return false;
        }

        for(std::size_t i = 0; i < count_; ++i)
        {
            if(array_[i] != rhs.array_[i])
            {
                return false;
            }
        }

        return true;
    }

private:
    T* array_;
    std::size_t array_size_;
    std::size_t count_;

    static const std::size_t start_size_ = 16;
};
