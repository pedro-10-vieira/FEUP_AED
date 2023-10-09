# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//=============================================================================
// Exercise 3: StackExt class
//=============================================================================
//TODO
template <class T>
bool StackExt<T>::empty() const {
    return values.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    return values.top();
}

//TODO
template <class T>
void StackExt<T>::pop() {
    values.pop();
}

//TODO
template <class T>
void StackExt<T>::push(const T& val) {
    values.push(val);
}

//TODO
/**
 * Esta função encontra o valor mais pequeno presente numa stack
 * @tparam T
 * @return
 */
template <class T>
T& StackExt<T>::findMin() {
    stack<T> temp = values;
    while (!temp.empty()) {
        if (minimums.empty() || temp.top() < minimums.top()) {
            minimums.push(temp.top());
            temp.pop();
        }
        else {
            temp.pop();
        }
    }
    return minimums.top();
}
