#pragma once
#include "Player.h"

struct ListBox {
	int index{ int() };
	Application* application{ nullptr };
	Player* player{ nullptr };
	ListBox* next_ptr{ nullptr };
	ListBox* prev_ptr{ nullptr };
};

class ApplicationList {

	ListBox* head_node, * tail_node;
	int size_list;

	ListBox* findListBox(ListBox*, int);
	void updateIndex(ListBox*, int);

public:
	ApplicationList() :head_node{ nullptr }, tail_node{ nullptr }, size_list{ int() } {};
	~ApplicationList();

	void addNewApplication(int,int, Player*);
	Application*& getApplication (int index);
	int getNumberOfApplictions();
	Application*& operator[](int index);
	int getNextApplicationIndex(ApplicationList&, int);
	void deleteApplication(int);
	
	void sortListApplicationsESMs();
	void sortListApplicationsEGPs();

	Player* getPlayer(int);
};
