#include"graal.h"
//#include<cstdlib>
#include<iostream>
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

    void reverse(void *first, void *last, std::size_t typeSize, void (swap)(void*, void*))
    {
        //std::cout << "Pog1";
        byte *newFirst = (byte*) first;
        byte *newLast = (byte*)last;
        newLast -= typeSize;
        //std::cout << "Pog2";
        byte *mid = newFirst + ((std::distance(newFirst, newLast))/2);
        //std::cout << "Pog3";
        while(newFirst != mid)
        {
            swap(newLast, newFirst);
            newFirst+= typeSize;
            newLast -= typeSize;
        }
    }

    void * copy(void * firstA, void *lastA, void * firstB, std::size_t typeSize)
    {
        byte *newFirstA = (byte *) firstA;
        byte *newLastA = (byte *) lastA;
        byte *newFirstB = (byte *) firstB;

        while(newFirstA != newLastA)
        {
            *newFirstB = *newFirstA;
            newFirstA++;
            newFirstB++;
        }
        return newFirstB;
    }

    void * clone(void * first, void *last, std::size_t typeSize)
    {
        byte *newFirst = (byte *) first;
        byte *newLast = (byte *) last;
        int size = std::distance(newFirst, newLast);

        byte *newArray = new byte[size];
        byte *firstIndex = newArray;

        while(newFirst != newLast)
        {
            *newArray = *newFirst;
            newFirst++;
            newArray++;
        }

        return firstIndex;
    }

    void * find_if(void * first, void *last, std::size_t typeSize, bool (predicate)(void *))
    {
        byte * newFirst = (byte*)first + typeSize;
        byte * newLast = (byte*) last;

        while(newFirst != newLast)
        {
            if(predicate(newFirst))
                return newFirst;
            newFirst+= typeSize;
        }
        
        return last;
    }

    bool all_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *))
    {
        byte * newFirst = (byte*)first + typeSize;
        byte * newLast = (byte*) last;

        if(newFirst == newLast)
            return true;

        while(newFirst != newLast)
        {
            if(!predicate(newFirst))
                return false;
            newFirst+= typeSize;
        }
        
        return true;
    }

    bool any_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *))
    {
        byte * newFirst = (byte*)first + typeSize;
        byte * newLast = (byte*) last;

        if(newFirst == newLast)
            return true;

        while(newFirst != newLast)
        {
            if(predicate(newFirst))
                return true;
            newFirst+= typeSize;
        }
        
        return false;
    }

    bool none_of(void * first, void *last, std::size_t typeSize, bool (predicate)(void *))
    {
        byte * newFirst = (byte*)first + typeSize;
        byte * newLast = (byte*) last;

        if(newFirst == newLast)
            return true;

        while(newFirst != newLast)
        {
            if(predicate(newFirst))
                return false;
            newFirst+= typeSize;
        }
        
        return true;
    }

}