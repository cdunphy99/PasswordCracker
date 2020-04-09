#include <iostream>
#include
#include "RowTree.h"

using namespace std;

#define NUMVALUES 26
#define startPoint 97

RowTree* genNextRow(RowTree* prevRow) {
	// length of previous * num of possible values
  RowTree newRowTree;
  
	int newLen = prevRow->getLen() * NUMVALUES;
  newRowTree.setLen(newLen);
	newRowTree.setLevel(prevRow->getLevel() + 1);

	NodeObject* newRowList = new NodeObject[newLen];
	for (int i = 0; i < prevRow->getLevel(); i++) {
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			int* temp2 = new int[newRowTree.getLevel()];
			int* temp3 = prevRow->getRowListPointer()[i].getIntWord();
			for (int k = 0; k < newRowTree.getLevel() - 1; k++)
			{
				temp2[k] = temp3[k];
			}
			temp2[newRowTree.getLevel() - 1] = startPoint + j;
			temp->setWord(temp2);

			newRowList[(i * NUMVALUES) + j] = *temp;
		}
	}
  
  newRowTree.setRowListPointer(newRowList);



  return &newRowTree;

	//needs to reset something

}


int main()
{
	int wordLen;
	string wordCheck;

	cout << "Enter the Password: ";
	cin >> wordCheck;
	wordLen = wordCheck.length();




	for (int i = 0; i < NUMVALUES; i++)
	{
		RowTree currRow;
		RowTree start(i + startPoint);
		for (int j = 0; j < wordLen - 2; j++) // 2 have already been generated
		{
			if (j == 0) {
				currRow = RowTree(&start);
			}
			else
			{
				currRow = *genNextRow(&currRow);
			}
		}



		string* permutations = currRow.getPermutations();
		for (int i = 0; i < currRow.getLen(); i++)
		{
			cout << permutations[i];
		}


	}

	return 0;
}