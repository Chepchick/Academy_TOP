#include "PlayerList.h"


//private:
Node* PlayerList::findNode(Node* node, int index) {
	if (node->index == index) return node;
	if (tail_node == node) return nullptr;
	else findNode(node->next_ptr, index);
}
void PlayerList::updateIndex(Node* node, int val) {
	node->index = val;
	if (tail_node == node) return;
	else updateIndex(node->next_ptr, val + 1);
}

//public:
PlayerList::~PlayerList() {
	while (size_list != 0)
	{
		Node* temp = head_node->next_ptr;
		delete head_node;
		head_node = temp;
		size_list--;
	}
}

void PlayerList::addNewPlayer(std::string name) {
	size_list++;

	Node* temp = new Node;
	temp->next_ptr = head_node;
	temp->prev_ptr = tail_node;
	temp->player = new Player(name);
	temp->index = size_list - 1;

	if (head_node != nullptr) {
		tail_node->next_ptr = temp;
		head_node->prev_ptr = temp;
		tail_node = temp;
	}
	else head_node = tail_node = temp;
}
void PlayerList::playerRemoval(int index)
{
	Node* temp = findNode(head_node, index);
	temp->prev_ptr->next_ptr = temp->next_ptr;
	temp->next_ptr->prev_ptr = temp->prev_ptr;
	size_list--;
	if (head_node == temp) head_node = temp->next_ptr;
	if (tail_node == temp) tail_node = temp->prev_ptr;
	delete temp;
	temp = nullptr;
	updateIndex(head_node, 0);
}
int PlayerList::getNumber() const {
	return size_list;
}

int PlayerList::getNextPlayerIndex(PlayerList& player_list, int index) {
	if (player_list.getNumber() == 0) return 0;
	else {
		Node* temp = findNode(player_list.head_node, index);
		return temp->next_ptr->index;
	}
}
Player*& PlayerList::operator[](int index) {
	Node* temp = findNode(head_node, index);
	if (temp != nullptr) return temp->player;
	else std::cout << "Error! index is not in the range\n";
}