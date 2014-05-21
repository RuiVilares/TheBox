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

//void loadConfigs();

void welcome()
{
	cout << endl << endl << endl << endl;
	cout <<  " __        __   _                          " << endl;
	cout <<  " \\ \\      / /__| | ___ ___  _ __ ___   ___ " << endl;
	cout <<  "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
	cout <<  "   \\ V  V /  __/ | (_| (_) | | | | | |  __/" << endl;
	cout <<  "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl << endl << endl;

	loadConfigs(box);
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
	box.save_movies();
	box.saveInfo();
	exit(0);
}

void movieclub_menu()
{
	bool valid = false;
	int yourchoice;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	
	cout << "1. Rent a movie" << endl;
	cout << "2. Number of times a movie has been watched" << endl;
	cout << "3. List of movies never seen" << endl;
	cout << "4. List of movies previously seen" << endl;
	cout << "5. Money spent in watching movies" << endl;
	cout << "6. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 6)
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
		movieclub_menu_RentMovie();
	if (yourchoice == 2)
		movieclub_menu_timesWatched();
	if (yourchoice == 3)
		movieclub_menu_neverSeen();
	if (yourchoice == 4)
		movieclub_menu_seen();
	if (yourchoice == 5)
		movieclub_menu_totalCost();
	if (yourchoice == 6)
		start_menu();
}

void movieclub_menu_RentMovie()
{
	int yourchoice;
	bool valid = false;
	string name;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	cout << "\t \t Rent a movie" << endl << endl << endl << endl;
	cout << "Insert a movie's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;
	box.rentMovies(name);
	cout << "1. Refresh" << endl;
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
			movieclub_menu_timesWatched();
		}
	} while (!valid);

	if (yourchoice == 1)
		movieclub_menu_RentMovie();
	if (yourchoice == 2)
		movieclub_menu();
}

void movieclub_menu_timesWatched()
{
	int yourchoice;
	bool valid = false;
	string name;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	cout << "\t \t Number of times a movie has been watched" << endl << endl << endl << endl;
	cout << "Insert a movie's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;
	if (box.Whatched(name))
	{
		cout << endl;
		box.show_timesWhatched(name);
		cout << endl << endl;
	}
	else
	{
		if (box.exist_in_movieClub(name))
			cout <<  "The movie \"" << name << "\"" << " exists in the Movieclub, but it was never seen." << endl << endl << endl;
		else
			cout << "The movie \"" << name << "\"" << " doesn't exist." << endl << endl << endl;
			
	}
	cout << "1. Refresh" << endl;
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
			movieclub_menu_timesWatched();
		}
	} while (!valid);

	if (yourchoice == 1)
		movieclub_menu_timesWatched();
	if (yourchoice == 2)
		movieclub_menu();
}

void movieclub_menu_neverSeen()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	cout << "\t \t List of movies never seen" << endl << endl;
	box.show_movies_movieClub();
	cout << "1. Rent a movie" << endl;
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
			movieclub_menu_neverSeen();
		}
	} while (!valid);

	if (yourchoice == 1)
		movieclub_menu_RentMovie();
	if (yourchoice == 2)
		movieclub_menu();

}

void movieclub_menu_seen()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	cout << "\t \t List of movies previously seen" << endl << endl;
	box.show_movies_seen();
	cout << "1. Rent a movie" << endl;
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
			movieclub_menu_seen();
		}
	} while (!valid);

	if (yourchoice == 1)
		movieclub_menu_RentMovie();
	if (yourchoice == 2)
		movieclub_menu();

}

