#pragma once
#include "Player.h"
struct Node {
	int index{ int() };
	Player* player{ nullptr };
	Node* next_ptr{ nullptr };
	Node* prev_ptr{ nullptr };
};

class PlayerList {

	Node* head_node, * tail_node;
	int size_list;

	Node* findNode(Node*, int);
	void updateIndex(Node*, int);

public:
	PlayerList():head_node{ nullptr }, tail_node{ nullptr } , size_list{ int() } {};
	~PlayerList();

	void addNewPlayer(std::string);
	void playerRemoval(int);
	int getNumber() const;
	int getNextPlayerIndex(PlayerList&, int);
	Player*& operator[](int index);
};

