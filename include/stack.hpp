#include <exception>

#include "allocator.hpp"

class empty_stack: public std::exception
{
public:
    const char* what() const throw()
    {
        return "stack is empty";
    }
};

template <typename T>
class stack: public allocator<T>
{
public:
    stack():
        allocator<T>(start_size_)
    {}

    
    std::size_t count() const noexcept
    {
        return allocator<T>::count_;
    }

    void push(const T& elem) /* strong */
    {
        allocator<T>::allocate();
        new(&allocator<T>::ptr_[allocator<T>::count_]) T(elem);
        ++allocator<T>::count_;
    }

    void pop() /* strong */
    {
        if(allocator<T>::count_ == 0)
        {
            throw empty_stack();
        }

        allocator<T>::ptr_[allocator<T>::count_ - 1].~T();
        --allocator<T>::count_;
    }

    T& top() /* strong */
    {
        if(allocator<T>::count_ == 0)
        {
            throw empty_stack();
        }

        return allocator<T>::ptr_[allocator<T>::count_ - 1];
    }

    auto empty() const noexcept -> bool
    {
        return (allocator<T>::count_ == 0);
    }

    
    bool operator==(const stack<T>& rhs)
        {
            if(allocator<T>::count_ != rhs.count_)
            {
                return false;
            }
    
            for(std::size_t i = 0; i < allocator<T>::count_; ++i)
            {
                if(allocator<T>::ptr_[i] != rhs.ptr_[i])
                {
                    return false;
                }
            }
    
            return true;
        }
    
private:
    static const std::size_t start_size_ = 16;
};
