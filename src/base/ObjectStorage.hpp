

#pragma once
#ifndef __SPACEG_OBJECTSTORAGE__
#define __SPACEG_OBJECTSTORAGE__

namespace spaceg {
	
//For Ref: http://bitsquid.blogspot.de/2011/09/managing-decoupling-part-4-id-lookup.html
	
/**
* Id for an object
*/
struct ObjectId 
{
	unsigned int id;
}

/**
* Store objects
*/
template<class T>
class ObjectStorage
{
private:
	static const size_t MAX_OBJECTS = 1000;
	
	struct Index
	{
	};
	
	T objects_[MAX_OBJECTS];
	Index indices_[MAX_OBJECTS]
	
public:

	ObjectStorage(size_t size)
	{
		
	}
	
	inline ObjectId add()
	{
	}
	
	inline void remove(const ObjectId& id)
	{
	}
	
	inline bool has(const ObjectId& id)
	{
		
	}
	
	inline Object& get(const ObjectId& id)
	{
	}
	
	
	inline size_t memorySize() { return (sizeof(T) * MAX_OBJECTS) + (sizeof(Index) * MAX_OBJECTS); }
};
	
	
} // end namespace

#endif
