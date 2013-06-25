

#pragma once
#ifndef __SPACEG_OBJECTSTORAGE__
#define __SPACEG_OBJECTSTORAGE__

#include <cstddef>

#include <iostream>

namespace spaceg {
	
//For Ref: http://bitsquid.blogspot.de/2011/09/managing-decoupling-part-4-id-lookup.html
	
class Storage
{
public:
	//generic objectid type
	typedef unsigned int ObjectId;
};

/**
* Store objects
*/
template<class T>
class ObjectStorage : public Storage
{
private:
	static const size_t MAX_OBJECTS = 1024*64; //16bit type  0x0000ffff
	
	// limit 8-16 bit?
	// types: 256 (8bit), 1024 (10bit), 4096 (12bit), 65536 (16bit)
	
	static const int INDEX_MASK = 0x0000ffff; // == MAX_OBJECTS
	static const int NEW_OBJECT_ID_ADD = 0x10000; // == INDEX_MASK+1
	
	struct Index
	{
		ObjectId id;		  //complete id
		unsigned short index; //object array index ObjectID && INDEX_MASK
		unsigned short next;  //next free index?
	};
	
	T objects_[MAX_OBJECTS];
	Index indices_[MAX_OBJECTS];
	
	
	size_t num_objects_; //number of objects 
	unsigned short freelist_enqueue_;
	unsigned short freelist_dequeue_;
	
public:
	//create special internal structure for element count?
	
	
	//TODO interate overall available objects

	ObjectStorage()
	{
		num_objects_ = 0;
		
		for (unsigned int i=0; i<MAX_OBJECTS; ++i) 
		{
			indices_[i].id = i;
			indices_[i].next = i+1;
		}
		freelist_dequeue_ = 0;
		freelist_enqueue_ = MAX_OBJECTS-1;
	}
	
	inline ObjectId add()
	{
		Index &in = indices_[freelist_dequeue_];
		freelist_dequeue_ = in.next;
		in.id += NEW_OBJECT_ID_ADD; //first 2 bytes are the valid counter?
		in.index = num_objects_++;
		//T &o = objects_[in.index];
		//o.id = in.id;
		return in.id;
	}
	
	inline void remove(const ObjectId& id)
	{
		Index &in = indices_[id & INDEX_MASK];
		
		T &o = objects_[in.index];
		//o.reset(); //why is this required? see LuaBinder delete
		o = objects_[--num_objects_];
		indices_[id & INDEX_MASK].index = in.index;
		
		in.index = 0x0000ffff; //ushrt_MAX
		indices_[freelist_enqueue_].next = id & INDEX_MASK;
		freelist_enqueue_ = id & INDEX_MASK;
	}
	
	inline bool has(const ObjectId& id)
	{
		Index &in = indices_[id & INDEX_MASK];
		return in.id == id && in.index != 0x0000ffff; //ushort max
	}
	
	inline T& get(const ObjectId& id)
	{
		if((id & INDEX_MASK) >= MAX_OBJECTS)
			throw "error";
		auto index = indices_[id & INDEX_MASK].index;
		
		if(index >= MAX_OBJECTS)
			throw "error";
		return objects_[index];
	}
	
	
	inline T& operator[](size_t index) { return objects_[index]; }
	inline size_t objCount() const { return num_objects_; }
	inline size_t objStorageCount()  const { return MAX_OBJECTS; }
	inline size_t memorySize() const { return (sizeof(T) * MAX_OBJECTS) + (sizeof(Index) * MAX_OBJECTS); }
};
	
	
} // end namespace

#endif
