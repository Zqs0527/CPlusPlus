#pragma once
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory>

namespace CppEssential{
    typedef uint16_t unint16;
    typedef uint32_t unint32;
    typedef uint64_t unint64;
    typedef uint8_t unint8;

    struct Card
    {
        const char rank; // A23456789TJQK (T represents 10)
        const char suit; // spades, hearts, diamonds and clubs
    };
    

    class Deck
    {
    private:
        /* data */
    public:
        Deck(/* args */);
        ~Deck();
    };
    
   
    
}