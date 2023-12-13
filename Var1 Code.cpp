#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Vehicle{
protected: //Защищенные данные для хранения марки и модели
	std::string Mark;
	std::string Model;
public: //Конструктор для инициализации марки и модели.
	Vehicle(const std::string& first, const std::string& second): Mark(first), Model(second){};

	virtual void display() const{//Виртуальная функция  которая выводит информацию о транспортном средстве.
		cout<<Mark<<" "<<Model<<endl;
	};

	void setMark(const std::string& d){
		Mark = d;
	};
	void setModel(const std::string& d){
		Model = d;
	};

	virtual ~Vehicle(){};
};


class Car : public Vehicle{
protected:
	int doors; // количество дверей
public:
	Car(const std::string& f, const std::string& s, const int& d): Vehicle(f, s), doors(d){};

	void display() const override{//Виртуальная функция  которая выводит информацию о транспортном средстве.
		cout<<Mark<<" "<<Model<<" "<<doors<<endl;
	}

	~Car(){};
};

class Motorcycle : public Vehicle{
protected:
	std::string TYPE; //тип мотоцикла
public:
	Motorcycle(const std::string& f, const std::string& s, const std::string& d): Vehicle(f,s), TYPE(d){};

	void display() const override{//Виртуальная функция  которая выводит информацию о транспортном средстве.
		cout<<Mark<<" "<<Model<<" "<<TYPE<<endl;
	}
	~Motorcycle(){};
};

void modifyObj(Vehicle* ptr){//функция которая принимает указатель на базовый класс и изменяет его характеристики.
	ptr->setMark("NISSAN");
	ptr->setModel("GT");
}

int main() {
	vector<Vehicle*> vec;
	vec.resize(3);
	vec[0] = new Vehicle("BMW","I3");
	vec[1] = new Car("BMW","I3", 2);
	vec[2] = new Motorcycle("SUZUKI","GT","310 R");

	for(const auto i: vec){//Используя итераторы STL, выведите информацию о каждом транспортном средстве в контейнере.
		i->display();
	}
	for(const auto i: vec){
		modifyObj(i);
		i->display();
		delete i;
	}
	return 0;
}
