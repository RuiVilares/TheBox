#include "Box.h"


Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}


Date Box::GetCurrentDate()
{
	return currentDate;
}

string Box::GetPassword()
{
	return password;
}


bool Box::changePassword(string np){
	password = np;
	return true;
}


void Box::saveInfo()
{
	ofstream file;
	file.open("info//General Information.txt");
	file.clear();
	file << password << endl;
	file << channels.size() << endl;
	file << movieClub.size() << endl;
	file << seenMovies.size() << endl;
	/*file << recorded.size() << endl;*/
	file << recordList.size();
	file.close();
}



vector<Channel> Box::getChannels(){
	return channels;
}


//MOVIE CLUB

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

void Box::save_movies()
{
	string s;
	float c;
	int t;
	ofstream mfile, sfile;
	mfile.open("info//Seen Movies.txt");
	sfile.open("info//Movie Club.txt");
	mfile.clear();
	sfile.clear();
	if (seenMovies.size() > 0)
	{
		mfile << "\"" << seenMovies[0].getTitle() << "\" " << seenMovies[0].getCost() << " " << seenMovies[0].getTimesRented();
		for (int i = 1; i < seenMovies.size(); i++)
		{
			mfile << endl << "\"" << seenMovies[i].getTitle() << "\" " << seenMovies[i].getCost() << " " << seenMovies[i].getTimesRented();
		}
	}
	if (movieClub.size() > 0)
	{
		sfile << "\"" << movieClub[0].getTitle() << "\" " << movieClub[0].getCost();
		for (int i = 1; i < movieClub.size(); i++)
		{
			sfile << endl << "\"" << movieClub[i].getTitle() << "\" " << movieClub[i].getCost();
		}
	}
	mfile.close();
	sfile.close();
}





//TELEVISION

void Box::SetProgramRecorded()
{
	string name;
	int aux=-1;
	int i = 0;
	cout << "Insert a Program's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl << endl;
	for (i; i < channels.size(); i++)
	{
		aux = searchProgram(string_to_upper(name), channels[i]);
		if (aux >= 0)
		{
			break;
		}
	}

	if (aux >= 0)
	{
		/*if (channels[i].getPrograms()[aux].getState())
		{
			cout << "The program \"" << channels[i].getPrograms()[aux].getName();
			cout << "\", from the channel \"" << channels[i].getName() << "\", has been requested to be record." << endl << endl << endl << endl;
		}
		else
		{*/
			if (compDates(GetCurrentDate(), channels[i].getPrograms()[aux].getDate()))
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName() << "\", was sucefully set to be recorded." << endl << endl << endl << endl;
				//[i].getPrograms()[aux].setRecord(true);
				recordList.push_back(channels[i].getPrograms()[aux]);
			}
			else
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName() << "\", has been reproduced." << endl << endl << endl << endl;
			}
		//}
	}
	else 
		cout << "The program \"" << name << "\" doesn't exist." << endl << endl << endl << endl;
}

void Box::RemoveProgramToBeRecorded()
{
	string name;
	int aux = -1;
	int i = 0;
	cout << "Insert a Program's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl << endl;
	for (i; i < channels.size(); i++)
	{
		aux = searchProgram(string_to_upper(name), channels[i]);
		if (aux >= 0)
		{
			break;
		}
	}

	if (aux >= 0)
	{
		if (channels[i].getPrograms()[aux].getState())
		{
			if (compDates(GetCurrentDate(), channels[i].getPrograms()[aux].getDate()))
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName();
				cout << "\", was sucefully removed from the list of to be recorded programs." << endl << endl << endl << endl;
				//channels[i].getPrograms()[aux].setRecord(false);
				for (int j = 0; j < recordList.size(); j++)
				{
					if (string_to_upper(channels[i].getPrograms()[aux].getName()) == string_to_upper(recordList[j].getName()))
					{
						recordList.erase(recordList.begin() + j);
						break;
					}
				}
			}
			else
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName();
				cout << "\", is in the list of recorded programs." << endl << endl << endl << endl;
			}
		}
		else
		{
			cout << "The program \"" << channels[i].getPrograms()[aux].getName();
			cout << "\", from the channel \"" << channels[i].getName();
			cout << "\", isn't in the list of recorded program's nor in the list of to be recorded programs." << endl << endl << endl << endl;
		}
	}
	else
		cout << "The program \"" << name << "\" doesn't exist." << endl << endl << endl << endl;
}

