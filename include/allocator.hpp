#include <new>
#include <algorithm>

template <typename T>
class allocator
{
public:
    explicit allocator(std::size_t size = 0):
        ptr_(nullptr),
        size_(size),
        count_(0)
    {
        if(size > 0)
        {
            ptr_ = static_cast<T*>(operator new[](size * sizeof(T)));
        }
    }

    allocator(allocator const&) = delete;
    auto operator =(allocator const&) -> allocator& = delete;

    virtual ~allocator()
    {
        deallocate(ptr_, count_);
    }

    auto resize() -> void
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

    auto swap(allocator& other) -> void
    {
        std::swap(ptr_, other.ptr_);
        std::swap(size_, other.size_);
        std::swap(count_, other.count_);
    }

    auto construct(T* ptr, T const& value) -> void
    {
        if(ptr != nullptr)
        {
            new(ptr) T(value);
        }
    }

    auto destroy(T* ptr) -> void
    {
        if(ptr != nullptr)
        {
            ptr->~T();
        }
    }

    auto get() -> T*
    {
        return ptr_;
    }

    auto get() const -> T const*
    {
        return ptr_;
    }

    auto count() const -> std::size_t
    {
        return count_;
    }

    auto full() const -> bool
    {
        return (count_ == size_);
    }

    auto empty() const -> bool
    {
        return (count_ == 0);
    }

    auto increment_count() -> void
    {
        ++count_;
    }

    auto decrement_count() -> void
    {
        --count_;
    }

    bool operator==(const allocator<T>& rhs)
    {
        if(count_ != rhs.count_)
        {
            return false;
        }

        for(std::size_t i = 0; i < count_; ++i)
        {
            if(ptr_[i] != rhs.ptr_[i])
            {
                return false;
            }
        }

        return true;
    }

private:
    auto deallocate(T* ptr, std::size_t count) -> void
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            ptr_[i].~T();
        }
        operator delete[](ptr);
    }

private:
    T* ptr_;
    std::size_t size_;
    std::size_t count_;
};
