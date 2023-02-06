#include "BuildingSiteList.h"

//private:
BuildingSiteNode* BuildingSiteList::findBuildingNode(BuildingSiteNode* node, int index) {
	if (node->index == index) return node;
	if (tail_node == node) return nullptr;
	else findBuildingNode(node->next_ptr, index);
}
void BuildingSiteList::updateIndex(BuildingSiteNode* node, int val) {
	node->index = val;
	if (tail_node == node) return;
	else updateIndex(node->next_ptr, val + 1);
}

//public:
BuildingSiteList::~BuildingSiteList() {
	while (list_size != 0)
	{
		BuildingSiteNode* temp = head_node->next_ptr;
		delete head_node;
		head_node = temp;
		list_size--;
	}
}

void BuildingSiteList::addNewBuildingSite(int object_type) {
	list_size++;

	BuildingSiteNode* temp = new BuildingSiteNode;
	temp->next_ptr = head_node;
	temp->prev_ptr = tail_node;
	temp->building_site = СonstructionСompany::beginConstructionOfPlant(object_type);

	temp->index = list_size - 1;

	if (head_node != nullptr) {
		tail_node->next_ptr = temp;
		head_node->prev_ptr = temp;
		tail_node = temp;
	}
	else head_node = tail_node = temp;
}
void BuildingSiteList::deleteBuildingSite(int index)
{
	BuildingSiteNode* temp = findBuildingNode(head_node, index);
	temp->prev_ptr->next_ptr = temp->next_ptr;
	temp->next_ptr->prev_ptr = temp->prev_ptr;
	list_size--;
	if (head_node == temp) head_node = temp->next_ptr;
	if (tail_node == temp) tail_node = temp->prev_ptr;
	delete temp;
	updateIndex(head_node, 0);
}

int BuildingSiteList::getSize() {
	return list_size;
}
int BuildingSiteList::getNextBuildingSiteIndex(BuildingSiteList& application_list, int index) {
	BuildingSiteNode* temp = findBuildingNode(application_list.head_node, index);
	return (temp->next_ptr)->index;
}

BuildingSite* BuildingSiteList::getTheLastConstructionSiteAdded() const{
	return tail_node->building_site;
}

BuildingSite*& BuildingSiteList::getBuildingSite(int index) {
	BuildingSiteNode* temp = findBuildingNode(this->head_node, index);
	if (temp != nullptr) return temp->building_site;
	else std::cout << "Error! index is not in the range\n";
}
BuildingSite*& BuildingSiteList::operator[](int index) {
	BuildingSiteNode* temp = findBuildingNode(this->head_node, index);
	if (temp != nullptr) return temp->building_site;
	else std::cout << "Error! index is not in the range\n";
}