void Box::RemoveProgramRecorded()					// Comentei porque estava a dar erro e queria ver uma coisa
{
	/*string name;
	int aux = -1;
	int i = 0;
	cout << "Insert a Program's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl << endl;
	for (i; i < channels.size(); i++)
	{
		aux = searchProgram(string_to_upper(name), channels[i]);
		if (aux >= 0)
		{
			break;
		}
	}

	if (aux >= 0)
	{
		if (channels[i].getPrograms()[aux].getState())
		{
			if (!compDates(GetCurrentDate(), channels[i].getPrograms()[aux].getDate()))
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName();
				cout << "\", was sucefully removed from the list of recorded programs." << endl << endl << endl << endl;
				channels[i].getPrograms()[aux].setRecord(false);
				for (int j = 0; j < recorded.size(); j++)
				{
					if (string_to_upper(channels[i].getPrograms()[aux].getName()) == string_to_upper(recorded[j].getName()))
					{
						recorded.erase(recorded.begin() + j);
						break;
					}
				}
			}
			else
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName();
				cout << "\", is in the list of to be recorded programs." << endl << endl << endl << endl;
			}
		}
		else
		{
			cout << "The program \"" << channels[i].getPrograms()[aux].getName();
			cout << "\", from the channel \"" << channels[i].getName();
			cout << "\", isn't in the list of recorded program's nor in the list of to be recorded programs." << endl << endl << endl << endl;
		}
	}
	else
		cout << "The program \"" << name << "\" doesn't exist." << endl << endl << endl << endl;*/
}


bool Box::RecordProgram(string &program_name, string &channel_name){
	int channel_loc = searchChannel(channel_name);
	Channel * channel = &channels[channel_loc];

	int program = searchProgram(program_name, *channel);

	for (int i = 0; i < recordList.size(); i++)
	{
		if (channel->getPrograms()[program].getName()==recordList[i].getName())
		{
			return false;
		}
	}
	
	if (currentDate.getTotalDate() < channel->getPrograms()[program].getDate().getTotalDate())
	{
		bool state = true;
		channel->getPrograms()[program].setRecord(state);
	}
	recordList.push_back(channel->getPrograms()[program]);
	saveChannels();
	/*saveRecordList();*/
	return true;
}


void Box::showPrograms(vector<Program> &list_programs){
	for (int i = 0; i < list_programs.size(); i++)
	{
		cout << i + 1 << ". " << list_programs[i].getName() << endl;
	}
}



//CHANNELS

void Box::saveChannels(){
	ofstream channels_file;
	channels_file.open("Info\\Channels.txt");

	for (int i = 0; i < channels.size(); i++)
	{
		vector<Program> program_list;
		program_list = channels[i].getPrograms();

		channels_file << channels[i].getName() << endl;
		channels_file << program_list.size() << endl;

		for (int k = 0; k < program_list.size(); k++)
		{
			channels_file << '\"' << program_list[k].getName() << '\"';
			channels_file << " " << program_list[k].getDuration();
			channels_file << " " << '\"' << program_list[k].getType() << '\"';

			if (program_list[k].getState())
			{
				channels_file << " " << 1;
			}
			else
			{
				channels_file << " " << 0;
			}

			channels_file << " " << '\"' << program_list[k].getDate().getDay() << '\"';
			channels_file << " " << program_list[k].getDate().getHour();
			channels_file << " " << program_list[k].getDate().getMinutes() << endl;
		}
	}
	channels_file.close();
}


