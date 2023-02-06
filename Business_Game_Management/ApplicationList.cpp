#include "ApplicationList.h"

//private:
ListBox* ApplicationList::findListBox(ListBox* node, int index) {
	if (node->index == index) return node;
	if (tail_node == node) return nullptr;
	else findListBox(node->next_ptr, index);
}
void ApplicationList::updateIndex(ListBox* node, int val) {
	node->index = val;
	if (tail_node == node) return;
	else updateIndex(node->next_ptr, val + 1);
}

//public:
ApplicationList::~ApplicationList() {
	while (size_list != 0)
	{
		ListBox* temp = head_node->next_ptr;
		delete head_node;
		head_node = temp;
		size_list--;
	}
}

void ApplicationList::addNewApplication(int num_units,int cost_units, Player* player) {
	size_list++;

	ListBox* temp = new ListBox;
	temp->next_ptr = head_node;
	temp->prev_ptr = tail_node;
	temp->application = new Application(num_units, cost_units, player->getName());
	temp->player = player;
	temp->index = size_list - 1;

	if (head_node != nullptr) {
		tail_node->next_ptr = temp;
		head_node->prev_ptr = temp;
		tail_node = temp;
	}
	else head_node = tail_node = temp;
}
void ApplicationList::deleteApplication(int index)
{
	ListBox* temp = findListBox(head_node, index);
	temp->prev_ptr->next_ptr = temp->next_ptr;
	temp->next_ptr->prev_ptr = temp->prev_ptr;
	size_list--;
	if (head_node == temp) head_node = temp->next_ptr;
	if (tail_node == temp) tail_node = temp->prev_ptr;
	delete temp;
	updateIndex(head_node, 0);
}

Player* ApplicationList::getPlayer(int index){
	ListBox* temp = findListBox(head_node, index);
	return temp->player;
}

int ApplicationList::getNumberOfApplictions() {
	return size_list;
}

int ApplicationList::getNextApplicationIndex(ApplicationList& application_list, int index) {
	ListBox* temp = findListBox(application_list.head_node,index);
	return (temp->next_ptr)->index;
}

Application*& ApplicationList::getApplication(int index) {
	ListBox* temp = findListBox(this->head_node, index);
	if (temp != nullptr) return temp->application;
	else std::cout << "Error! index is not in the range\n";
}

Application*& ApplicationList::operator[](int index) {
	ListBox* temp = findListBox(this->head_node, index);
	if (temp != nullptr) return temp->application;
	else std::cout << "Error! index is not in the range\n";
}

void ApplicationList::sortListApplicationsESMs() {
	ListBox* outside_temp = this->head_node;
	ListBox* inside_temp{ nullptr };

	while (outside_temp != this->tail_node)
	{
		inside_temp = this->head_node;

		while (inside_temp != this->tail_node)
		{
			if (inside_temp->application->getPricePerUnit() < inside_temp->next_ptr->application->getPricePerUnit()) {
				Application* temp_app;
				Player* temp_pl;

				temp_pl = inside_temp->player;
				temp_app = inside_temp->application;

				inside_temp->player = inside_temp->next_ptr->player;
				inside_temp->application = inside_temp->next_ptr->application;

				inside_temp->next_ptr->player = temp_pl;
				inside_temp->next_ptr->application = temp_app;
			}
			inside_temp = inside_temp->next_ptr;
		}
		outside_temp = outside_temp->next_ptr;
	}
}
void ApplicationList::sortListApplicationsEGPs() {
	ListBox* outside_temp = this->head_node;
	ListBox* inside_temp{ nullptr };

	while (outside_temp != this->tail_node)
	{
		inside_temp = this->head_node;

		while (inside_temp != this->tail_node)
		{
			if (inside_temp->application->getPricePerUnit() > inside_temp->next_ptr->application->getPricePerUnit()) {
				Application* temp_app;
				Player* temp_pl;

				temp_pl = inside_temp->player;
				temp_app = inside_temp->application;

				inside_temp->player = inside_temp->next_ptr->player;
				inside_temp->application = inside_temp->next_ptr->application;

				inside_temp->next_ptr->player = temp_pl;
				inside_temp->next_ptr->application = temp_app;
			}
			inside_temp = inside_temp->next_ptr;
		}
		outside_temp = outside_temp->next_ptr;
	}
}