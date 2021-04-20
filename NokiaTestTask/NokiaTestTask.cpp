// NokiaTestTask.cpp: определяет точку входа для приложения.
//

#include "NokiaTestTask.h"
#include "NokiaSingleton.h"

using namespace std;

void Task1()
{
	NokiaSingleton& nokiaSingleton = NokiaSingleton::getInstance();
	vector<unsigned int> prime_numbers;
	vector<unsigned int>::iterator vector_iterator;

	cout << "Task 1" << endl;
	cout << "Prime numbers: ";

	nokiaSingleton.primeNumbers(15, prime_numbers);

	for (vector_iterator = prime_numbers.begin(); vector_iterator != prime_numbers.end(); ++vector_iterator) {
		cout << (*vector_iterator) << " ";
	}

	cout << endl << endl;
}

void Task2()
{
	NokiaSingleton& nokiaSingleton = NokiaSingleton::getInstance();
	string myDog = "I have got a dog. Her name is Pat. She can do this. She can do that. Look at my dog. Tricks she can do. I love my dog. She loves me, too.";
	list<WordsCount> wordsCount_list;
	list<WordsCount>::iterator list_iterator;

	cout << "Task 2" << endl;

	nokiaSingleton.countWords(myDog, wordsCount_list);

	for (list_iterator = wordsCount_list.begin(); list_iterator != wordsCount_list.end(); ++list_iterator) {
		cout << "Length " << (*list_iterator).length << ": " << (*list_iterator).count << endl;
	}

	cout << endl;
}

void Task3()
{
	NokiaSingleton& nokiaSingleton = NokiaSingleton::getInstance();
	struct List* root = NULL;

	cout << "Task 3" << endl;

	nokiaSingleton.fillElements(root, 11);

	nokiaSingleton.remainedElements(root);

	cout << endl;

	nokiaSingleton.removeElements(root, 5);

	cout << endl;

	nokiaSingleton.remainedElements(root);

	cout << endl;
}

void Task4()
{
	NokiaSingleton& nokiaSingleton = NokiaSingleton::getInstance();
	unsigned int integer;
	struct MinMax minMax;

	integer = (1 << 24)|(1 << 13)|(1 << 4);

	minMax = nokiaSingleton.obtainIntegers(integer);

	cout << "Task 4" << endl;
	cout << "Minimum integer: " << minMax.min << " Maximum integer:  " << minMax.max << endl << endl;
}


void Task5()
{
	NokiaSingleton& nokiaSingleton = NokiaSingleton::getInstance();

	struct TreeNode* treeRoot;
	struct PathNode* longestPaths;

	treeRoot = new TreeNode(101);

	treeRoot->leftChild = new TreeNode(201);
	treeRoot->rightChild = new TreeNode(202);

	treeRoot->leftChild->leftChild = new TreeNode(301);
	treeRoot->leftChild->rightChild = new TreeNode(302);
	treeRoot->rightChild->rightChild = new TreeNode(304);

	treeRoot->leftChild->leftChild->rightChild = new TreeNode(402);
	treeRoot->leftChild->rightChild->leftChild = new TreeNode(403);
	treeRoot->rightChild->rightChild->leftChild = new TreeNode(407);
	treeRoot->rightChild->rightChild->rightChild = new TreeNode(408);

	treeRoot->rightChild->rightChild->leftChild->rightChild = new TreeNode(514);
	treeRoot->leftChild->rightChild->leftChild->rightChild = new TreeNode(506);

	cout << "Task 5" << endl;

	longestPaths = nokiaSingleton.getLongestPaths(treeRoot);

	cout << endl << "Depth of the tree: " << longestPaths->maxDepth << endl;
}

int main()
{
	cout << "Hello CMake" << endl << endl;

	Task1();
	Task2();
	Task3();
	Task4();
	Task5();

	cin.get();

	return 0;
}
