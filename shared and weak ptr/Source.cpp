//Задание 5. shared_ptr и weak_ptr
	//Создаем генеалогическое дерево посредством класса human. В классе хранятся:
	//имя - string
	//возможно признак: жив или уже нет...
	//родители - shared_ptr (родители не всегда известны...)
	//дети - контейнер из weak_ptr (чтобы избежать циклических зависимостей)

	//Методы класса human:
	//конструктор - для инициализации имени и признака
	//конструктор копирования, оператор присваивания, move ???
	//статический метод child() - 
	//				должен создать создать и вернуть обертку для родившегося человека
	//				+ сформировать все связи ребенка с родителями и наоборот
	//????????????????????????




	//Ввести возможность распечатать генеалогическое дерево для указанного индивидума
	//История должна с кого-то начинаться => "Жили-были дед да баба, например, Адам и Ева"
	//(то есть на самом деле два деда и две бабы):


	//std::shared_ptr<human> grandM1(new human("Eva"));
	//...

	//у них появились дети - child():

	//а у детей в свою очередь свои дети:

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class human
{
	std::string name;
	bool alive;

	std::pair<std::shared_ptr<human>, std::shared_ptr<human>> Parents;
	std::vector<std::weak_ptr<human>> children;

public:

	human() = default;
	human(const char * myname, const human & mama, const human & papa) :
	name(myname), alive(true), Parents(mama, papa) {};
	
	human(const human & anotherhuman) = delete;
	human & operator=(const human & anotherhuman) = delete;
	human & operator=(human && anotherhuman) = delete;
};

int main() 
{
	human first_human_Eva("Eva", human(), human());
	human first_human_Adam("Adam", human(), human());
}
