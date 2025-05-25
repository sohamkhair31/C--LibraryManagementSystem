#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<fstream>

using namespace std;

typedef struct Stu_info {
	string name;
	string book;
	int id;
}obj; obj info;

typedef class library
{
public:
	void take_data();
	void wel();
	void put_data();
	void all_data();
	void search_id();
	void delete_id();
	void fix_file();

}lib;

void lib::wel()
{
	cout << "\t\tLIBRARY MANAGEMENT \n\n";
	cout << "1-> Add Student\n";
	cout << "2-> show all Borrowers\n";
	cout << "3-> Search by ID \n";
	cout << "4-> Delete ID \n";
	cout << "0-> Exit\n";
	short opt;
	cin >> opt;
	if (opt == 1)
	{
		lib::take_data();
	}
	else if (opt == 2)
	{
		lib::all_data();
	}
	else if (opt == 3)
	{
		lib::search_id();
	}
	else if (opt == 4) { lib::delete_id(); }
	else if (opt == 0)
	{
		exit(0);
	}
}

void lib::take_data()
{
	cout << "ENTER DATA \n";
	cout << "ENTER ID : ";
	cin >> info.id;
	cout << "ENTER BOOK NAME : ";
	cin >> info.book;
	cout << "ENTER NAME : ";
	cin >> info.name;

	lib::put_data();
};

void lib::put_data()
{
	cout << "\nPUTTING DATA IN FILE...\n\n";
	fstream myfile;
	myfile.open("data.txt", ios::app);
	myfile << "\n";
	myfile << info.id << endl;
	myfile << info.book << endl;
	myfile << info.name << endl;
	myfile.close();
}

void lib::all_data()
{
	system("Cls");
	cout << endl << "ALL DATA \n";
	fstream myfile("data.txt");
	string data;
	while (getline(myfile, data))
	{
		cout << data << endl;
	}
	myfile.close();
}

void lib::search_id()
{
	system("Cls");
	cout << "ENTER ID TO FIND : ";
	string id[4];
	cin >> id[0];
	string data;
	fstream i_file("data.txt");
	while (getline(i_file, id[1]))
	{
		if (id[1] == id[0])
		{
			cout << "found\n";
			cout << "ID : " << id[0];

			for (int i = 0; i < 1; i++)
			{
				getline(i_file, id[2]);
				cout << endl << "NAME : " << id
					[2];
				getline(i_file, id[3]);
				cout << endl << "BOOK : " << id[3];
			}
			exit(0);

		}
		else
		{
			cout << "not found\n";
		}
	}
}

void lib::fix_file()
{
	fstream main_f;
	fstream temp_f;
	string main_data, temp_data;

	main_f.open("data.txt", std::ofstream::out | std::ofstream::trunc);
	temp_f.open("temp.txt");
	cout << endl << "WAIT";
	while (getline(temp_f, temp_data))
	{
		main_f << endl << temp_data;
	}temp_f.close(); main_f.close();

	// clearing data of temp file
	remove("temp.txt");

	cout << "\nDONE";
}

void lib::delete_id()
{
	cout << "ENTER ID (DELETING BY ID )   : ";
	string d_id;
	cin >> d_id;

	fstream main_f, temp_f;
	string main_data, temp_data, extra;
	temp_f.open("temp.txt", ios::app);
	main_f.open("data.txt");
	while (getline(main_f, main_data))
	{
		if (main_data == d_id)
		{

			for (int i = 0; i < 3; i++)
			{
				getline(main_f, main_data);
				continue;
			}

		}
		else
		{
			temp_f << endl << main_data;
		}
	}temp_f.close(); main_f.close();
	lib::fix_file();
}

int main()
{
	lib M_lib;
	M_lib.wel();
	_getch();

	return 0;
}