/***********************************************************************
  AUTHOR:	Joshua Carter.
  WARNING:	Hacky uncommented code inside.

  README:	-	You may look at any of the source code in this project 
				but it should be mostly unnecessary. 
			-	You only really need to	know that the Node class has an 
				x/y position and a vector of Node pointers (no edge 
				class is needed for this example).
			-	The FindPath function is called for you when a new graph
				is generated (by pressing the SPACE key).
			-	You will probably want to create another function to do
				the recursive walking of the graph and return the path
				it took from start to end.
			-	There are a few vector2 style operations in the Math.h
				file that you can use.
			-	Due to the framework used, link-lines cannot be drawn
				behind the nodes ._.
			
************************************************************************/

#include "AIE.h"
#include <cmath>
#include <vector>
#include "Node.h"
#include "NodeMap.h"
#include "Player.h"
#include "Math.h"

NodeMap* nodeMap;
Player* player;

std::vector<Node*>* FindPathRec(Node* current, Node* end, std::vector<Node*>* visitedNodes = new std::vector<Node*>());

//	THIS SECTION TO BE FILLED IN BY THE STUDENT ---------------------------------------------------------

std::vector<Node*>* FindPath()
{
	Node* start					= nodeMap->GetStart();
	Node* end					= nodeMap->GetEnd();

	std::vector<Node*>* path	= new std::vector<Node*>();

	// YOUR CODE GOES HERE
	path = FindPathRec(start, end);

	// YOUR CODE ENDS HERE

	return path;
}

std::vector<Node*>* FindPathRec(Node* current, Node* end, std::vector<Node*>* visitedNodes) {
	std::vector<Node*>* out = nullptr; // create an array pointer to edit/return
	if (current == end) {//check our goal condition
		out = new std::vector<Node*>();
		(*out).emplace_back(current);
		return out;
	}

	if ((*current).links.size() == 0) {//make sure there are links to go to
		return nullptr;
	}

	for (int i = 0; i < (*visitedNodes).size(); i++) {//make sure we haven't alredy been here
		if (current == (*visitedNodes)[i]) {
			return nullptr;
		}
	}

	(*visitedNodes).emplace_back(current);//add the current spot to the do not enter list before going elsewhere

	for (int i = 0; out == nullptr/*if we arn't null then we found the end further down the line*/ && i < (*current).links.size()/*if we hit the end of our list then we need to back up*/; i++) {+
		out = FindPathRec((*current).links[i], end, visitedNodes);//check each one of the links to this node
	}

	if (out != nullptr) {
		(*out).emplace_back(current); // if we're not null after the loop then we've found something and we should add ourselves to the sequence
	} else {
		(*visitedNodes).erase((*visitedNodes).end() - 1); // if we're still null then we need to back up so we need to remove ourselves from the viseted list
	}

	return out;
}
//	-----------------------------------------------------------------------------------------------------
