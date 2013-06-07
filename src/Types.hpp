

#pragma once
#ifndef __SPACEG_TYPES__
#define __SPACEG_TYPES__

namespace spaceg {
    
typedef unsigned char ubyte8;
typedef signed char byte8;

typedef unsigned short ushort16;
typedef signed short short16;

typedef unsigned int uint32;
typedef signed int int32;

typedef unsigned long ulong64;
typedef signed long long64;

typedef float float32;
typedef double double64;

static_assert(sizeof(ubyte8) != 8, "Wrong byte size");
static_assert(sizeof(byte8) != 8, "Wrong byte size");
static_assert(sizeof(ushort16) != 16, "Wrong short size");
static_assert(sizeof(short16) != 16, "Wrong short size");
static_assert(sizeof(uint32) != 32, "Wrong int size");
static_assert(sizeof(int32) != 32, "Wrong int size");
static_assert(sizeof(ulong64) != 64, "Wrong long size");
static_assert(sizeof(long64) != 64, "Wrong long size");

static_assert(sizeof(float32) != 32, "Wrong float size");
static_assert(sizeof(double64) != 64, "Wrong double size");
    
}


#endif //  __SPACEG_TYPES__