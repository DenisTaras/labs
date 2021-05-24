#include <iostream>
#include <fstream>
#include "node.hpp"
#include "students.hpp"
#include <string.h>
#include <sstream>
#include <random>
#include <time.h>
#include <cctype>
#include <vector>
#include <locale>

static std::string FindGrop;
static std::string FindFirst;
static std::string FindMiddle;
static std::string FindLast;
/// for test
void f(int * a){
	*a = *a % 2;
}

bool g(int a){
	return a%2;
}
/// 

bool FindFromGroup(Student elem){
	return elem.Get_Group() == FindGrop;
}

bool FindFromFIO(Student elem){
	return ((elem.Get_First_Name() == FindFirst) &&(elem.Get_Middle_Name() == FindMiddle) &&(elem.Get_Last_Name() == FindLast));
}
bool FindFromF(Student elem){
	return (elem.Get_First_Name() == FindFirst);
}

bool FindFromI(Student elem){
	return (elem.Get_Middle_Name() == FindMiddle);
}

bool FindFromO(Student elem){
	return (elem.Get_Last_Name() == FindLast);
}

void PrintStudent(Student * elem){
	std::cout << elem->Get_First_Name() << " " << elem->Get_Middle_Name() << " " << elem->Get_Last_Name() << " " << elem->Get_Group() << std::endl;
}

void help(){
	std::cout << "find <type> [arg] -for search in database " << std::endl;
	std::cout << "rlist [num] -for print response" << std::endl;
	std::cout << "help -for this massage" << std::endl;
	std::cout << "q - for exit" << std::endl;
}

int main(int argc, char ** argv){
    setlocale(LC_ALL, "Russian");
	if(argc == 1){
		std::vector<Tree<Student, int> *> responsis;
		bool exist = false;
		char Buffer[1024];
		std::ifstream ins("students.txt");
		std::ifstream intch("teacher.txt");
		if(!ins.is_open()){
			std::cerr << "FILE students.txt NO OPEN" << std::endl;
		}
		if(!intch.is_open()){
			std::cerr << "FILE teacher.txt NO OPEN" << std::endl;
		}
		Tree<Student,int> students;
		std::string group, name1, name2, name3;
		int id;
		std::string tmp;
		while(!ins.eof()){
			ins >> group;
			ins >> tmp;
			while(isdigit(tmp[0])){
				ins >> name1 >> name2 >> name3;
				Student typicalstudent(name1, name2, name3, group);
				id = std::stoi(tmp);
				students.insert(id, typicalstudent);
				ins >> tmp;
			}
		}
		while(!exist){
			std::cout << "Enter command" << std::endl;
			std::cin.getline(Buffer,1024);
			std::stringstream stream;
			stream << Buffer;
			std::string funct;
			stream >> funct;
			if(funct == "find"){
				std::string param;
				stream >> param;
				if(param == "group"){
					std::string arg;
					stream >> arg;
					if(arg.length() > 0){
						FindGrop = arg;
						Tree<Student,int> * respons = students.where(FindFromGroup);
						responsis.push_back(respons);
						std::cout << "Respons save" << std::endl;
					}else{
						std::cout << "Error command" << std::endl;
					}
				}else if(param == "fio"){
					std::string arg1;
					std::string arg2;
					std::string arg3;
					stream >> arg1 >> arg2 >> arg3;
					if(arg1.length() > 0 && arg2.length() > 0 && arg3.length() > 0){
						FindFirst = arg1;
						FindMiddle = arg2;
						FindLast = arg3;
						Tree<Student,int> * respons = students.where(FindFromFIO);
						responsis.push_back(respons);
						std::cout << "Respons save" << std::endl;
					} else {
						std::cout << "Error command" << std::endl;
					}
				}else if(param == "i"){
					std::string arg;
					stream >> arg;
					if(arg.length() > 0){
						FindMiddle = arg;
						Tree<Student,int> * respons = students.where(FindFromI);
						responsis.push_back(respons);
						std::cout << "Respons save" << std::endl;
					}else{
						std::cout << "Error command" << std::endl;
					}
				}else if(param == "f"){
					std::string arg;
					stream >> arg;
					if(arg.length() > 0){
						FindFirst = arg;
						Tree<Student,int> * respons = students.where(FindFromF);
						responsis.push_back(respons);
						std::cout << "Respons save" << std::endl;
					}else{
						std::cout << "Error command" << std::endl;
					}
				}else if(param == "o"){
					std::string arg;
					stream >> arg;
					if(arg.length() > 0){
						FindLast = arg;
						Tree<Student,int> * respons = students.where(FindFromO);
						responsis.push_back(respons);
						std::cout << "Respons save" << std::endl;
					}else{
						std::cout << "Error command" << std::endl;
					}
				}else if(param == "id"){
					int id;
					stream >> id;
					if(id > 0){
						node<Student,int> * ptr = students.find(id);
						if(!ptr){
							std::cout << "Not found" << std::endl;
						}else {
							PrintStudent(&(ptr->data));
						}
					} else {
						std::cout << "Error command" << std::endl;
					}
				}else{
					std::cout << "Error command" << std::endl;
				}
			} else if(funct == "q"){
				exist = true;
			} else if(funct == "help"){
				help();
			}else if(funct == "rlist"){
				unsigned int param;
				stream >> param;
				if((param < responsis.size() + 1) && (param > 0)){
					responsis[param - 1]->map(PrintStudent);
				}else {
					std::cout << "Error command" << std::endl;
				}
			}else {
				std::cout << "Error command, command \"help\" for help)" << std::endl;
			}
		}
		ins.close();
		intch.close();
	} else if(argc > 1 && !(strcmp(argv[1],"crash"))){
		Tree<int,int> a;
		int key = 0,value = 0;
		srand(time(nullptr));
		for(int i = 0; i < 100000000; i++){
			key = i;
			value = rand() % 10;
			a.insert(key,value);
		}
		std::cout << a.height_tree() << std::endl;
		try{
			for(int i = 10; i < 50000000; i++){
				a.delete_node(i);
			}
		}catch(int s){
			std::cerr << "Not Found node" << s << std::endl;
		}
		std::cout << a.height_tree() << std::endl;
	}
	return 0;
}
