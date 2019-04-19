#include"graal.h"
//#include<cstdlib>
namespace graal{

    void * min( void *first, void *last, std::size_t typeSize, Compare smaller)
    {
        byte *buffer = (byte*) first;
        byte * newFirst = (byte*)first + typeSize;
        byte * newLast = (byte*) last;

        while(newFirst != newLast)
        {
            if(smaller(newFirst, buffer))
                buffer = (byte*) newFirst;
            newFirst+= typeSize;
        }
        
        return buffer;
    }

    void reverse(void *first, void *last, size_t typeSize)
    {
        
    }

}