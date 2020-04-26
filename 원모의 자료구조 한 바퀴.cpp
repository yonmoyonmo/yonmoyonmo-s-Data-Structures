#include <iostream>
#include <string>
#include "ListData.h"
#include "ArrayList.h"
#include <fstream>

int enterInt() {
    int a;
    std::cin >> a;
    std::cin.clear();
    return a;
}
std::string enterString() {
    std::string s;
    std::getline(std::cin, s);
    std::cin.clear();
    return s;
}
void makeTextFile(ArrayList list) {
    std::ofstream out("youtlist.txt");
    int count = list.getCount();
    out << "your bucket list\n\n";
    for (int i = 0; i < count; i++) {
        out<<i+1<<". "<<"title: " << list.getTitle(i) << "\t" <<"description: "<< list.getDesc(i)<<"\n";
    }
    out.close();
}

int main()
{
    std::string title="";
    std::string desc="";
    int length = 0;
    std::cout << "\t\t______BUCKET LIST MAKER_____________\n\n" << std::endl;
    std::cout << "\t\t how long?? is your list: ";
    length = enterInt();
    std::cout << "\t\tmaking your list...\n\n";
    ArrayList yourlist(length);
    ListData data(title,desc);
    int index = 0;
    int choice = 0;
    
    while (1) {
       std::cin.clear();
       std::cout << "========================= empty: "<<yourlist.getLength()<<" ============================\n1. add\t2. print single element\t3. print all\n4. update one\t5. delete one\t6. save it in textfile\n7. quit program\n\n\n";
       choice = enterInt();
       switch (choice) {
        case 1:
            if (length <= 0) {
                std::cout << "\t **** yout list is full ****\n\n";
                break;
            }
            system("cls");
            std::cin.clear();
            std::cout << "\t\ttitle: ";
            getchar();
            title = enterString();
            std::cout << "\t\tdescription: ";
            desc = enterString();
            data.title = title;
            data.desc = desc;
            yourlist.insert(data);
            length--;
            break;
        case 2:
            system("cls");
            std::cout << "\t\tindex: ";
            index = enterInt();
            try {
                yourlist.read(index);
            }
            catch (int exception) {
                std::cout << "??" << exception;
            }
            break;
        case 3:
            system("cls");
            try {
                yourlist.printAll();
            }
            catch (int exception) {
                std::cout << "??" << exception;
            }
            break;
        case 4:
            std::cout << "\t\tindex: ";
            index = enterInt();
            try {
                yourlist.update(index);
            }
            catch (int exception) {
                std::cout << "??" << exception;
            }
            break;
        case 5:
            std::cout << "\t\tindex: ";
            index = enterInt();
            try {
                yourlist.del(index);
            }
            catch (int exception) {
                std::cout << "??" << exception;
            }
            length++;
            break;
        case 6:
            makeTextFile(yourlist);
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }

}
