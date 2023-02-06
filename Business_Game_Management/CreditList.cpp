#include <iostream>
#include "CreditList.h"


//private:
CreditNode* CreditList::findCreditNode(CreditNode* node, int index) {
	if (node->index == index) return node;
	if (tail_node == node) return nullptr;
	else findCreditNode(node->next_ptr, index);
}
void CreditList::updateIndex(CreditNode* node, int val) {
	node->index = val;
	if (tail_node == node) return;
	else updateIndex(node->next_ptr, val + 1);
}

//public:
CreditList::~CreditList() {
	while (size_list != 0)
	{
		CreditNode* temp = head_node->next_ptr;
		delete head_node;
		head_node = temp;
		size_list--;
	}
}

void CreditList::addNewCredit(int credit_amount) {
	size_list++;

	CreditNode* temp = new CreditNode;
	temp->next_ptr = head_node;
	temp->prev_ptr = tail_node;
	temp->building_site = new Credit(credit_amount);	
	temp->index = size_list - 1;

	if (head_node != nullptr) {
		tail_node->next_ptr = temp;
		head_node->prev_ptr = temp;
		tail_node = temp;
	}
	else head_node = tail_node = temp;
}
void CreditList::deleteCredit(int index)
{
	CreditNode* temp = findCreditNode(head_node, index);
	temp->prev_ptr->next_ptr = temp->next_ptr;
	temp->next_ptr->prev_ptr = temp->prev_ptr;
	size_list--;
	if (head_node == temp) head_node = temp->next_ptr;
	if (tail_node == temp) tail_node = temp->prev_ptr;
	delete temp;
	updateIndex(head_node, 0);
}

int CreditList::getSize() {
	return size_list;
}

int CreditList::getNextCreditIndex(CreditList& application_list, int index) {
	CreditNode* temp = findCreditNode(application_list.head_node, index);
	return (temp->next_ptr)->index;
}

Credit*& CreditList::getCredit(int index) {
	CreditNode* temp = findCreditNode(this->head_node, index);
	if (temp != nullptr) return temp->building_site;
	else std::cout << "Error! index is not in the range\n";
}

Credit*& CreditList::operator[](int index) {
	CreditNode* temp = findCreditNode(this->head_node, index);
	if (temp != nullptr) return temp->building_site;
	else std::cout << "Error! index is not in the range\n";
}

