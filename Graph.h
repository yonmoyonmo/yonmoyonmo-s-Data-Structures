#pragma once
#include <iostream>

class Vertex {
	std::string name;
	Vertex* Edges; //Edge들을 연결리스트로 유지할 것임
	friend class WonmoGraph;
	Vertex(std::string _name) : name(_name) { Edges = nullptr; }
};

class WonmoGraph {
	Vertex* vertexes[6];
public:
	//그냥 디폴트 생성한다. 딱히 할 것이 없다.
	void nameVertexes() {
		for (int i = 0; i < 6; i++) {
			std::string name;
			std::cout << "enter vertex name [" << i << "] :";
			std::cin >> name;
			vertexes[i] = new Vertex(name);
		}
	}
	void makeEdges() { //그냥 적당히 내맘대로 간선을 이음, 무식하게 이었음, 방향이 있음
		//i i+1, i i+2
		for (int i = 0; i < 6; i++) {
			if (i > 3) { //최대인덱스는 5, 양방향 간선이 생기면 귀찮으니까 한방향씩만 이어준다.
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