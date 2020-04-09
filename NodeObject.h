#include <string>
using namespace std;
class NodeObject
{
public:
	vector<int> getWord();
	vector<int> getIntWord();
	NodeObject(vector<int> wordToStore);
	NodeObject() = default;
	void setWord(vector<int> wordToStore);

private:
	vector<int> word;
	long len;

};

vector<int> NodeObject::getWord() {
	return word;
}

vector<int> NodeObject::getIntWord() {
	return word;
}

NodeObject::NodeObject(vector<int> wordToStore) {
	this->word = wordToStore;
	this->len = wordToStore.size();
}

void NodeObject::setWord(vector<int> wordToStore) {
	this->word = wordToStore;
	this->len = wordToStore.size();
}