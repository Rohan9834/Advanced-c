#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Bank
{
	
	
};
class User
{
  private:
	string name;
	int age;
	string account_type;
	int password;
	int Balance;

  public:
	User()
	{
		name = "NO NAME";
		age = 0;
		account_type = "NO TYPE";
		password = 0;
		Balance = 0;
	}
	void getdata()
	{
		cout << "\t\t\tCreate Account";
		cout << "\nNAME :";
		cin >> name;
		cin.ignore();
		cout << "\nAge :";
		cin >> age;
		cin.ignore();
		cout << "\nACCOUNT	TYPE: \n1]Saving \n2]General\n";
		cin >> account_type;
		cout << "\nAdd amount";
		cin >> Balance;
		cin.ignore();
		cout << "\nCREATE	PASSWORD :";
		cin >> password;
	}
	void showdata()
	{
		cout << left << setw(15) << name << setw(10) << age << setw(15) << account_type << setw(10) << Balance << endl;
	}
	int storeuser()
	{
		if (age == 0 || password == 0)
		{
			cout << "Please Enter the user data\n";
			return (0);
		}
		else
		{
			ofstream file1;
			file1.open("user6.dat", ios::app | ios::binary);
			file1.write((char *)this, sizeof(*this));
			file1.close();
			cout << "\nData save successfully\n";
			return (1);
		}
	}
	void showbooks()
	{
		ifstream file;
		file.open("user6.dat", ios::in | ios::binary);
		if (!file)
		{
			cout << "File not open";
		}
		else
		{
			file.read((char *)this, sizeof(*this));
			while (!file.eof())
			{
				showdata();
				file.read((char *)this, sizeof(*this));
			}
			file.close();
		}
	}
	void login()
	{
		string temp_name;
		int temp_pass, count = -1;
		cout << "\t\t\tLogin Now";
		cout << "\nEnter the Name :";
		cin >> temp_name;
		cout << "\nEnter the Password :";
		cin >> temp_pass;
		ifstream file;
		file.open("user6.dat", ios::in | ios::binary);
		if (!file)
		{
			cout << "File not open";
		}
		else
		{
			file.read((char *)this, sizeof(*this));
			while (!file.eof())
			{
				if (temp_pass == password && name == temp_name)
				{
					showdata();
					count = 1;
				}
				else
				{
					count = 0;
					if (name == temp_name && temp_pass != password)
					{
						count = 2;
					}
					else if (name != temp_name && temp_pass == password)
					{
						count = 3;
					}
				}

				file.read((char *)this, sizeof(*this));
			}
			file.close();
		}
		if (count == 0)
		{
			cout << "Enter valid details or Create account";
		}
		else if (count == 2)
		{
			cout << "Invalid pasword";
		}
		else if (count == 3)
		{
			cout << "Invalid username";
		}
	}
};
int main()
{
	User r;
	//r.getdata();
	//r.storeuser();
//	r.showbooks();
	r.login();
}
