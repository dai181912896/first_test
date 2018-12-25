
#include<iostream>
#include<string>
#include"graph.h"
#include<queue>
using namespace std;
void BFS(char v,int reach[128],linkgraph<char>&g);
void DFS(char v, int reach[],linkgraph<char>& g);

int main()
{
	static int dictonary[128];
	memset(dictonary, 0, sizeof(dictonary));
	cout << "多少个顶点" << endl;
	int n;
	cin >> n;
	cout << "初始化中" << endl;
	linkgraph<char> graph1(n);
	string str;
	cout << "给顶点标记字母" << endl;
	cin >> str;
	cin.clear();
	cout << "标记成功" << endl;
	graph1.mark(str);
	string str2;
	char ch1, ch2;
	while (cin>>ch1&&ch1 != 'Y'&&ch1 != 'y'&&cin>>ch2)
	{
		graph1.insertedge(ch1, ch2);
		cout << "输入Y或y结束" << endl;
 		}
	for (auto &c1 : str)
		for (auto &c2 : str)
			cout << c1 << ":"<<c2<<" "<< graph1.existedge(c1, c2) << endl;
	char v = 'a';
	cout << "深度优先搜索 :" << endl;
	DFS(v, dictonary, graph1);
	cout << endl << "广度优先搜素:" << endl;
	memset(dictonary, 0, sizeof(dictonary));
	BFS(v, dictonary, graph1);
	
	


	system("pause");
	return 0;
	
}




void BFS(char v, int reach[128], linkgraph<char>& g)
{
	queue<char> q1;
	q1.push(v);
	while (!q1.empty())
	{
		char w = q1.front();
		q1.pop();
		for (Node<char>* u = g.getthenode(w)->get_elementptr(); u != g.getthenode(w)->get_talinode(); u = u->next)
		{
			if (reach[u->element] == 0)
			{
				cout << u->element << "   ";
				q1.push(u->element);
				reach[u->element] = 1;
			}

		}
		


	}
	memset(reach, 0, sizeof(reach));
}

void DFS(char v,int reach[],linkgraph<char>&g)
{
	reach[v] = 1;
	cout << v << "  ";
	Node<char>* u = g.getthenode(v)->get_elementptr();
	while (u!=g.getthenode(v)->get_talinode())
	{
		char vv = u->element;
		if (reach[u->element] == 0)
		{
			DFS(vv, reach, g);
			
		}
		u = u->next;
	}
	
}