#pragma once
#include <iostream>

class Vertex {
	std::string name;
	Vertex* Edges; //Edge���� ���Ḯ��Ʈ�� ������ ����
	friend class WonmoGraph;
	Vertex(std::string _name) : name(_name) { Edges = nullptr; }
};

class WonmoGraph {
	Vertex* vertexes[6];
public:
	//�׳� ����Ʈ �����Ѵ�. ���� �� ���� ����.
	void nameVertexes() {
		for (int i = 0; i < 6; i++) {
			std::string name;
			std::cout << "enter vertex name [" << i << "] :";
			std::cin >> name;
			vertexes[i] = new Vertex(name);
		}
	}
	void makeEdges() { //�׳� ������ ������� ������ ����, �����ϰ� �̾���, ������ ����
		//i i+1, i i+2
		for (int i = 0; i < 6; i++) {
			if (i > 3) { //�ִ��ε����� 5, ����� ������ ����� �������ϱ� �ѹ��⾿�� �̾��ش�.
				break;
			}
			else {
				vertexes[i]->Edges = vertexes[i + 1];
				vertexes[i]->Edges->Edges = vertexes[i + 2];
			}
		}
		//Edges = <0,1>, <0,2>, <1,2>, <1,3>, <2,3>, <2,4>, <3,4>, <3,5> 
	}
	void PrintAll() {
		std::cout << "start -> \n[ " << vertexes[0]->name << " ]->\n";
		recursivePrint(vertexes[0]->Edges);
	}
	void recursivePrint(Vertex* vertex) {
		if (vertex == nullptr) {
			std::cout << "terminal\n";
			return;
		}
		std::cout << "[ " << vertex->name << " ]->\n";
		recursivePrint(vertex->Edges);
	}
	~WonmoGraph() {
		for (int i = 0; i < 6; i++) {
			delete(vertexes[i]);
		}
	}
};