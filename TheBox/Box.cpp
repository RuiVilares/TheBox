#include "Box.h"


Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}


Date Box::GetCurrentDate(Box box)
{
	return box.currentDate;
}

string Box::GetPassword()
{
	return password;
}

void Box::rentMovies(const string &title){
	bool mfound = false, sfound = false;
	for (int i = 0; i < movieClub.size(); i++)
	{
		if (string_to_upper(title) == string_to_upper(movieClub[i].getTitle()))
		{
			mfound = true;
			movieClub[i].addTimesRented();
			seenMovies.push_back(movieClub[i]);
			movieClub.erase(movieClub.begin() + i);
			cout << "The movie \"" << seenMovies[seenMovies.size() - 1].getTitle() << "\" was rent by the MovieClub.";
			cout << endl << endl << endl << endl;
			break;
		}
	}
	if (!mfound)
		for (int i = 0; i < seenMovies.size(); i++)
		{
			if (string_to_upper(title) == string_to_upper(seenMovies[i].getTitle()))
			{
				sfound = true;
				seenMovies[i].addTimesRented();
				cout << "The movie \"" << seenMovies[i].getTitle() << "\" was rent again.";
				cout << endl << endl << endl << endl;
				break;
			}
		}
		if (!mfound && !sfound)
			cout << "The movie \"" << title << "\"" << " doesn't exist." << endl << endl << endl << endl;
}

bool Box::changePassword(string np){
	password = np;
	return true;
}


void Box::show_movies_movieClub()
{
	cout << "NAME" << setw(40) << "COST (EUR)" << endl;
	for (int i = 0; i < movieClub.size(); i++)
	{
		cout << movieClub.at(i).getTitle() << setw(40 - movieClub.at(i).getTitle().length()) << movieClub.at(i).getCost() << endl;
	}
	cout << "\n \n \n";
}


void Box::show_movies_seen()
{
	cout << "NAME" << setw(40) << "COST (EUR)" << setw(20) << "TIMES WATCHED" << endl;
	for (int i = 0; i < seenMovies.size(); i++)
	{
		cout << seenMovies.at(i).getTitle() << setw(40 - seenMovies.at(i).getTitle().length()) << seenMovies.at(i).getCost();
		cout << setw(15) << seenMovies.at(i).getTimesRented() << endl;
	}
	cout << "\n \n \n";
}

void Box::load_movies_movieClub()
{
	vector<Movie> Club;
	string s;
	float c;
	ifstream file;
	file.open("info//Movie Club.txt");
	if (!file.fail())
	{
		while (!file.eof())
		{
			getline(file, s);
			int i = 1;
			string name;
			do
			{
				name.push_back(s.at(i));
				i++;
			} while (s.at(i) != '\"');
			c = string_to_float(s.substr(i + 2, s.length()));
			Movie temp(name, c);
			Club.push_back(temp);
		}
		file.close();
	}
	movieClub = Club;
}

void Box::load_movies_seen()
{
	vector<Movie> Seen;
	string s;
	float c;
	int t;
	ifstream file;
	file.open("info//Seen Movies.txt");
	if (!file.fail())
	{
		while (!file.eof())
		{
			getline(file, s);
			int i = 1;
			string name, aux;
			do
			{
				name.push_back(s.at(i));
				i++;
			} while (s.at(i) != '\"');
			i+=2;
			do
			{
				aux.push_back(s.at(i));
				i++;
			} while (s.at(i) != ' ');
			c = string_to_float(aux);
			t = string_to_int(s.substr(i + 1, s.length()));
			Movie temp(name, c, t);
			Seen.push_back(temp);
		}
		file.close();
	}
	seenMovies = Seen;
}

float Box::moneySpent(){
	float totalCost = 0;

	for (int i = 0; i < seenMovies.size(); i++)
	{
		totalCost = totalCost + seenMovies[i].getCost()*seenMovies[i].getTimesRented();
	}
	return totalCost;
}

bool Box::Whatched(const string &title){
	for (int i = 0; i < seenMovies.size(); i++)
	{
		if (string_to_upper(title) == string_to_upper(seenMovies[i].getTitle()))
		{
			return true;
		}
	}
	return false;
}

void Box::show_timesWhatched(const string &title){
	for (int i = 0; i < seenMovies.size(); i++)
	{
		if (string_to_upper(title) == string_to_upper(seenMovies[i].getTitle()))
		{
			cout << "NAME" << setw(40) << "COST (EUR)" << setw(20) << "TIMES WATCHED" << endl;
			cout << seenMovies.at(i).getTitle() << setw(40 - seenMovies.at(i).getTitle().length()) << seenMovies.at(i).getCost();
			cout << setw(15) << seenMovies.at(i).getTimesRented() << endl;
			break;
		}
	}
}

