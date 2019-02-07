//������� 5. shared_ptr � weak_ptr
	//������� ��������������� ������ ����������� ������ human. � ������ ��������:
	//��� - string
	//�������� �������: ��� ��� ��� ���...
	//�������� - shared_ptr (�������� �� ������ ��������...)
	//���� - ��������� �� weak_ptr (����� �������� ����������� ������������)

	//������ ������ human:
	//����������� - ��� ������������� ����� � ��������
	//����������� �����������, �������� ������������, move ???
	//����������� ����� child() - 
	//				������ ������� ������� � ������� ������� ��� ����������� ��������
	//				+ ������������ ��� ����� ������� � ���������� � ��������
	//????????????????????????




	//������ ����������� ����������� ��������������� ������ ��� ���������� ����������
	//������� ������ � ����-�� ���������� => "����-���� ��� �� ����, ��������, ���� � ���"
	//(�� ���� �� ����� ���� ��� ���� � ��� ����):


	//std::shared_ptr<human> grandM1(new human("Eva"));
	//...

	//� ��� ��������� ���� - child():

	//� � ����� � ���� ������� ���� ����:

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
