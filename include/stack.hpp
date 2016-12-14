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
class stack
{
public:
    stack():
        allocator_(start_size_)
    {}

    ~stack() {}

    std::size_t count() const noexcept
    {
        return allocator_.count();
    }

    void push(const T& elem)
    {
        if(allocator_.full())
        {
            allocator_.resize();
        }
        allocator_.construct(allocator_.get() + allocator_.count(), elem);
        allocator_.increment_count();
    }

    void pop()
    {
        if(allocator_.empty())
        {
            throw empty_stack();
        }

        allocator_.destroy(allocator_.get() + allocator_.count() - 1);
        allocator_.decrement_count();
    }

    T& top()
    {
        if(allocator_.empty())
        {
            throw empty_stack();
        }

        return *(allocator_.get() + allocator_.count() - 1);
    }

    bool empty() const noexcept
    {
        return allocator_.empty();
    }

    bool operator==(const stack<T>& rhs)
    {
        return (allocator_ == rhs.allocator_);
    }

private:
    allocator<T> allocator_;

    static const std::size_t start_size_ = 16;
};
