
#ifndef GRAAL_H
#define GRAAL_H
#include<cstdlib>
#include<vector>

namespace graal{

    using Compare = bool (*)(void *, void *);
    using byte = unsigned char;

    /// Returns the first occurence of the smallest element in the array.
    void * min( void *first, void *last, size_t typeSize, Compare comp);

    /// Reverses the elements of the array.
    void reverse(void *first, void *last, std::size_t typeSize, void (swap)(void*, void*));

    /// Copies one array to the other. The arrays must be of the same type and size. Returns the first element PAST the copied range.
    void * copy(void * firstA, void *lastA, void * firstB, std::size_t typeSize);

    /// Clones the array, returning the pointer to the first element in the range.
    void * clone(void * first, void *last, std::size_t typeSize);

    /// Runs through an array and returns the first element in accord with predicate. Predicate must be a bool(void *).
    void * find_if(void * first, void *last, std::size_t typeSize, bool (predicate)(void *));

    /// Runs through an array and returns true if ALL OF the elements are in accord with predicate. Predicate must be a bool(void *).
    bool all_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *));

    /// Runs through an array and returns true if ANY OF the elements are in accord with predicate. Predicate must be a bool(void *).
    bool any_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *));

    /// Runs through an array and returns true if NONE OF the elements are in accord with predicate. Predicate must be a bool(void *).
    bool none_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *));

    

}
#endif