void movieclub_menu_totalCost()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  __  __            _             _       _     " << endl;
	cout << " |  \\/  | _____   _(_) ___    ___| |_   _| |__  " << endl;
	cout << " | |\\/| |/ _ \\ \\ / / |/ _ \\  / __| | | | | '_ \\ " << endl;
	cout << " | |  | | (_) \\ V /| |  __/ | (__| | |_| | |_) |" << endl;
	cout << " |_|  |_|\\___/ \\_/ |_|\\___|  \\___|_|\\__,_|_.__/ " << endl << endl << endl;
	cout << "\t \t Money spent in watching movies" << endl << endl << endl << endl;
	cout << "You already spent: EUR " << box.moneySpent() << endl << endl << endl << endl << endl;
	cout << "1. Start Menu" << endl;
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
			movieclub_menu_totalCost();
		}
	} while (!valid);

	if (yourchoice == 1)
		start_menu();
	if (yourchoice == 2)
		movieclub_menu();

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
	cout << "1. Set a program to be recorded" << endl;
	cout << "2. Remove a program from the to be recorded's list" << endl;
	cout << "3. Remove a program from the recorded's list" << endl;
	cout << "4. List the programs to be recorded" << endl;
	cout << "5. List the programs already recorded" << endl;
	cout << "6. List the programs by day" << endl;
	cout << "7. List the programs by channel" << endl;
	cout << "8. List the programs by type of program" << endl;
	cout << "9. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 9)
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
			tv_menu();
		}
	} 
	while (!valid);
	
	if (yourchoice == 1)
		tv_menu_setprogram();
	if (yourchoice == 2)
		tv_menu_removeToBeRecorded();
	if (yourchoice == 3)
		tv_menu_removeRecorded();
	if (yourchoice == 4)
		start_menu();
	if (yourchoice == 5)
		start_menu();
	if (yourchoice == 6)
		start_menu();
	if (yourchoice == 7)
		start_menu();
	if (yourchoice == 8)
		start_menu();
	if (yourchoice == 9)
		start_menu();
}

void tv_menu_setprogram()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  _____    _            _     _             " << endl;
	cout << " |_   _|__| | _____   _(_)___(_) ___  _ __  " << endl;
	cout << "   | |/ _ \\ |/ _ \\ \\ / / / __| |/ _ \\| '_ \\ " << endl;
	cout << "   | |  __/ |  __/\\ V /| \\__ \\ | (_) | | | |" << endl;
	cout << "   |_|\\___|_|\\___| \\_/ |_|___/_|\\___/|_| |_|" << endl << endl << endl;
	cout << "\t \t Set a program to be recorded" << endl << endl;
	box.SetProgramRecorded();
	cout << "1. Refresh" << endl;
	cout << "2. Return"  << endl << endl;
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
			tv_menu();
		}
	} while (!valid);

	if (yourchoice == 1)
		tv_menu_setprogram();
	if (yourchoice == 2)
		tv_menu();
}

void tv_menu_removeToBeRecorded()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  _____    _            _     _             " << endl;
	cout << " |_   _|__| | _____   _(_)___(_) ___  _ __  " << endl;
	cout << "   | |/ _ \\ |/ _ \\ \\ / / / __| |/ _ \\| '_ \\ " << endl;
	cout << "   | |  __/ |  __/\\ V /| \\__ \\ | (_) | | | |" << endl;
	cout << "   |_|\\___|_|\\___| \\_/ |_|___/_|\\___/|_| |_|" << endl << endl << endl;
	cout << "\t \t Remove a program from the to be recorded's list" << endl << endl;
	box.RemoveProgramToBeRecorded();
	cout << "1. Refresh" << endl;
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
			tv_menu();
		}
	} while (!valid);

	if (yourchoice == 1)
		tv_menu_removeToBeRecorded();
	if (yourchoice == 2)
		tv_menu();
}

void tv_menu_removeRecorded()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "  _____    _            _     _             " << endl;
	cout << " |_   _|__| | _____   _(_)___(_) ___  _ __  " << endl;
	cout << "   | |/ _ \\ |/ _ \\ \\ / / / __| |/ _ \\| '_ \\ " << endl;
	cout << "   | |  __/ |  __/\\ V /| \\__ \\ | (_) | | | |" << endl;
	cout << "   |_|\\___|_|\\___| \\_/ |_|___/_|\\___/|_| |_|" << endl << endl << endl;
	cout << "\t \t Remove a program from the recorded's list" << endl << endl;
	box.RemoveProgramRecorded();
	cout << "1. Refresh" << endl;
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
			tv_menu();
		}
	} while (!valid);

	if (yourchoice == 1)
		tv_menu_removeRecorded();
	if (yourchoice == 2)
		tv_menu();
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
	cout << "2. Update" << endl;
	cout << "3. Delete" << endl;
	cout << "4. Return" << endl << endl;
	do
	{
		cout << "Choose one of those options: ";
		cin >> yourchoice;
		if (yourchoice >= 1 && yourchoice <= 4)
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
	
	if (yourchoice == 1)
		advanced_menu_movies_create();
	if (yourchoice == 2)
		advanced_menu_movies_update1();
	if (yourchoice == 3)
		advanced_menu_movies_remove();
	if (yourchoice == 4)
		advanced_menu2();
	
		
}

