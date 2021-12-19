#include<iostream>
#include<string>

#define MAX 1000

using namespace std;

//Person
struct Person
{
	string Name;
	int Sex = 0;
	int Age = 0;
	string Phone;
	string Addr;
};

//Address Book
struct AddressBook
{
	struct Person personArray[MAX];
	int Size = 0;
};



//Menu
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****  1.Create  *****" << endl;
	cout << "*****  2.List    *****" << endl;
	cout << "*****  3.Delete  *****" << endl;
	cout << "*****  4.Search  *****" << endl;
	cout << "*****  5.Modify  *****" << endl;
	cout << "*****  6.Clean   *****" << endl;
	cout << "*****  0.Exit    *****" << endl;
	cout << "**********************" << endl;
}

//1.Create
void addPerson(AddressBook* abs)
{
	if (abs->Size == MAX)
	{
		cout << "The address book is full!" << endl;
		return;
	}
	else
	{
		cout << "Please input Name:" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->Size].Name = name;

		cout << "Please input Sex:" << endl;
		cout << "1 --- Male" << endl;
		cout << "2 --- Female" << endl;

		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) 
			{
				abs->personArray[abs->Size].Sex = sex;
				break;
			}
			cout << "Wrong! Please input again:" << endl;
		}
		

		cout << "Please input Age:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 || age <= 200)
			{
				abs->personArray[abs->Size].Age = age;
				break;
			}
			cout << "Wrong! Please input again:" << endl;
		}


		cout << "Please input Phone number:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->Size].Phone = phone;

		cout << "Please input Address:" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->Size].Addr = addr;
	}

	++abs->Size;

	cout << "Create Successully!" << endl;

	system("pause");
	system("cls");
}

//2.List
void showPerson(AddressBook* abs)
{
	if (abs->Size == 0) cout << "Empty!" << endl;
	else
	{
		for (int i = 0; i < abs->Size; ++i)
		{
			cout << "Name:" << abs->personArray[i].Name << "\t";
			cout << "Sex:" << (abs->personArray[i].Sex == 1 ?"Male  ":"Female" ) << "\t";
			cout << "Age:" << abs->personArray[i].Age << "\t";
			cout << "Phone:" << abs->personArray[i].Phone << "\t";
			cout << "Address:" << abs->personArray[i].Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//test Person
int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->Size; ++i)
	{
		if (abs->personArray[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}

//3.Delete
void deletePerson(AddressBook* abs)
{
	cout << "Delete who?" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "Can't find this person!" << endl;
	}
	else
	{
		for (int i = ret; i < abs->Size; ++i)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		--abs->Size;
		cout << "Delete successfully!" << endl;
	}
	system("pause");
	system("cls");
}

//4.Search
void searchPerson(AddressBook* abs)
{
	cout << "Search who?" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "Can't find this person!" << endl;
	}
	else
	{
		cout << "Find this person" << endl;
		cout << "Name:" << abs->personArray[ret].Name << "\t";
		cout << "Sex:" << abs->personArray[ret].Sex << "\t";
		cout << "Age:" << abs->personArray[ret].Age << "\t";
		cout << "Phone number:" << abs->personArray[ret].Phone << "\t";
		cout << "Address:" << abs->personArray[ret].Addr << endl;
	}
	system("pause");
	system("cls");
}

//5.Modify
void modifyPerson(AddressBook* abs)
{
	cout << "Modify who?" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "Can't find this person!" << endl;
	}
	else
	{
		cout << "Please input modified Name:" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].Name = name;

		cout << "Please input modified Sex:" << endl;
		cout << "1 --- Male" << endl;
		cout << "2 --- Female" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].Sex = sex;
				break;
			}
			cout << "Wrong! Please input again:" << endl;
		}


		cout << "Please input modified Age:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 || age <= 200)
			{
				abs->personArray[ret].Age = age;
				break;
			}
			cout << "Wrong! Please input again:" << endl;
		}

		cout << "Please input Phone modified number:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].Phone = phone;

		cout << "Please input Address:" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].Addr = addr;

		cout << "Modify successfully!" << endl;
	}
	system("pause");
	system("cls");
}

//6.Clean
void cleanPerson(AddressBook* abs)
{
	abs->Size = 0;
	cout << "Clean successfully!" << endl;
	system("pause");
	system("cls");
}


int main() {

	//Menu
	showMenu();

	//Initialize
	AddressBook abs;
	abs.Size = 0;

	int select = 0;


	while (true)
	{
		cin >> select;

		switch (select)
		{
		case 1://1.Create
			addPerson(&abs);
			break;
		case 2://2.List
			showPerson(&abs);
			break;
		case 3://3.Delete
			deletePerson(&abs);
			break;
		case 4://4.Search
			searchPerson(&abs);
			break;
		case 5://5.Modify
			modifyPerson(&abs);
			break;
		case 6://6.Clean
			cleanPerson(&abs);
			break;
		case 0://0.Exit
		{
			cout << "Good Bye!" << endl;
			return 0;
		}
			break;
		default:
			cout << "Wrong command!" << endl;
			break;
		}
		showMenu();
	}


	system("pause");
	return 0;
}