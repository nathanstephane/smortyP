

#include "unique_ptr.h"

template<class T>
T *unique_ptr<T>::release() noexcept {
    T* old = _mPtr;
    _mPtr = nullptr;
    return old;//or std::exchange(_mPtr, nullptr);
}



template<class T>
void unique_ptr<T>::reset(T *ptr) noexcept
{
    T* old = _mPtr;
    _mPtr = ptr;
    if(old) delete old;
}


template<class T>
unique_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(_mPtr);
}

template<class T>
T *unique_ptr<T>::get() const noexcept
{
    return _mPtr;
}

template<class T>
T *unique_ptr<T>::operator->() const noexcept
{
    return _mPtr;
}

template<class T>
T &unique_ptr<T>::operator*() const noexcept
{
     return *_mPtr;;
}
