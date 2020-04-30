#pragma once

class Airplane {
	int id;
	int weight;
	int emergency;
public:
	Airplane() {
		id = rand() % 100;
		weight = rand() % 100;
		emergency = rand() % 100;
	}
	Airplane& operator=(Airplane& ref) {
		id = ref.id;
		weight = ref.weight;
		return *this;
	}
	int getId() { return id; }
	int getWeight() { return weight; }
	int getEmer() { return emergency; }
};
