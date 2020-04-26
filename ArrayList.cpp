#include "ArrayList.h"

void ArrayList::insert(ListData data)
{
	try {
		arraylist[count] = data;
		count++;
		std::cout << "good\n" << std::endl;
	}
	catch (...) {
		std::cout << "something's wrong" <<std:: endl;
	}
}

void ArrayList::read(int index)
{
	if (index >= count || index < 0) {
		throw index;
	}
	else {
		std::cout <<"your limit of list: "<< listLength << std::endl;
		std::cout << "title: " << arraylist[index].title << "\n" << "desc: " << arraylist[index].desc << std::endl;
	}
}

void ArrayList::printAll(void)
{
	if (count <= 0) {
		throw count;
	}
	else {
		std::cout <<"elements: "<<count <<"\n" <<std::endl;
		for (int i = 0; i < count; i++) {
			std::cout <<"index: "<<i<<"\n"<< "title: " << arraylist[i].title << "\n" << "desc: " << arraylist[i].desc <<"\n=============================================" <<std::endl;
		}
	}
}

void ArrayList::update(int index)
{
	if (index > count || index < 0) {
		throw index;
	}
	else {
		std::string tmp_title;
		std::string tmp_desc;
		std::cout << "\t\tenter new title: ";
		std::cin >> tmp_title;
		std::cout << "\t\tenter new description: ";
		std::cin >> tmp_desc;
		arraylist[index].title = tmp_title;
		arraylist[index].desc = tmp_desc;
		std::cout <<"\tupdated content\nindex: "<<index<< "title: " << arraylist[index].title << "\n" << "desc: " << arraylist[index].desc << std::endl;
	}
}

void ArrayList::del(int index)
{
	if (index > count || index < 0) {
		throw index;
	}
	else if (count - index == 1) {
		count--;
	}
	else {
		//해당 인덱스 다음 인덱스의 내용 복붙
		int howmanytimes = count - 1 - index;
		int start = index;
		for (int i = 0; i < howmanytimes; i++) {
			arraylist[start].title = arraylist[start+1].title;
			arraylist[start].desc = arraylist[start+1].desc;
			start++ ;
		}
		count--;
	}
}

