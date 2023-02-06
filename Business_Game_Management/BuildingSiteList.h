#pragma once
#include <iostream>
#include "BuildingSite.h"
#include "—onstruction—ompany.h"

struct BuildingSiteNode {
	int index{ int() };
	BuildingSite* building_site{ nullptr };
	BuildingSiteNode* next_ptr{ nullptr };
	BuildingSiteNode* prev_ptr{ nullptr };
};

class BuildingSiteList {

	BuildingSiteNode* head_node, * tail_node;
	int list_size;

	BuildingSiteNode* findBuildingNode(BuildingSiteNode*, int);
	void updateIndex(BuildingSiteNode*, int);

public:
	BuildingSiteList() :head_node{ nullptr }, tail_node{ nullptr }, list_size{ int() } {};
	~BuildingSiteList();

	void addNewBuildingSite(int);
	void deleteBuildingSite(int);

	int getSize();
	int getNextBuildingSiteIndex(BuildingSiteList&, int);

	BuildingSite* getTheLastConstructionSiteAdded() const;

	BuildingSite*& getBuildingSite(int index);
	BuildingSite*& operator[](int index);
};