void Box::loadChannels(int channels_number){
	ifstream channels_file;
	channels_file.open("Info\\Channels.txt");

	for (int i = 0; i < channels_number; i++)
	{
		string channel_name;
		channels_file >> channel_name;
		Channel new_channel = Channel(channel_name);
		int program_number;
		channels_file >> program_number;
		for (int k = 0; k < program_number; k++)
		{
			string name, type, day;
			int duration, hour, min, state;
			bool recordState = false;

			// Add name

			channels_file.ignore(2);

			do
			{
				char name_char;
				channels_file >> name_char;
				name.push_back(name_char);
				if (channels_file.peek() == ' ')
				{
					name.push_back(' ');
				}
			} while (channels_file.peek() != '\"');
			channels_file.ignore();

			// Add duration
			channels_file >> duration;

			// Add type
			channels_file.ignore(2);
			while (channels_file.peek() != '\"')
			{
				char name_char;
				channels_file >> name_char;
				type.push_back(name_char);
			}
			channels_file.ignore();

			// Add recordState
			channels_file >> state;
			if (state)
			{
				recordState = true;
			}


			// Add day
			channels_file.ignore(2);
			while (channels_file.peek() != '\"')
			{
				char name_char;
				channels_file >> name_char;
				day.push_back(name_char);
			}
			channels_file.ignore();

			// Add hour and minutes
			channels_file >> hour >> min;


			new_channel.addProgram(name, duration, type, recordState, day, hour, min);
		}

		channels.push_back(new_channel);
	}

}


void Box::showChannels(){
	for (int i = 0; i < channels.size(); i++)
	{
		cout << i + 1 << ". " << channels[i].getName() << endl;
	}
}


// Channel CRUD

int Box::searchChannel(string &channel_name){
	for (int i = 0; i < channels.size(); i++)
	{
		if (string_to_upper(channels[i].getName()) == string_to_upper(channel_name))
		{
			return i;
		}
	}
	return -1;
}

void Box::createChannel()
{
	string name;
	vector<Program> vec;
	cout << "Insert a channel's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	if (searchChannel(name) == -1)
	{
		Channel temp(name);
		channels.push_back(temp);
		cout << endl << endl << "The channel \"" << name << "\", was successfully created." << endl << endl << endl;
	}
	else
	{
		cout << endl << endl << "The channel \"" << name << "\" already exists." << endl << endl << endl;
	}
}

void Box::removeChannel()
{
	string name;
	cout << "Insert a channel's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	int aux = searchChannel(name);
	if (aux != -1)
	{
		channels.erase(channels.begin() + aux);
		cout << endl << endl << "The channel \"" << name << "\", was successfully removed." << endl << endl << endl;
	}
	else
	{
		cout << endl << endl << "The channel \"" << name << "\" doesn't exist." << endl << endl << endl;
	}
}


void Box::updateChannel(string &name)
{	
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a channel" << endl << endl;
	string newname;
	cout << "Insert a new name to this channel: ";
	cin.clear();
	cin.ignore();
	getline(cin, newname);
	if (string_to_upper(name) == string_to_upper(newname))
	{
		cout << endl << endl << "The channel \"" << name << "\" already have this name." << endl << endl << endl;
	}
	else
	{
		cout << endl << endl << "The name of the channel \"" << name << "\" was change to \"" << newname << "\"." << endl << endl << endl;
	}
}



// Program CRUD
bool Box::checkProgramDate(Date new_program_date, int duration, Channel &channel){
	for (int i = 0; i < channel.getPrograms().size(); i++)
	{
		Date program_date = channel.getPrograms()[i].getDate();

		int begin_new_program, end_new_program;			//Valor dos minutos a que começa o programa durante a semana. O inicio da contagem é à meia noite de domingo.
		begin_new_program = (new_program_date.getInt(new_program_date.getDay()) - 1) * 24 * 60 + new_program_date.getHour() * 60 + new_program_date.getMinutes();
		end_new_program = begin_new_program + duration;

		int begin_program, end_program;

		begin_program = (channel.getPrograms()[i].getDate().getInt(channel.getPrograms()[i].getDate().getDay()) - 1) * 24 * 60 + channel.getPrograms()[i].getDate().getHour() * 60 + channel.getPrograms()[i].getDate().getMinutes();
		end_program = begin_program + channel.getPrograms()[i].getDuration();

		if ((begin_program < begin_new_program && end_program > begin_new_program) || (begin_program < end_new_program && end_program > end_new_program))
		{
			return false;
		}
	}
	return true;
}


