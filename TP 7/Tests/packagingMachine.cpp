#include "packagingMachine.h"

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}


//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================
// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    auto it = objs.begin();
    while (it != objs.end()) {
        if (it->getWeight() <= boxCapacity) {
            objects.push(*it);
            it = objs.erase(it);
            continue;
        }
        it++;
    }
    return objects.size();
}


//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox temp;
    while (!boxes.empty()) {
        if (boxes.top().getFree() >= obj.getWeight()) {
            Box box = boxes.top();
            boxes.pop();
            while (!temp.empty()) {
                boxes.push(temp.top());
                temp.pop();
            }
            return box;
        }
        temp.push(boxes.top());
        boxes.pop();
    }
    boxes.swap(temp);
    return {};
}



//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
// TODO
unsigned PackagingMachine::packObjects() {
    unsigned count = 0;
    while (!objects.empty()) {
        Object it = objects.top();
        Box update = searchBox(it);
        if (update.getSize() == 0) {
            Box box;
            box.addObject(it);
            boxes.push(box);
            count++;
        }
        else {
            update.addObject(it);
            boxes.push(update);
        }
        objects.pop();
    }
    return count;
}


//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
    HeapBox clone = boxes;
    Box the_one;
    unsigned max_objects = 0;
    while (!clone.empty()) {
        Box box = clone.top();
        if (box.getSize() > max_objects) {
            the_one = box;
            max_objects = box.getSize();
        }
        clone.pop();
    }
    return the_one.getObjects();
}