void advanced_menu_movies_create()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Create a movie" << endl << endl;
	box.createMovie();
	cout << "1. Refresh" << endl;
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
			advanced_menu_movies();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_movies_create();
	if (yourchoice == 2)
		advanced_menu_movies();

}

void advanced_menu_movies_update1()
{
	string name;
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a movie" << endl << endl;
	cout << "Insert a movie's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;
	if (!box.exist_in_movieClub(name) && !box.Whatched(name))
	{
		cout << "The movie \"" << name << "\" doesn't exist." << endl << endl << endl;
		cout << "1. Refresh" << endl;
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
				advanced_menu_movies();
			}
		} while (!valid);

		if (yourchoice == 1)
			advanced_menu_movies_update1();
		if (yourchoice == 2)
			advanced_menu_movies();
	}
	else
	{
		if (box.exist_in_movieClub(name))
		{
			cout << "The movie \"" << name << "\" exists in the Movieclub." << endl << endl << endl;
			cout << "1. Set title of the movie" << endl;
			cout << "2. Set cost of its rental" << endl;
			cout << "3. Return" << endl << endl;
			do
			{
				cout << "Choose one of those options: ";
				cin >> yourchoice;
				if (yourchoice >= 1 && yourchoice <= 3)
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
			} while (!valid);

			if (yourchoice == 1)
				box.updateMovie(1, name);
			if (yourchoice == 2)
				box.updateMovie(2, name);
			if (yourchoice == 3)
				advanced_menu_movies();
		}
		else
		{
			cout << "The movie \"" << name << "\" exists in the list of movies previously seen." << endl << endl << endl;
			cout << "1. Set title of the movie" << endl;
			cout << "2. Set cost of its rental" << endl;
			cout << "3. Set number of times the movie was rented" << endl;
			cout << "4. Return" << endl << endl;
			do
			{
				cout << "Choose one of those options: ";
				cin >> yourchoice;
				if (yourchoice >= 1 && yourchoice <= 4)
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
			} while (!valid);

			if (yourchoice == 1)
				box.updateMovie(3, name);
			if (yourchoice == 2)
				box.updateMovie(4, name);
			if (yourchoice == 3)
				box.updateMovie(5, name);
			if (yourchoice == 4)
				advanced_menu_movies();
		}
		
	}
	cout << "1. Refresh" << endl;
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
			advanced_menu_movies();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_movies_update1();
	if (yourchoice == 2)
		advanced_menu_movies();

}

void advanced_menu_movies_remove()
{
	int yourchoice;
	bool valid = false;
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Remove a movie" << endl << endl;
	box.removeMovie();
	cout << "1. Refresh" << endl;
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
			advanced_menu_movies();
		}
	} while (!valid);

	if (yourchoice == 1)
		advanced_menu_movies_remove();
	if (yourchoice == 2)
		advanced_menu_movies();

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
	box.GetCurrentDate().show();
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



//FUNÇÃO LOAD DO PROGRAMA

void loadConfigs(Box &box){
	ifstream info;
	info.open("Info\\General Information.txt");
	string password;
	int channel_number, movieClub_number, seenMovies_number, recorded_number;

	info >> password >> channel_number >> movieClub_number >> seenMovies_number >> recorded_number;
	info.close();

	box.loadChannels(channel_number);
	box.load_movies_movieClub();
	box.load_movies_seen();
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