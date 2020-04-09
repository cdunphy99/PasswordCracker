#include <string>
using namespace std;
class NodeObject
{
public:
	string getWord();
	int* getIntWord();
	NodeObject(int* wordToStore);
	NodeObject() = default;
	void setWord(int* wordToStore);

private:
	int* word;
	long len;

};

string NodeObject::getWord() {
	string toReturn;
	for (int i = 0; i < this->len; i++) {
		toReturn += word[i];
	}
	return toReturn;
}

int* NodeObject::getIntWord() {
	return word;
}

NodeObject::NodeObject(int* wordToStore) {
	this->word = wordToStore;
	this->len = sizeof(*wordToStore);
}

void NodeObject::setWord(int* wordToStore) {
	this->word = wordToStore;
	this->len = sizeof(*wordToStore);
}