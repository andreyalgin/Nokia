
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

struct WordsCount
{
	size_t length;
	unsigned int count;

	WordsCount(size_t _length) : length(_length), count(1) {}
};


struct List
{
	struct List* next;

	unsigned int payload;

	List(unsigned int _payload) : next(NULL), payload(_payload) {}
};

struct MinMax
{
	unsigned int min;
	unsigned int max;
};

struct TreeNode
{
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;

	unsigned int payload; // <-- I added this field just for algorithm clarification

	TreeNode(int number) : leftChild(NULL), rightChild(NULL), payload(number) {}
};

struct PathNode
{
	struct PathNode* leftChild;
	struct PathNode* rightChild;

	unsigned int maxDepth; // including this node

	struct TreeNode* node;
};

class NokiaSingleton
{
private:

	NokiaSingleton() = default;
	~NokiaSingleton() = default;

	NokiaSingleton(const NokiaSingleton&) = delete;
	NokiaSingleton& operator=(const NokiaSingleton&) = delete;

	void* operator new(std::size_t) = delete;
	void* operator new[](std::size_t) = delete;

	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;

	// Task 5 service function
	void deletePath(struct PathNode*& path)
	{
		if (path == NULL) {
			return;
		}

		deletePath(path->leftChild);
		deletePath(path->rightChild);

		cout << "PathNode deleted: " << path->node->payload << endl;

		delete path;

		path = NULL;
	}

public:

	static NokiaSingleton& getInstance()
	{
		static NokiaSingleton nokiaSingleton;

		return nokiaSingleton;
	}

	// Task 1
	void primeNumbers(unsigned int N, vector<unsigned int>& array)
	{
		vector<unsigned int>::iterator vector_iterator;
		unsigned int sample = 1;
		unsigned int maxDivider;

		array.reserve(N);

		array.push_back(2);
		N--;

		while (N > 0) {
			sample += 2;

			maxDivider = (unsigned int)sqrt(sample);

			for (vector_iterator = array.begin(); vector_iterator != array.end(); ++vector_iterator) {
				if ((*vector_iterator) > maxDivider) {
					array.push_back(sample);
					N--;

					break;
				}

				if (sample % (*vector_iterator) == 0) {
					break;
				}
			}
		}

	}

	// Task 2
	void countWords(string& text, list<WordsCount>& wordsCount_list)
	{
		list<WordsCount>::iterator list_iterator;
		stringstream string_stream(text);
		string word;
		WordsCount* count;

		while (string_stream >> word) {
			word.erase(remove(word.begin(), word.end(), '.'), word.end());
			word.erase(remove(word.begin(), word.end(), ','), word.end());

			for (list_iterator = wordsCount_list.begin(); list_iterator != wordsCount_list.end(); ++list_iterator) {
				if ((*list_iterator).length == word.length()) {
					(*list_iterator).count++;

					break;
				}
			}

			if (list_iterator == wordsCount_list.end()) {
				count = new WordsCount(word.length());

				wordsCount_list.push_back(*count);
			}

			//cout << word << endl;
		}
	}

	// Task 3
	void remainedElements(struct List* list)
	{
		if (list == NULL) {
			return;
		}

		cout << "Element remained: " << list->payload << endl;

		remainedElements(list->next);
	}

	void fillElements(struct List*& list, unsigned int size, unsigned int counter = 1)
	{
		if (size == 0) {
			return;
		}

		if (list == NULL) {
			list = new List(counter);
		}

		counter++;
		size--;

		fillElements(list->next, size, counter);
	}

	// Removes every n-element 
	void removeElements(struct List* list, unsigned int n, struct List* previous = NULL, unsigned int counter = 1)
	{
		struct List* next;

		if ((list == NULL) || (n < 1)) {
			return;
		}

		next = list->next;

		if (counter == n) {
			if (previous != NULL) {
				previous->next = next;
			}

			counter = 0;

			cout << "Element removed: " << list->payload << endl;

			delete(list);

			list = previous;
		}

		counter++;

		removeElements(next, n, list, counter);
	}

	// Task 4
	struct MinMax obtainIntegers(unsigned int integer)
	{
		struct MinMax minMax {};

		while (integer != 0) {
			if ((integer & (1 << 0)) != 0) {
				minMax.min <<= 1;
				minMax.max >>= 1;

				minMax.min |= (1 << 0);
				minMax.max |= (1 << 31);
			}

			integer >>= 1;
		}

		return minMax;
	}

	// Task 5:
	struct PathNode* getLongestPaths(struct TreeNode* node, unsigned int depth = 0, unsigned int maxDepth = 0)
	{
		struct PathNode tmpPath {};
		struct PathNode* path = NULL;

		if (node == NULL) {
			return path;
		}

		depth++;

		tmpPath.maxDepth = depth;
		tmpPath.node = node;

		tmpPath.leftChild = getLongestPaths(node->leftChild, depth, maxDepth);

		if (tmpPath.leftChild != NULL) {
			tmpPath.maxDepth = tmpPath.leftChild->maxDepth;

			tmpPath.rightChild = getLongestPaths(node->rightChild, depth, tmpPath.leftChild->maxDepth);

			if (tmpPath.rightChild != NULL) {
				tmpPath.maxDepth = tmpPath.rightChild->maxDepth;

				if (tmpPath.rightChild->maxDepth > tmpPath.leftChild->maxDepth) {
					deletePath(tmpPath.leftChild);
				}
			}

		}
		else {
			tmpPath.rightChild = getLongestPaths(node->rightChild, depth, maxDepth);

			if (tmpPath.rightChild != NULL) {
				tmpPath.maxDepth = tmpPath.rightChild->maxDepth;
			}
		}

		if (tmpPath.maxDepth >= maxDepth) {
			path = new PathNode(tmpPath);

			cout << "PathNode created: " << path->node->payload << endl;
		}

		return path;
	}
};
