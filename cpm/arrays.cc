#include "common.cc"


namespace arrays {
    using c::size_t;
    
    #define DEF_T template<typename T>

    constexpr size_t INIT_CAPACITY = 15;
    
    /// scalable generic array of values T
    template<typename T>
    struct array {
        T* items = nullptr;
        size_t count = 0;
        size_t capacity = 0;

        /// reserve space for `init_capacity` items
        bool init(size_t init_capacity);
        void free();
        void clear();


        bool push(T item);
        optional<T> pop();
        bool insert(size_t index, T item);
        
        /// reallocate to `capacity + sizeof(T) * 2`
        bool realloc();
        bool needs_realloc(size_t new_items);

        bool find(const T& needle);
    };
    

#ifdef CPM_IMPLEMENTATION
    DEF_T void array<T>::free() {
        count = 0;
        capacity = 0;
        c::free(items);
        items = nullptr;
    }

    DEF_T void array<T>::clear() {
        count = 0;
    }

    DEF_T bool array<T>::init(size_t init_capacity) {
        capacity = init_capacity;
        items = static_cast<T*>(c::malloc(init_capacity * sizeof(T)));
        return items != nullptr;
    }

    DEF_T bool array<T>::needs_realloc(size_t new_items) {
        return new_items * sizeof(T) + count * sizeof(T) > capacity;
    }

    DEF_T bool array<T>::realloc() {
        capacity = capacity + sizeof(T) * 2;
        items = static_cast<T*>(c::realloc(static_cast<void*>(items), capacity));
        return items != nullptr;
    }

    DEF_T optional<T> array<T>::pop() {
        if (!count) return optional<T>::empty();
        return optional<T>::some(items[--count]);
    }
    

    DEF_T bool array<T>::push(T item) {
        if (needs_realloc(1)) {
            if (capacity == 0) {
                capacity = INIT_CAPACITY * sizeof(T);
                items = static_cast<T*>( c::malloc(capacity) );
                if (items == nullptr) return false;
            } else {
                if (!realloc()) return false;
            }
        }
        items[count] = item;
        count += 1;
        return true;
    }
    
    DEF_T bool array<T>::find(const T& needle) {
        // O(n)
        for (size_t i = 0; i < count; i++)
            if (items[i] == needle) return true;
        return false;
    }
    
#endif

    #undef DEF_T
}

