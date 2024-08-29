#include <iostream>


class Camera {
public:
	Camera() {
		std::cout << "Конструктор Camera" << std::endl;
	}
	~Camera() {
		std::cout << "Деструктор Camera" << std::endl;
	}
	void  photo() {
		std::cout << "Сделана фотография" << std::endl;
	}
	virtual void print(){
	std::cout << "Это камера" << std::endl;
}
};

class Phone {
protected:
	std::string phoneNumber;

public:
	Phone() {
		std::cout << "Конструктор Phone" << std::endl;
	}
	~Phone() {
		std::cout << "Деструктор Phone" << std::endl;
	}
	void  call() {
		std::cout << "Звонок" << std::endl;

	}
	virtual void print() {
		std::cout << "Это телефон" << std::endl;
	}
	const std::string& getPhoneNumber() { return phoneNumber;  }
	void setPhoneNumber(std::string number) {
		phoneNumber = number;
	}
};

class Calculator {
public:
	Calculator() {
		std::cout << "Конструктор Calculator" << std::endl;
	}
	~Calculator() {
		std::cout << "Деструктор Calculator" << std::endl;
	}
	int calculate(double num1, double num2) {
		return num1 + num2;
	}
	virtual void print() {
		std::cout << "Это калькулятор" << std::endl;
	}
};

class Smartphone : public Camera, public Phone, public Calculator { // множественное наследование
public:
	Smartphone() {
		std::cout << "Конструктор Smartphone" << std::endl;
	}
	~Smartphone() {
		std::cout << "Деструктор Smartphone" << std::endl;
	}
	void print() override {
		std::cout << "Это смартфон" << std::endl;
	}

};



class Person {
protected:
	std::string name;
public:
	Person() {
		std::cout << "Конструктор Person" << std::endl;
	}
	Person(std::string name) : Person() {
		this->name = name;
	}
	const std::string& getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
};

class Student : virtual public Person {
protected:
	std::string group;
public:
	Student() {
		std::cout << "Конструктор Student" << std::endl;
	}
	Student(std::string name, std::string group) : Student() {
		this->name = name;
		this->group = group;
	}
};

class Employee : virtual public Person { // сотрудники
protected:
	int salary;// зарплата
public:
	Employee() : salary(0) {
		std::cout << "Конструктор Employee" << std::endl;
	}
	Employee(std::string name, int salary) : Employee() {
		this->name = name;
		this->salary = salary;
	}
};

class LabAssistent : public Student, public Employee { // Лаборант наследует характеристики студента 
public:
	LabAssistent() {
		std::cout << "Конструктор LabAssistent" << std::endl;
	}
	LabAssistent(std::string name, std::string group, int salary) : Student(name, group), Employee(name, salary) {
		std::cout << "Конструктор LabAssistent" << std::endl;
	}

	void print() {
		std::cout << "Имя:      " << name << std::endl;
		std::cout << "Группа:   " << group << std::endl;
		std::cout << "Зарплата: " << salary << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	int n;


	// Множественное наследование 
	/*
	Smartphone sp;

	std::cout << std::endl;

	sp.photo();
	sp.call();
	std::cout << sp.calculate(7, 15) << std::endl;
	sp.Calculator::print();


	sp.setPhoneNumber("*8(800)555-35-35");
	std::cout << sp.getPhoneNumber() << std::endl;

	std::cout << std::endl;
*/

	LabAssistent la("Родион", "БВ311", 70'000);
	la.print();

	Person* me = new Employee;
	me->setName("Игорь");
	std::cout << "Меня зовут " << me->getName() << std::endl;


	return 0;
}