bool Box::exist_in_movieClub(const string &title){
	for (int i = 0; i < movieClub.size(); i++)
	{
		if (string_to_upper(title) == string_to_upper(movieClub[i].getTitle()))
		{
			return true;
		}
	}
	return false;
}



vector<Movie> Box::GetSeenMovies()
{
	return seenMovies;
}

vector<Movie> Box::GetmovieClub()
{
	return movieClub;
}



// Channel CRUD


bool Box::createdChannel(string &n){
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName()==n)
		{
			return false;
		}
	}
	
	Channel new_channel(n);	// Isto dá erro    // 17/05/2014- Corrigido o erro. Faltava o construtor na classe
	channels.push_back(new_channel);
	saveChannels(channels);
	return true;
}



bool Box::removeChannel(string &n){
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == n)
		{
			channels.erase(channels.begin() + i);
			saveChannels(channels);
			return true;
		}
	}
	return false;
}

bool Box::updateChannel(string &channel_name){
	system("cls");
	string new_name;
	cout << "|||| UPDATE CHANNEL ||||\nChoose the channels new name:\n";
	getline(cin, new_name);
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == channel_name)
		{
			channels[i].setName(new_name);
			return true;
		}
	}
	return false;
}



// Program CRUD


int Box::searchProgram(string &program_name){					// Se encontrar o programa na lista de programas, retorna a posição do programa no vetor, senão retorna -1
	for (int i = 0; i < recordList.size(); i++)
	{
		if (recordList[i].getName() == program_name)
		{
			return i;
		}
	}
	return -1;
}


//bool Box::createdProgram(string &channel){
//	string new_program;
//	cout << "|||| CREATE PROGRAM ||||";
//	cout << endl << "Program name:\n";
//	cin >> new_program;
//	while (-1!=searchProgram(new_program))
//	{
//		system("cls");
//		cout << "|||| CREATE PROGRAM ||||";
//		cout << endl << "This name is already in use by another program\n Enter another name:\n";
//		cin >> new_program;
//
//	}
//
//	system("cls");
//	int duration, hour, min;
//	string type, day;
//
//
//	cout << "Insert the programs:\n";
//	//INSERIR DURACAO
//	cout << "Duration(in minutes): ";
//	cin >> duration;
//	while (cin.fail() || duration < 1)
//	{
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Wrong format. Please insert a number equal or bigger then 1: ";
//		cin >> duration;
//	}
//
//
//	//INSERIR HORA INÍCIO
//
//	cout << "\nStarting hour: "; cin >> hour;
//	while (cin.fail() || hour > 23 || hour < 0)
//	{
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Wrong format. Please insert a number between 0 and 23: ";
//		cin >> hour;
//	}
//
//
//	// INSERIR MINUTOS
//	cout << "minutes: "; cin >> min;
//	while (cin.fail() || min > 59 || min < 0)
//	{
//		cin.clear();
//		cin.ignore(10000, '\n');
//		cout << "Wrong format. Please insert a number between 0 and 59: ";
//		cin >> min;
//	}
//
//
//	// INSERIR DIA DA SEMANA
//	int option;
//	cout << "Choose a day of the week:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n";
//	cin >> option;
//	bool repeat;
//	do
//	{
//		repeat = false;
//		switch (option)
//		{
//		case 1:
//			day = "Sunday";
//			break;
//		case 2:
//			day = "Monday";
//			break;
//		case 3:
//			day = "Tuesday";
//			break;
//		case 4:
//			day = "Wednesday";
//			break;
//		case 5:
//			day = "Thursday";
//			break;
//		case 6:
//			day = "Friday";
//			break;
//		case 7:
//			day = "Saturday";
//			break;
//		default:
//			repeat = true;
//			cout << "Option mismatch. Please choose a number between 1 and 7: ";
//			cin >> option;
//			break;
//		}
//	} while (repeat);
//	
//	////////////////////////////////////////////
//	// VERIFICAR A COMPATIBILIDADE DE HORÁRIOS
//	// por completar
//	////////////////////////////////////////////
//
//
//	for (int i = 0; i < channels.size(); i++)
//	{
//		if (channel==channels[i].getName())
//		{
//			channels[i].addProgram();
//		}
//	}
//}