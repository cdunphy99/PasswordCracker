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
	vector<vector<int>> getPermutations();
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

void RowTree::setLen(long toSet){
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
	this->RowList = new NodeObject[NUMVALUES];
	for (int i = 0; i < (NUMVALUES); i++)
	{
		NodeObject* temp = new NodeObject;
		vector<int> temp2;
		temp2.push_back(startingLetter);
		temp2.push_back(i + startPoint);
		temp->setWord(temp2);
		RowList[i] = *temp;
	}
}

RowTree::RowTree(RowTree* prevRow) {
  RowTree newRowTree;
  
	int newLen = prevRow->getLen() * NUMVALUES;
  newRowTree.setLen(newLen);
	newRowTree.setLevel(prevRow->getLevel() + 1);

	NodeObject* newRowList = new NodeObject[newLen];
	for (int i = 0; i < prevRow->getLevel(); i++) {
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			vector<int> temp2;
			vector<int> temp3;
      temp3 = prevRow->getRowListPointer()[i].getIntWord();
			for (int k = 0; k < newRowTree.getLevel() - 1; k++)
			{
				temp2.push_back(temp3[k]);
			}
			temp2[newRowTree.getLevel() - 1] = startPoint + j;
			temp->setWord(temp2);

			newRowList[(i * NUMVALUES) + j] = *temp;
		}
	}
  
  newRowTree.setRowListPointer(newRowList);
}

vector<vector<int>> RowTree::getPermutations()
{
	vector<vector<int>> Permutations;
	for (int i = 0; i < this->len; i++)
	{
		Permutations.push_back(RowList[i].getWord());
	}
	return Permutations;
}

long RowTree::getLen()
{
	return this->len;
}