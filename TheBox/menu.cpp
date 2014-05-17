#include "menu.h"

Date currentDate()
{
	Date d1;
	string wd;
	int d, h, m;
	srand (time(NULL));
    d = rand() % 7 + 1;
	h = rand() % 24;
	m = rand() % 60;
	wd = d1.getStr(d);
	d1.setDate(wd, h, m);
	return d1;
}

Box box = Box(LoadPassword(), currentDate());

void loadConfigs();

void welcome()
{
	cout << endl << endl << endl << endl;
	cout <<  " __        __   _                          " << endl;
	cout <<  " \\ \\      / /__| | ___ ___  _ __ ___   ___ " << endl;
	cout <<  "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
	cout <<  "   \\ V  V /  __/ | (_| (_) | | | | | |  __/" << endl;
	cout <<  "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl << endl << endl;
}

void goodbye()
{
	system("CLS");
	cout << endl << endl << endl << endl;
	cout << "   ____                 _ _                " << endl;
	cout << "  / ___| ___   ___   __| | |__  _   _  ___ " << endl;
	cout << " | |  _ / _ \\ / _ \\ / _` | '_ \\| | | |/ _ \\" << endl;
	cout << " | |_| | (_) | (_) | (_| | |_) | |_| |  __/" << endl;
	cout << "  \\____|\\___/ \\___/ \\__,_|_.__/ \\__, |\\___|" << endl;
	cout << "                                |___/      " << endl << endl << endl;
	exit(0);
}

void movieclub_menu()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	
	cout << "1. Rent a movie" << endl;
	cout << "2. List of movies never seen" << endl;
	cout << "3. List of movies previously seen" << endl;
	cout << "4. Money spent in watching movies" << endl;
	cout << "5. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
			
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			movieclub_menu();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1)
		RentMovie();
	if (yourchoice == 2)
		ListNeverSeen();
	if (yourchoice == 3)
		ListPreviouslySeen();
	if (yourchoice == 4)
		MoneySpent();
	if (yourchoice == 5)
		start_menu();
}

void tv_menu()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  _____    _            _     _             " << endl;
	cout << " |_   _|__| | _____   _(_)___(_) ___  _ __  " << endl;
	cout << "   | |/ _ \\ |/ _ \\ \\ / / / __| |/ _ \\| '_ \\ " << endl;
	cout << "   | |  __/ |  __/\\ V /| \\__ \\ | (_) | | | |" << endl;
	cout << "   |_|\\___|_|\\___| \\_/ |_|___/_|\\___/|_| |_|" << endl << endl << endl;
	cout << "1. List the programs by day" << endl;
	cout << "2. List the programs by channel" << endl;
	cout << "3. List the programs by type of program" << endl;
	cout << "4. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			movieclub_menu();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1)
		ListbyDay();
	if (yourchoice == 2)
		ListbyChannel();
	if (yourchoice == 3)
		ListbyType();
	if (yourchoice == 4)
		start_menu();
}


void advanced_menu1()
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl << endl;
	cout << "Please insert your password: ";
	string pass = "";
	char ch;
	ch = _getch();
	while (ch != 13) //character 13 is enter
	{
		if (ch == 8)
		{
			advanced_menu1();
		}
		else
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
	}
	if (pass == box.GetPassword())
	{
		advanced_menu2();
	}
	else
	{
		cout << endl << endl << "Incorrect password" << endl;
		Sleep(1000);
		start_menu();
	}
}

void advanced_menu2()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl << endl;
	cout << "You are in a privileged user menu, please don't change anything without the" << endl;
	cout << "certainty. The box allows for CRUD operations (Create, Read, Update, Delete)." << endl << endl;
	cout << "1. Password" << endl;
	cout << "2. Channels" << endl;
	cout << "3. Programs" << endl;
	cout << "4. Movies" << endl;
	cout << "5. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');

			}
			cout << endl << "Invalid option" << endl << endl;
			Sleep(1000);
			advanced_menu2();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_password1();
	if (yourchoice == 2)
		advanced_menu_channels();
	if (yourchoice == 3)
		advanced_menu_programs();
	if (yourchoice == 4)
		advanced_menu_movies();
	if (yourchoice == 5)
		start_menu();
}

void advanced_menu_password1()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Password advanced options" << endl << endl;
	cout << "1. Change password" << endl;
	cout << "2. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 2)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');

			}
			cout << endl << "Invalid option" << endl << endl;
			Sleep(1000);
			advanced_menu_password1();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_password2();
	if (yourchoice == 2)
		advanced_menu2();
}

void advanced_menu_password2()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Change Password" << endl << endl;
	cout << "Are you sure you want to change the password?\n" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');

			}
			cout << endl << "Invalid option" << endl << endl;
			Sleep(1000);
			advanced_menu_password2();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_password3();
	if (yourchoice == 2)
		advanced_menu2();
}

