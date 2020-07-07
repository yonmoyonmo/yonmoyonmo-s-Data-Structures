#include <iostream>
#include "PQH.h"
#include <cstdlib>
#include <ctime>


int main() {
	srand((unsigned int)time(NULL));
	IntPriorityQueue* Q = new IntPriorityQueue();
	for (int i = 0; i < 20; i++) {
		Q->enqueue(static_cast<int>(rand() % 100 + 1));
		std::cout << "No." << i << " is queued | ";
		if (i % 5 == 0 && i!=0) std::cout << "\n";
	}
	printf("\n\n\n_________________________\n");
	int dequeueBasket[20];
	for (int i = 0; i < 20; i++) {
		dequeueBasket[i] = Q->dequeue();
		std::cout << "dequeueing : " << i <<" | ";
		if (i % 5 == 0 && i != 0) std::cout << "\n";
	}
	printf("\n\n\n____________________________\n");
	for (int i = 0; i < 20; i++) {
		std::cout << "basket[" << i << "] : "<<dequeueBasket[i]<<" | ";
		if (i % 5 == 0 && i != 0) std::cout << "\n";
	}
	return 0;
}