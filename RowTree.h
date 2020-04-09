#include <string>
#include "NodeObject.h"

#define NUMVALUES 26
#define startPoint 97

using namespace std;

class RowTree
{
public:
	RowTree() = default;
	RowTree(int);
	RowTree(RowTree*);
  RowTree* genNextRow(RowTree*);
	string* getPermutations();
	long getLen();
  void setLen(long toSet);
  void setLevel(int toSet);
  void setRowListPointer(NodeObject* toSet);
  int getLevel();
  NodeObject* getRowListPointer();

	~RowTree() = default;

private:

	NodeObject* RowList;
	int level;
	long len;
};

NodeObject* RowTree::getRowListPointer(){
  return this->RowList;
}

int RowTree::getLevel(){
  return this->level;
}

void RowTree::setLen(int toSet){
  this->len = toSet;
}

void RowTree::setRowListPointer(NodeObject* toSet){
  this->RowList = toSet;
}

void RowTree::setLevel(int toSet){
  this->level = toSet;
}

RowTree::RowTree(int startingLetter) {
	this->level = 2;
	this->len = NUMVALUES;
	RowList = new NodeObject[NUMVALUES];
	for (int i = 0; i < (NUMVALUES); i++)
	{
		NodeObject* temp = new NodeObject;
		int* temp2 = new int[2];
		temp2[0] = startingLetter;
		temp2[1] = i + startPoint;
		temp->setWord(temp2);
		RowList[i] = *temp;
	}
}

RowTree::RowTree(RowTree* prevRow) {
	// length of previous * num of possible values
	this->len = prevRow->getLen() * NUMVALUES;
	this->level = prevRow->level + 1;
	this->RowList = new NodeObject[this->len];

	for (int i = 0; i < prevRow->len; i++) {
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			int* temp2 = new int[level];
			int* temp3 = prevRow->RowList[i].getIntWord();
			for (int k = 0; k < level - 1; k++)
			{
				temp2[k] = temp3[k];
			}
			temp2[level - 1] = startPoint + j;
			temp->setWord(temp2);

			this->RowList[(i * NUMVALUES) + j] = *temp;
		}
	}

	//needs to reset something

}

string* RowTree::getPermutations()
{
	string* Permutations = new string[this->len];
	for (int i = 0; i < this->len; i++)
	{
		Permutations[i] = RowList[i].getWord();
	}
	return Permutations;
}

int RowTree::getLen()
{
	return this->len;
}