void advanced_menu_password3()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Change Password" << endl << endl << endl;
	cout << "Enter current password: ";
	string pass = "";
	string newpass = "";
	char ch1, ch2;
	ch1 = _getch();
	while (ch1 != 13) //character 13 is enter
	{
		if (ch1 == 8)
		{
			advanced_menu_password3();
		}
		else
		{
			pass.push_back(ch1);
			cout << '*';
			ch1 = _getch();
		}
	}
	if (pass == box.GetPassword())
	{
		cout << "\nEnter new password: ";
		ch2 = _getch();
		while (ch2 != 13) //character 13 is enter
		{
			if (ch2 == 8)
			{
				advanced_menu_password3(); // Corrigir esta parte, poder apagar pass passo a passo
			}
			else
			{
				newpass.push_back(ch2);
				cout << '*';
				ch2 = _getch();
			}
		}
		cout << endl << endl << endl << "Password successfully changed";
		box.changePassword(newpass);
		Sleep(1000);
		//advanced_menu_password1();
		start_menu();
	}
	else
	{
		cout << endl << endl << "Incorrect password" << endl;
		Sleep(1000);
		start_menu();
		//advanced_menu_password1(); 
	}
}

void advanced_menu_channels()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Channels advanced options" << endl <<  endl;
	cout << "1. Create" << endl;
	cout << "2. Read" << endl;
	cout << "3. Update" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			advanced_menu_channels();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1);
		//Completar
	if (yourchoice == 2);
		//Completar
	if (yourchoice == 3);
		//Completar
	if (yourchoice == 4);
		//Completar
	if (yourchoice == 5)
		advanced_menu2();
}

void advanced_menu_programs()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Programs advanced options" << endl <<  endl;
	cout << "1. Create" << endl;
	cout << "2. Read" << endl;
	cout << "3. Update" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			advanced_menu_programs();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1);
		//Completar
	if (yourchoice == 2);
		//Completar
	if (yourchoice == 3);
		//Completar
	if (yourchoice == 4);
		//Completar
	if (yourchoice == 5)
		advanced_menu2();
}

void advanced_menu_movies()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Movies advanced options" << endl <<  endl;
	cout << "1. Create" << endl;
	cout << "2. Read" << endl;
	cout << "3. Update" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 5)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			advanced_menu_movies();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1);
		//Completar
	if (yourchoice == 2);
		//Completar
	if (yourchoice == 3);
		//Completar
	if (yourchoice == 4);
		//Completar
	if (yourchoice == 5)
		advanced_menu2();
}


void endprogram_menu()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  _____           _   ____                                      " << endl;
	cout << " | ____|_ __   __| | |  _ \\ _ __ ___   __ _ _ __ __ _ _ __ ___  " << endl;
	cout << " |  _| | '_ \\ / _` | | |_) | '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ " << endl;
	cout << " | |___| | | | (_| | |  __/| | | (_) | (_| | | | (_| | | | | | |" << endl;
	cout << " |_____|_| |_|\\__,_| |_|   |_|  \\___/\\ \__, |_|  \\__,_|_| |_| |_|" << endl;
	cout << "                                      |___/                     " << endl << endl;
	cout << "Are you sure that you want to exit the program?" << endl << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 2)
			valid = true;
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			endprogram_menu();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1)
		goodbye();
	if (yourchoice == 2)
		start_menu();
}


void start_menu()
{
	
	system("CLS");
	int yourchoice;
	bool valid = false;
	cout << "  ____  _             _     __  __                  " << endl;
	cout << " / ___|| |_ __ _ _ __| |_  |  \\/  | ___ _ __  _   _ " << endl;
	cout << " \\___ \\| __/ _` | '__| __| | |\\/| |/ _ \\ '_ \\| | | |" << endl;
	cout << "  ___) | || (_| | |  | |_  | |  | |  __/ | | | |_| |" << endl;
	cout << " |____/ \\__\\__,_|_|   \\__| |_|  |_|\\___|_| |_|\\__,_|" << endl << '\t' << '\t' << '\t' << '\t';// << endl << endl;
	box.GetCurrentDate(box).show();
	cout << endl << endl;
	cout << "1. Movieclube" << endl;
	cout << "2. Television" << endl;
	cout << "3. Advanced options" << endl;
	cout << "4. Exit" << endl << endl;
	
	
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 4)
		{
			valid = true;
		}
		
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n'); 
				
			}
			cout << endl << "Invalid option" << endl << endl; 
			Sleep(1000);
			start_menu();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1)
		movieclub_menu();
	if (yourchoice == 2)
		tv_menu();
	if (yourchoice == 3)
		advanced_menu1();
	if (yourchoice == 4)
		endprogram_menu();
	
}


//Estas funções devem ser uns menus que irão aparecer ainda antes de apresentar os resultados finais que estão definidos nas classes
void ListbyDay()
{
	//Exemplo para compilar
}

void ListbyChannel()
{
	//Exemplo para compilar
}

void ListbyType()
{
	//Exemplo para compilar
}

void EditChannels()
{
	//Exemplo para compilar
}

void EditPrograms()
{
	//Exemplo para compilar
}

void EditMovies()
{
	//Exemplo para compilar
}

void EditPass()
{
	//Exemplo para compilar
}