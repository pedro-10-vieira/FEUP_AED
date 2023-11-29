#ifndef BOX_H_
#define BOX_H_

#include <stack>
#include <iostream>

using namespace std;

class Object {
	unsigned id;
	unsigned weight;
public:
	Object(unsigned i, unsigned w);
	unsigned getID() const;
	unsigned getWeight() const;
	bool operator<(const Object& o1) const;
};


typedef stack<Object> StackObj;

class Box {
	StackObj objects;
	unsigned capacity;
	unsigned free;
public:
    Box(unsigned cap=10);
    unsigned getCapacity() const;
    unsigned getFree() const;
    void addObject(Object& obj);
    StackObj getObjects() const;
    unsigned getSize() const;
	bool operator<(const Box& b1) const;
};

#endif
