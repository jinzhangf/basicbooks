#include "base.h"

struct ListNode
{
	ListNode() : next(NULL) {}
	ListNode(int val) : value(val), next(NULL) {}

	int value;
	ListNode *next;
};

struct List
{
	List() {}
	List(const vector<int> &vec) {
		ListNode *tail = &dummy;
		for (auto val : vec) {
			ListNode *node = new ListNode(val);
			tail->next = node;
			tail = tail->next;
		}
	}
	void display() {
		ListNode *p = dummy.next;
		while (p) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}
	ListNode dummy; //带头结点的单链表
};

void sort(List &list)
{
	List tmp;
	ListNode *p = list.dummy.next;
	ListNode *q;

	// 拆分
	while (p && p->next) {
		q = p->next;
		p->next = q->next;
		p = p->next;
		q->next = tmp.dummy.next;
		tmp.dummy.next = q;
	}

	// 合并
	p = list.dummy.next;
	q = tmp.dummy.next;
	List ret;
	ListNode *tail = &ret.dummy;
	while (p && q) {
		if (p->value < q->value) {
			tail->next = p;
			p = p->next;
			tail = tail->next;
			tail->next = NULL;
		}
		else if (p->value > q->value) {
			tail->next = q;
			q = q->next;
			tail = tail->next;
			tail->next = NULL;
		}
		else {
			tail->next = p;
			p = p->next;
			tail = tail->next;
			tail->next = q;
			q = q->next;
			tail = tail->next;
			tail->next = NULL;
		}
	}

	ListNode *remain = (p == NULL) ? q : p;
	if (remain) {
		tail->next = remain;
	}

	list = ret;
}

int main()
{
	List list({1,8,3,6,5,5});
	sort(list);
	list.display();
	return 0;
}