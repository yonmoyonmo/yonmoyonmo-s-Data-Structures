#include <iostream>
#include "Myqueue.h"
#include "Airplane.h"\
#include <ctime>
#include <cstdlib>
//이륙비행기 착륙비행기 100대씩 만듦
//비행기가 큐(하늘)에서 나와서 큐(대기)로 들어갔다가 큐(활주로)로 들어옴
//weight에 따라 활주로를 차지하는 시간이 늘어남
//착륙하는 비행기의 emergency가 10 이하면 어느 활주로든 비어있으면 사용 가능 
void fillin(MyQueue& pool) {
	for (int i = 0; i < 100; i++) {
		Airplane air;
		pool.enqueue(air);
	}
}

int main() {
	srand((unsigned int)time(NULL));
	MyQueue landingairplanes;
	fillin(landingairplanes);
	MyQueue takeoffairplanes;
	fillin(takeoffairplanes);
	
	MyQueue landingwaitingplanes;
	MyQueue takeoffwaitingplanes;

	MyQueue landingone;
	MyQueue landingtwo;
	MyQueue takeoffthree;

	int onestatus =0;
	int twostatus=0;
	int threestatus=0;

	int onelandingcount = 0;
	int twolandingcount = 0;
	int threelandingcount = 0;

	int threetakeoffcount = 0;

	int landingWaitingCnt = 0;
	int takeoffWaitingCnt = 0;
	int i = 0;
	while (i<100) {//100번정도만 해보면 될듯
		system("cls");
		std::cout << "landing waiting: " << landingWaitingCnt << "\n";
		std::cout << "takeoff waiting: " << takeoffWaitingCnt << "\n";
		if (landingWaitingCnt == 0) {
			for (int i = 0; i < 5; i++) {
				std::cout << "waiting for land: " << landingairplanes.peek().getId() << "\n";
				landingwaitingplanes.enqueue(landingairplanes.dequeue());
				landingWaitingCnt++;
			}
		}
		if (takeoffWaitingCnt == 0) {
			for (int i = 0; i < 5; i++) {
				std::cout << "waiting for take off: " << takeoffairplanes.peek().getId() << "\n";
				takeoffwaitingplanes.enqueue(takeoffairplanes.dequeue());
				takeoffWaitingCnt++;
			}
		}
		std::cout<<"_________________________\n";
		system("PAUSE");
		std::cout << "_________________________\n";
		//landing
		if (onestatus == 0) {
			if (landingwaitingplanes.peek().getWeight() > 50) {
				std::cout << "ID: " << landingwaitingplanes.peek().getId() << " is landing on 01\n";
				onestatus = 2;
				landingone.enqueue(landingwaitingplanes.dequeue());
				onelandingcount++;
				landingWaitingCnt--;
			}
			else {
				std::cout << "ID: " << landingwaitingplanes.peek().getId() << " is landing on 01\n";
				onestatus = 1;
				landingone.enqueue(landingwaitingplanes.dequeue());
				onelandingcount++;
				landingWaitingCnt--;
			}
		}
		else if (twostatus == 0) {
			if (landingwaitingplanes.peek().getWeight() > 50) {
				std::cout << "ID: " << landingwaitingplanes.peek().getId() << " is landing on 02\n";
				twostatus = 2;
				landingtwo.enqueue(landingwaitingplanes.dequeue());
				twolandingcount++;
				landingWaitingCnt--;
			}
			else {
				std::cout << "ID: " << landingwaitingplanes.peek().getId() << " is landing on 02\n";
				twostatus = 1;
				landingtwo.enqueue(landingwaitingplanes.dequeue());
				twolandingcount++;
				landingWaitingCnt--;
			}
		}
		else if (landingwaitingplanes.peek().getEmer() < 20) {
			std::cout << "ID: " << landingwaitingplanes.peek().getId() << " is landing on 03\tFuel: "<<landingwaitingplanes.peek().getEmer()<<"\n";
			takeoffthree.enqueue(landingwaitingplanes.dequeue());
			threelandingcount++;
			landingWaitingCnt--;
		}
		else {
			std::cout << "landing queue is full\n\n";
		}
		//take off
		if (threestatus == 0) {
			if (takeoffwaitingplanes.peek().getWeight() > 50) {
				std::cout << "ID: " << takeoffwaitingplanes.peek().getId() << " is taking off at 03\n";
				threestatus = 2;
				takeoffthree.enqueue(takeoffwaitingplanes.dequeue());
				threetakeoffcount++;
				takeoffWaitingCnt--;
			}
			else {
				std::cout << "ID: " << takeoffwaitingplanes.peek().getId() << " is taking off at 03\n";
				threestatus = 1;
				takeoffthree.enqueue(takeoffwaitingplanes.dequeue());
				threetakeoffcount++;
				takeoffWaitingCnt--;
			}
		}
		std::cout << "line one status: " << onestatus << "\n";
		std::cout << "line two status: " << twostatus << "\n";
		std::cout << "line three status: " << threestatus << "\n";
		std::cout << "---------------------------------------\n";
		std::cout << "line one landing: " << onelandingcount << "\n";
		std::cout << "line two landing: " << twolandingcount << "\n";
		std::cout << "line three landing: " << threelandingcount << "\n";
		std::cout << "---------------------------------------\n";
		std::cout << "line three take off: " << threetakeoffcount << "\n";
		std::cout << "_________________________\n";
		system("PAUSE");
		i++;
		if(onestatus>0){ onestatus--; }
		if(twostatus>0){ twostatus--; }
		if(threestatus>0){ threestatus--; }
	}
	std::cout << "game end";

	return 0;
}