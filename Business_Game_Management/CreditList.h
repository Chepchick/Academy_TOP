#pragma once
#include "Ñredit.h"

struct CreditNode {
	int index{ int() };
	Credit* building_site{ nullptr };	
	CreditNode* next_ptr{ nullptr };
	CreditNode* prev_ptr{ nullptr };
};

class CreditList {

	CreditNode *head_node, *tail_node;
	int size_list;

	CreditNode* findCreditNode(CreditNode*, int);
	void updateIndex(CreditNode*, int);

public:
	CreditList() :head_node{ nullptr }, tail_node{ nullptr }, size_list{ int() } {};
	~CreditList();

	void addNewCredit(int);
	void deleteCredit(int);
	
	int getSize();
	int getNextCreditIndex(CreditList&, int);

	Credit*& getCredit(int index);
	Credit*& operator[](int index);
};

