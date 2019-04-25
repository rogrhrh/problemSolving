// BOJ.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include <iostream>
#include <string>
#include <list>

typedef struct EditorNode
{
	EditorNode *nNext = nullptr;
	EditorNode *nPrev = nullptr;
	char nText;
}NODE;

typedef struct Cursor
{
	EditorNode *cNext = nullptr;
	EditorNode *cPrev = nullptr;
}CURSOR;

using namespace std;

int main()
{
	string sOrigin;
	NODE *startNode = new NODE;
	NODE *tmpNode = startNode;
	
	list<char> arrList;

	cin >> sOrigin;
	for (int i = 0; i < sOrigin.length(); i++)
	{
		arrList.push_back(sOrigin[i]);
		/*if (i == 0) tmpNode->nText = sOrigin[i];
		else
		{
			NODE *nNode = new NODE;
			nNode->nText = sOrigin[i];
			nNode->nPrev = tmpNode;
			tmpNode->nNext = nNode;
			tmpNode = nNode;
		}*/
	}

	int N;
	char cCommand, cNewWord;
	////NODE *curserNode = tmpNode;
	//CURSOR *cursorNode = new CURSOR;
	//cursorNode->cPrev = tmpNode;

	auto iter = arrList.end();
	cin >> N;
	while (N--)
	{
		cin >> cCommand;
		switch (cCommand)
		{
		case 'L':
			/*if (cursorNode->cPrev == nullptr) break;
			cursorNode->cNext = cursorNode->cPrev;
			cursorNode->cPrev = cursorNode->cPrev->nPrev;*/
			if (iter != arrList.begin())
			{
				iter--;
			}
			break;
		case 'D':
			/*if (cursorNode->cNext == nullptr) break;
			cursorNode->cPrev = cursorNode->cNext;
			cursorNode->cNext = cursorNode->cNext->nNext;*/
			if (iter != arrList.end())
			{
				iter++;
			}
			break;
		case 'B':
			/*if (cursorNode->cPrev == nullptr) break;
			if (cursorNode->cPrev == startNode)
			{
				delete(startNode);
				startNode = cursorNode->cNext;
				startNode->nPrev = nullptr;
				cursorNode->cPrev = nullptr;
			}
			else
			{
				tmpNode = cursorNode->cPrev->nPrev;
				delete(cursorNode->cPrev);
				cursorNode->cNext->nPrev = tmpNode;
				tmpNode->nNext = cursorNode->cNext;
				cursorNode->cPrev = tmpNode;
			}*/
			if (iter != arrList.begin())
			{
				auto temp = iter;
				--temp;
				iter = arrList.erase(temp);
			}
			break;
		case 'P':
			cin >> cNewWord;
			iter = arrList.insert(iter, cNewWord);
			iter++;
			/*tmpNode = new NODE;
			tmpNode->nText = cNewWord;
			tmpNode->nNext = cursorNode->cNext;
			if (cursorNode->cPrev != nullptr)
			{
				cursorNode->cPrev->nNext = tmpNode;
				tmpNode->nPrev = cursorNode->cPrev;
			}
			else
			{
				startNode = tmpNode;
			}
			cursorNode->cPrev = tmpNode;*/
			break;
		}
	}

	//cursorNode->cNext = startNode;
	//while (cursorNode->cNext != nullptr)
	//{
	//	cout << cursorNode->cNext->nText;
	//	cursorNode->cPrev = cursorNode->cNext;
	//	cursorNode->cNext = cursorNode->cNext->nNext;
	//	//free(cursorNode->cPrev);
	//}
	/*cout << endl;*/

	for (auto i:arrList)
	{
		cout << i;
	}

	return 0;
}

