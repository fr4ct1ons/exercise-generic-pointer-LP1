
#ifndef GRAAL_H
#define GRAAL_H
#include<cstdlib>

namespace graal{

    using Compare = bool (*)(void *, void *);
    using byte = unsigned char;

    /// Returns the first occurence of the smallest element in the array.
    void * min( void *first, void *last, size_t typeSize, Compare comp);

    /// Reverses the elements of the array.
    void reverse(void *first, void *last, size_t typeSize);

}
#endif