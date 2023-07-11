
#ifndef SMORTYP_UNIQUE_PTR_H
#define SMORTYP_UNIQUE_PTR_H
//***************************
//noexcept since destructors are called \
//anyway even if there is an exception.
//****************************
#include "iostream"
#include "memory"
#include "utility"
#include "vector"

template<class T>
class unique_ptr {
public:
    unique_ptr() noexcept: unique_ptr{nullptr} {}
    explicit unique_ptr(T *ptr) noexcept: _mPtr{ptr} {}
    ~unique_ptr() noexcept
    {
        if(_mPtr) delete _mPtr;
    }
    //copy constructor and copy assignment operator
    //because of the nature of unique_ptr, having
    //a copy constructor does not make sense.
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator  = (const unique_ptr &) = delete;
    unique_ptr(unique_ptr &&other) noexcept : _mPtr{other.release()} {}

    unique_ptr &operator=(unique_ptr &&other) noexcept
    {
        if(this != &other) reset(other.release());
        return *this;
    }

    ///Giving ownership to another
    T* release() noexcept;

    void reset(T* ptr = nullptr) noexcept;


    explicit operator bool() const noexcept;

    T* get() const noexcept;

    T* operator->() const noexcept;

    T &operator*() const noexcept;

private:
    //member pointer
    T *_mPtr;
};


#endif //SMORTYP_UNIQUE_PTR_H