int Box::searchProgram(string &program_name, Channel &channel){					// Se encontrar o programa na lista de programas, retorna a posição do programa no vetor, senão retorna -1
	
	
	
	for (int i = 0; i < channel.getPrograms().size(); i++)
	{
		if (channel.getPrograms()[i].getName() == program_name)
		{
			return i;
		}
	}
	return -1;
}


/*bool Box::createdProgram(string &channel){


	Channel * channel_pointer;

	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName()==channel)
		{
			channel_pointer = &channels[i];
		}
	}
	
	string new_program;
	cout << "|||| CREATE PROGRAM ||||";
	cout << endl << "Program name:\n";
	cin >> new_program;
	while (-1 != searchProgram(new_program, *channel_pointer))
	{
		system("cls");
		cout << "|||| CREATE PROGRAM ||||";
		cout << endl << "This name is already in use by another program\n Enter another name:\n";
		cin >> new_program;

	}

	system("cls");
	int duration, hour, min;
	string type, day;




	/////////////////////////////////////////////
	// VERIFICAR A COMPATIBILIDADE DE HORÁRIOS //
	//										   //
	/////////////////////////////////////////////


	Date new_program_date = Date();




	do
	{
		cout << "Insert the programs:\n";
		//INSERIR DURACAO
		cout << "Duration(in minutes): ";
		cin >> duration;
		while (cin.fail() || duration < 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number equal or bigger then 1: ";
			cin >> duration;
		}


		//INSERIR HORA INÍCIO

		cout << "\nStarting hour: "; cin >> hour;
		while (cin.fail() || hour > 23 || hour < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number between 0 and 23: ";
			cin >> hour;
		}


		// INSERIR MINUTOS
		cout << "minutes: "; cin >> min;
		while (cin.fail() || min > 59 || min < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number between 0 and 59: ";
			cin >> min;
		}


		// INSERIR DIA DA SEMANA
		int option;
		cout << "Choose a day of the week:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n";
		cin >> option;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Option mismatch. Please choose a number between 1 and 7: ";
			cin >> option;
		}
		bool repeat;
		do
		{
			repeat = false;
			switch (option)
			{
			case 1:
				day = "Sunday";
				break;
			case 2:
				day = "Monday";
				break;
			case 3:
				day = "Tuesday";
				break;
			case 4:
				day = "Wednesday";
				break;
			case 5:
				day = "Thursday";
				break;
			case 6:
				day = "Friday";
				break;
			case 7:
				day = "Saturday";
				break;
			default:
				repeat = true;
				cout << "Option mismatch. Please choose a number between 1 and 7: ";
				cin >> option;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Option mismatch. Please choose a number between 1 and 7: ";
					cin >> option;
				}
				break;
			}
		} while (repeat);

		new_program_date.setDate(day, hour, min);
		
		if (!checkProgramDate(new_program_date, duration, *channel_pointer))
		{
		system("cls");
		cout << "|||| CREATE PROGRAM ||||";
		cout << endl << "Error. The exhibition time matches the exhibition time of an already existing program.\nPlease enter different values\n";
		}

		
	} while (checkProgramDate(new_program_date, duration, *channel_pointer));


	// ADICIONAR TIPO DE PROGRAMA

	cout << "Program Type: ";
	cin.clear();
	cin.ignore(1000, '\n');
	cin >> type;

	 
	
	  //// ADICIONAR RECORDED
		//int begin_new_program = (new_program_date.getInt(new_program_date.getDay()) - 1) * 24 * 60 + new_program_date.getHour() * 60 + new_program_date.getMinutes();
		//int current_date_min = (currentDate.getInt(currentDate.getDay()) - 1) * 24 * 60 + currentDate.getHour() * 60 + currentDate.getMinutes();
		//if (begin_new_program > current_date_min)
		//{
		//	recorded = false;
		//}
		//else
		//{
		//	recorded = true;
		//}		
	

	bool recorded = false;

	// ADICIONAR Programa
	channel_pointer->addProgram(new_program, duration, type, recorded, day, hour, min);
	return true;
	
}

*/



