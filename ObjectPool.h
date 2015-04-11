#include <iostream>
#include <queue>
#include <vector>
 
template <typename T>
class ObjectPool
{
public:
    ObjectPool(size_t chunk_size = kdefault_size);
    ~ObjectPool();
 
    T& acquire_object();
    void release_object(T& obj);
 
protected:
    void allocate_chunk();
    static void array_delete_object(T* obj);
 
private:
    std::queue<T*> free_list_;
    std::vector<T*> all_objects_;
    int chunk_size_;                            //对象池中预分配对象个数
    static const size_t kdefault_size = 100;    //默认对象池大小
 
    ObjectPool(const ObjectPool<T>& src);
    ObjectPool<T>& operator=(const ObjectPool<T>& rhs);
};
