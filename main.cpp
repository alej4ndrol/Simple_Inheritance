#include <iostream>

using namespace std;


enum SEX{
	u, m, f
};

class Human {
	int age;
	SEX sex;

public:
	Human(int age, SEX sex) {
		this->age = age;
		this->sex = sex;
	}

	int get_age() {
		return age;
	}

	SEX get_sex() {
		return sex;
	}

	void set_age(int age) {
		this->age = age;
	}

	void set_sex(SEX sex) {
		this->sex = sex;
	}
};

class Student : public Human {
	int id;
public:
	Student(int age, SEX sex, int id) :Human(age, sex) {
		this->id = id;
	}
	
	int get_id() {
		return id;
	}

	void set_id(int id) {
		this->id = id;
	}
};

class Bachelor : public Student {
	int exam_score;
public:
	Bachelor(int age, SEX sex, int id, int exam_score) : Student(age, sex, id) {
		this->exam_score = exam_score;
	}

	int get_exam_score() {
		return exam_score;
	}

	void set_exam_score(int exam_score) {
		this->exam_score = exam_score;
	}
};

class Master : public Bachelor {
	int diploma_score;
public:
	Master(int age, SEX sex, int id, int exam_score, int diploma_score) :Bachelor(age, sex, id, exam_score) {
		this->diploma_score = diploma_score;
	}
	int get_diploma_score() {
		return diploma_score;
	}

	void set_diploma_score(int diploma_score) {
		this->diploma_score = diploma_score;
	}
};

class Teacher : public Human {
	bool permission;
public:
	Teacher(int age, SEX sex, bool permission) :Human(age, sex) {
		this->permission = permission;
	}

	bool get_permission() {
		return permission;
	}

	void set_permission(bool permission) {
		this->permission = permission;
	} 
};

class Postgraduate : public Master, public Teacher {
	bool dissertation;
public:
	Postgraduate(int age, SEX sex, int id, int exam_score, int diploma_score, bool permission, bool dissertation) :Master(age, sex, id, exam_score, diploma_score), Teacher(age, sex, permission) {
		this->dissertation = dissertation;
	}

	bool get_dissertation() {
		return dissertation;
	}

	void set_diassertation(bool dissertation) {
		this->dissertation = dissertation;
	}
};

int main(){
	Student student(10, m, 123);
	cout << student.get_age() << endl;

	Postgraduate Artem(28, m, 123, 228, 5, true, true);
	cout << Artem.Master::get_age() << endl;//ïðè ìíîæåñòâåííîì íàñëåäîâàíèè ìû ïîëó÷èëè àëìàç ïðè êîòîðîì èìåþòñÿ îäèíàêîâî îïðåäåëåííûå ìåòîäû ó äâóõ ðîäèòåëåé(ìàãèñòð è ó÷èòåëü) êîòîðûå ÿâëÿþòñÿ ïîòîìêàìè îäíîãî(÷åëîâåê) êëàññà
	return 0;
}