bool Box::removeProgram(string &channel, string &program){
	char ans;
	cout << "|||| DELETE PROGRAM ||||";
	cout << "Are you sure you want to delete this program(Y/N)?\n";
	cin >> ans;
	while (ans != 'Y' && ans != 'N')
	{
		cout << "Option mismatch. Enter Y to yes or N to no: ";
	}
	
	if ('N' == ans)
	{
		return false;
	}
	
	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName()==channel)
		{
			channels[i].getPrograms().erase(channels[i].getPrograms().begin() + searchProgram(program, channels[i]));
			return true;
		}
	}
	return false;
}

/*
bool Box::updateProgram(string &channel, string &program){
	
	Program * program_pointer;
	Channel * channel_pointer;

	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == channel)
		{
			channel_pointer = &channels[i];
		}
	}
	
	program_pointer= &channel_pointer->getPrograms()[searchProgram(program, *channel_pointer)];
	
	int option;

	system("cls");
	cout << "|||| UPDATE PROGRAM ||||";
	cout << "Select one of the options:\n"
		<< "1. Change name"
		<< "2. Change duration"
		<< "3. Change type"
		<< "4. Change record state"
		<< "5. Change exhibition date\n"
		<< "6. Return"
		<< "Option number: ";
	cin >> option;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Option mismatch. Please choose a number between 1 and 6: ";
		cin >> option;
	}




	
	
	bool repeat;
	do
	{
		system("cls");
		cout << "|||| UPDATE PROGRAM ||||";
		cout << endl << "Select one of the options:\n"
			<< "1. Change name"
			<< "2. Change duration"
			<< "3. Change type"
			<< "4. Change record state"
			<< "5. Change exhibition date\n"
			<< "6. Return"
			<< "Option number: ";
		cin >> option;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Option mismatch. Please choose a number between 1 and 6: ";
			cin >> option;
		}
		switch (option)
		{
			case 1:
				{
					string new_name;
					system("cls");
					cout << "|||| UPDATE PROGRAM ||||";
					cout << "\nChoose a new name:";
					cin >> new_name;

					while (searchProgram(new_name, *channel_pointer) && new_name != program)
					{
						cout << "Name already in use by another program. Please choose other name.\n";
						cin >> new_name;
					}
					program_pointer->setName(new_name);

				}
				break;
			case 2:
				{	
						int duration;

					system("cls");
					cout << "|||| UPDATE PROGRAM ||||";
					cout << "Enter duration: ";
					cin >> duration;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(100000, '\n');
						cout << "Invalid input. Please enter another value for duration: ";
						cin >> duration;
					}

					Channel new_channel = *channel_pointer;
					new_channel.removeProgram(program_pointer->getName());

					while (!checkProgramDate(program_pointer->getDate(), duration, new_channel))
					{
						cout << "The duration of the program overlaps with another program\nPlease enter another value: ";
						cin >> duration;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(100000, '\n');
							cout << "Invalid input. Please enter another value for duration: ";
							cin >> duration;
						}
				}

				program_pointer->setDuration(duration);

			}

			break;
		case 3:
			{
				  system("cls");
				  cout << "|||| UPDATE PROGRAM ||||";
				  cout << "\n Choose new type:\n";
				  string type;
				  cin >> type;
				  program_pointer->setType(type);
			}
			
			break;
		case 4:
			{
				  system("cls");
				  if (program_pointer->getState())
				  {
					  bool state = false;
					  program_pointer->setRecord(state);
				  }
				  else
				  {
					  bool state = true;
					  program_pointer->setRecord(state);
				  }
				  cout << "Record state changed";
			}
			break;
		case 5:
			{
				  system("cls");
				  cout << "|||| UPDATE PROGRAM ||||";
				  int hour, min;
				  string day;

				  Date new_date = Date();

				  do
				  {
					  cout << "Insert the programs:\n";
					  
					  //INSERIR HORA INÍCIO

					  cout << "\nStarting hour: "; cin >> hour;
					  while (cin.fail() || hour > 23 || hour < 0)
					  {
						  cin.clear();
						  cin.ignore(10000, '\n');
						  cout << "Wrong format. Please insert a number between 0 and 23: ";
						  cin >> hour;
					  }


					  // INSERIR MINUTOS
					  cout << "minutes: "; cin >> min;
					  while (cin.fail() || min > 59 || min < 0)
					  {
						  cin.clear();
						  cin.ignore(10000, '\n');
						  cout << "Wrong format. Please insert a number between 0 and 59: ";
						  cin >> min;
					  }


					  // INSERIR DIA DA SEMANA
					  int option;
					  cout << "Choose a day of the week:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n";
					  cin >> option;

					  while (cin.fail())
					  {
						  cin.clear();
						  cin.ignore(10000, '\n');
						  cout << "Option mismatch. Please choose a number between 1 and 7: ";
						  cin >> option;
					  }
					  bool repeat;
					  do
					  {
						  repeat = false;
						  switch (option)
						  {
						  case 1:
							  day = "Sunday";
							  break;
						  case 2:
							  day = "Monday";
							  break;
						  case 3:
							  day = "Tuesday";
							  break;
						  case 4:
							  day = "Wednesday";
							  break;
						  case 5:
							  day = "Thursday";
							  break;
						  case 6:
							  day = "Friday";
							  break;
						  case 7:
							  day = "Saturday";
							  break;
						  default:
							  repeat = true;
							  cout << "Option mismatch. Please choose a number between 1 and 7: ";
							  cin >> option;
							  while (cin.fail())
							  {
								  cin.clear();
								  cin.ignore(10000, '\n');
								  cout << "Option mismatch. Please choose a number between 1 and 7: ";
								  cin >> option;
							  }
							  break;
						  }
					  } while (repeat);

					  new_date.setDate(day, hour, min);

					  if (!checkProgramDate(new_date, program_pointer->getDuration(), *channel_pointer))
					  {
						  system("cls");
						  cout << "|||| CREATE PROGRAM ||||";
						  cout << endl << "Error. The exhibition time matches the exhibition time of an already existing program.\nPlease enter different values\n";
					  }
					 
				  } while (checkProgramDate(new_date, program_pointer->getDuration(), *channel_pointer));
				  
				  program_pointer->setDate(day, hour, min);
			}
			break;
		case 6:
			return true;
			break;
		default:
			repeat = true;
			cout << "Option mismatch. Please choose a number between 1 and 6: ";
			cin >> option;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Option mismatch. Please choose a number between 1 and 6: ";
				cin >> option;
			}
			break;
		}
	} while (repeat);

}

*/

