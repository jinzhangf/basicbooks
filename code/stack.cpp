#include "base.h"

struct StackNode
{
	int val;
	StackNode *next;

	StackNode() : next(NULL) {}
	StackNode(int v) : val(v), next(NULL) {}
};

class MyStack
{
public:
	MyStack() {}
	void push(int val);
	int pop();
	int size() { return _stack.size(); }
	int max() { return _max.next->val; }
	void display();

private:
	vector<StackNode*> _stack;
	StackNode _max;
};

void MyStack::push(int val)
{
	StackNode *node = new StackNode(val);
	if (_stack.empty()) {
		_max.next = node;
	}
	else if (val > _max.next->val) {
		node->next = _max.next;
		_max.next = node;
	}

	_stack.push_back(node);
}

int MyStack::pop()
{
	// ERROR, 简化处理
	if (_stack.empty()) return -1;

	int val = _stack.back()->val;
	StackNode *p = _stack.back();
	if (p == _max.next) {
		_max.next = p->next;
		p->next = NULL;
	}
	delete p;
	_stack.pop_back();
	return val;
}

void MyStack::display()
{
	if (_stack.empty()) return;
	
	for (auto &item : _stack) {
		cout << item->val << " ";
	}
	cout << ", max=" << max() << endl;
}

int main()
{
	MyStack stack;
	string cmd;
	while (cin >> cmd) {
		if (cmd == "push") {
			int val;
			if (cin >> val) {
				stack.push(val);
				stack.display();
			}
			else {
				return -1;
			}
		}
		else if (cmd == "pop") {
			stack.pop();
			stack.display();
		}
		else {
			return -1;
		}
	}

	return 0;
}