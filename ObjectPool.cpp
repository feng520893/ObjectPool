#include "ObjectPool.h"
#include <algorithm>
 
template <typename T>
const size_t ObjectPool<T>::kdefault_size;
 
template <typename T>
ObjectPool<T>::ObjectPool(size_t chunk_size /* = kdefault_size */) : chunk_size_ (chunk_size)
{
    if (chunk_size_ <= 0)
    {
        std::cout << "Object size invalid" << std::endl;
    }
    else
    {
        allocate_chunk();
    }
}
 
template <typename T>
void ObjectPool<T>::array_delete_object(T* obj)
{
    delete obj;
}
 
template <typename T>
ObjectPool<T>::~ObjectPool()
{
    std::for_each(all_objects_.begin(), all_objects_.end(), ObjectPool<T>::array_delete_object);
}
 
template <typename T>
void ObjectPool<T>::allocate_chunk()
{
    T* new_objects = new T(chunk_size_);
    for (int i = 0; i < chunk_size_; ++i)
    {
        all_objects_.push_back(&new_objects[i]);
        free_list_.push(&new_objects[i]);
    }
}
 
template <typename T>
T& ObjectPool<T>::acquire_object()
{
    if (free_list_.empty())
    {
        allocate_chunk();
    }
    T *obj = free_list_.front();
    free_list_.pop();
    return (*obj);
}
 
template <typename T>
void ObjectPool<T>::release_object(T& obj)
{
    free_list_.push(&obj);
}