// MOVIE CRDU 
void Box::createMovie()
{
	string name;
	bool valid=false;
	float cost;
	cout << "Insert a movie's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	if (!exist_in_movieClub(name) && !Whatched(name))
	{
		do
		{
			cout << "Insert a movie's cost (EUR): ";
			cin >> cost;
			if (cost >= 0)
				valid = true;
			else

			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');

				}
			}
		} while (!valid);
		Movie temp(name, cost);
		movieClub.push_back(temp);
		cout << endl << endl << "The movie \"" << name << "\" which costs " << cost << " (EUR), was successfully created." << endl << endl << endl;
	}
	else
	{
		if (exist_in_movieClub(name) || Whatched(name))
			cout << endl << endl << "The movie \"" << name << "\" already exists." << endl << endl << endl;
		else
			cout << endl << endl << "Invalid Option." << endl << endl << endl;
	}
}

void Box::removeMovie()
{
	string name;
	bool valid = false;
	float cost;
	cout << "Insert a movie's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl;
	if (!exist_in_movieClub(name) && !Whatched(name))
		cout << "The movie \"" << name << "\" doesn't exist." << endl << endl << endl;
	else
	{
		if (exist_in_movieClub(name))
		{
			for (int i = 0; i < movieClub.size(); i++)
			{
				if (string_to_upper(name) == string_to_upper(movieClub[i].getTitle()))
				{
					cout << "The movie \"" << movieClub[i].getTitle() << "\" was successfully";
					cout << " removed by the Movieclub." << endl << endl << endl;
					movieClub.erase(movieClub.begin() + i);
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < seenMovies.size(); i++)
			{
				if (string_to_upper(name) == string_to_upper(seenMovies[i].getTitle()))
				{
					cout << "The movie \"" << seenMovies[i].getTitle() << "\" was successfully";
					cout << " removed by the list of movies previously seen." << endl << endl << endl;
					seenMovies.erase(seenMovies.begin() + i);
					break;
				}
			}
		}

	}
}

void Box::updateMovie(int i, string name)
{
	cin.clear();
	cin.ignore();
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a movie" << endl << endl;
	if (i == 1)
	{
		string aux;
		for (int i = 0; i < movieClub.size(); i++)
		{
			if (string_to_upper(name) == string_to_upper(movieClub[i].getTitle()))
			{
				cout << "Insert a new title to this movie: ";
				getline(cin, aux);
				cout << endl << endl << "The title of the movie \"" << movieClub[i].getTitle() << "\"";
				cout << " was change to \"" << aux << "\"";
				movieClub[i].setTitle(aux);
				break;
			}
		}
	}
	if (i == 2)
	{
		float aux;
		for (int i = 0; i < movieClub.size(); i++)
		{
			if (string_to_upper(name) == string_to_upper(movieClub[i].getTitle()))
			{
				cout << "Insert a new cost to this movie: ";
				do
				{
					cin >> aux;
				} while (aux < 0);
				cout << endl << endl << "The movie \"" << movieClub[i].getTitle() << "\"";
				cout << " was change it's rent cost from " << movieClub[i].getCost() << " (EUR) to " << aux << " (EUR).";
				movieClub[i].setCost(aux);
				break;
			}
		}
	}
	if (i == 3)
	{
		string aux;
		for (int i = 0; i < seenMovies.size(); i++)
		{
			if (string_to_upper(name) == string_to_upper(seenMovies[i].getTitle()))
			{
				cout << "Insert a new title to this movie: ";
				getline(cin, aux);
				cout << endl << endl << "The title of the movie \"" << seenMovies[i].getTitle() << "\"";
				cout << " was change to \"" << aux << "\"";
				seenMovies[i].setTitle(aux);
				break;
			}
		}
	}
	if (i == 4)
	{
		float aux;
		for (int i = 0; i < seenMovies.size(); i++)
		{
			if (string_to_upper(name) == string_to_upper(seenMovies[i].getTitle()))
			{
				cout << "Insert a new cost to this movie: ";
				do
				{
					cin >> aux;
				} while (aux<0);
				cout << endl << endl << "The movie \"" << seenMovies[i].getTitle() << "\"";
				cout << " was change it's rent cost from " << seenMovies[i].getCost() << " (EUR) to " << aux << " (EUR).";
				seenMovies[i].setCost(aux);
				break;
			}
		}
	}
	if (i == 5)
	{
		int aux;
		for (int i = 0; i < seenMovies.size(); i++)
		{
			if (string_to_upper(name) == string_to_upper(seenMovies[i].getTitle()))
			{
				cout << "Insert a new number of times the movie was rent: ";
				do
				{
					cin >> aux;
				} while (aux < 0);
				cout << endl << endl << "The movie \"" << seenMovies[i].getTitle() << "\"";
				cout << " was change it's number of times that it was rent from " << seenMovies[i].getTimesRented() << endl;
				cout << " to " << aux << ".";
				if (aux == 0)
				{
					Movie temp(seenMovies[i].getTitle(), seenMovies[i].getCost());
					seenMovies.erase(seenMovies.begin() + i);
					movieClub.push_back(temp);
				}
				else
					seenMovies[i].setTimesRented(aux);
				break;
			}
		}
	}
	cout << endl << endl << endl;
}


