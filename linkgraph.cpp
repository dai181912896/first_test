
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
	cout << "���ٸ�����" << endl;
	int n;
	cin >> n;
	cout << "��ʼ����" << endl;
	linkgraph<char> graph1(n);
	string str;
	cout << "����������ĸ" << endl;
	cin >> str;
	cin.clear();
	cout << "��ǳɹ�" << endl;
	graph1.mark(str);
	string str2;
	char ch1, ch2;
	while (cin>>ch1&&ch1 != 'Y'&&ch1 != 'y'&&cin>>ch2)
	{
		graph1.insertedge(ch1, ch2);
		cout << "����Y��y����" << endl;
 		}
	for (auto &c1 : str)
		for (auto &c2 : str)
			cout << c1 << ":"<<c2<<" "<< graph1.existedge(c1, c2) << endl;
	char v = 'a';
	cout << "����������� :" << endl;
	DFS(v, dictonary, graph1);
	cout << endl << "�����������:" << endl;
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