#include <new>
#include <algorithm>

template <typename T>
class allocator
{
protected:
    allocator(std::size_t size = 0):
         ptr_(nullptr),
         size_(size),
         count_(0)
     {
         if(size > 0)
         {
             ptr_ = static_cast<T*>(operator new[](size * sizeof(T)));
         }
     }

    virtual ~allocator()
    {
        deallocate(ptr_, count_);
    }

    auto swap(allocator& other) -> void
    {
        std::swap(ptr_, other.ptr_);
        std::swap(size_, other.size_);
        std::swap(count_, other.count_);
    }

    auto allocate() -> void
    {
        if(count_ == size_)
        {
            T* new_ptr = static_cast<T*>(operator new[](size_ * sizeof(T) * 2));
            for(std::size_t i = 0; i < count_; ++i)
            {
                try
                {
                    new(&new_ptr[i]) T(ptr_[i]);
                }
                catch(...)
                {
                    deallocate(new_ptr, i);
                    throw;
                }
            }
            deallocate(ptr_, count_);
            ptr_ = new_ptr;
            size_ *= 2;
        }
    }

    auto deallocate(T* ptr, std::size_t count) -> void
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            ptr_[i].~T();
        }
        operator delete[](ptr);
    }

    allocator(allocator const&) = delete;
    auto operator =(allocator const&) -> allocator& = delete;
    
    T* ptr_;
    std::size_t size_;
    std::size_t count_;
};
