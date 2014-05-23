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
	file << recordList.size();
	file.close();
}



vector<Channel> Box::getChannels(){
	return channels;
}



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


	saveInfo();
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


void Box::saveRecorded(){
	ofstream recorded_file;
	recorded_file.open("Info\\Recorded.txt");
	for (int i = 0; i < recordList.size(); i++)
	{
		recorded_file << recordList[i].getName() << endl;
	}
	saveInfo();
}



void Box::loadRecorded(int recorded_number){
	ifstream recorded_file;
	recorded_file.open("Info\\Recorded.txt");

	for (int i = 0; i < recorded_number; i++)
	{
		string name;
		getline(recorded_file, name);
		for (int i = 0; i < channels.size(); i++)
		{
			if (searchProgram(name, channels[i]) != -1)
			{

				//Avalia a data do programa com a data actual
				if (currentDate.getTotalDate()>channels[i].getPrograms()[searchProgram(name, channels[i])].getDate().getTotalDate())
				{
					bool state = true;
					channels[i].setProgramState(searchProgram(name, channels[i]), state);
				}
				else
				{
					bool state = false;
					channels[i].setProgramState(searchProgram(name, channels[i]), state);
				}

				// Copia o programa para o recordList
				recordList.push_back(channels[i].getPrograms()[searchProgram(name, channels[i])]);
			}
		}
	}
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
	int existInRecord = false;
	for (int j = 0; j < recordList.size(); j++)
	{
		if (string_to_upper(name) == string_to_upper(recordList[j].getName()))
		{
			existInRecord = true;
			cout << "The program \"" << name << "\", is in the list of recorded programs." << endl << endl << endl << endl;
			break;
		}
	}
	if (!existInRecord)
	{
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

			if (compDates(GetCurrentDate(), channels[i].getPrograms()[aux].getDate()))
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName() << "\", was sucefully\n";
				cout << "set to be recorded." << endl << endl << endl << endl;
				recordList.push_back(channels[i].getPrograms()[aux]);
			}
			else
			{
				cout << "The program \"" << channels[i].getPrograms()[aux].getName();
				cout << "\", from the channel \"" << channels[i].getName() << "\", has been reproduced." << endl << endl << endl << endl;
			}
		}
		else
			cout << "The program \"" << name << "\" doesn't exist." << endl << endl << endl << endl;
	}
}



void Box::RemoveProgramRecorded()
{
	string name;
	int aux = -1;
	bool found = false;
	cout << "Insert a Program's name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << endl << endl << endl;
	for (int i = 0; i < recordList.size(); i++)
	{
		if (string_to_upper(recordList[i].getName()) == string_to_upper(name))
		{
			recordList.erase(recordList.begin() + i);
			saveRecorded();
			cout << "The program \"" << name;
			cout << "\", was sucefully removed from the list\n";
			cout << "of recorded programs." << endl << endl << endl << endl;
			found = true;

		}

	}

	if (found == false)
	{
		cout << "The program \"" << name << "\", isn't in the list of recorded programs." << endl << endl << endl << endl;
	}


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
	
	if (currentDate.getTotalDate() > channel->getPrograms()[program].getDate().getTotalDate())
	{
		bool state = true;
		channel->getPrograms()[program].setRecord(state);
	}
	recordList.push_back(channel->getPrograms()[program]);
	saveChannels();
	saveRecorded();
	return true;
}



void Box::ProgramRecordedShow()
{
	cout << "Name" << setw(27) << "Type" << setw(10) << "Duration" << setw(10) << "Date" << setw(25) << "Already recorded" <<  endl;
	for (int i = 0; i < recordList.size(); i++)
	{
		cout << recordList[i].getName() << setw(32 - recordList[i].getName().size()) << recordList[i].getType();
		cout << setw(8) << recordList[i].getDuration() << setw(10);
		recordList[i].getDate().showDate();
		if (recordList[i].getState())
			cout << setw(15) << "X";
		cout << endl;
	}
	cout << endl << endl;
}


void Box::showPrograms(vector<Program> &list_programs){
	for (int i = 0; i < list_programs.size(); i++)
	{
		cout << i + 1 << ". " << list_programs[i].getName() << endl;
	}
}



//CHANNELS


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
		if (string_to_upper(channels[i].getName()) == string_to_upper(channel_name) || channels[i].getName() == string_to_upper(channel_name))
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
		if (string_to_upper(channel.getPrograms()[i].getName()) == string_to_upper(program_name))
		{
			return i;
		}
	}
	return -1;
}


bool Box::createdProgram(string &channel){


	Channel * channel_pointer;

	channel_pointer = &Channel(channel); // Esta linha serve para o programa não dar erro porque existe a possibilidade de o apontador não ser inicializado

	for (int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName()==channel)
		{
			channel_pointer = &channels[i];
		}
	}
	system("CLS");
	string new_program;
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Create a program" << endl << endl;
	cout << endl << "Program name: ";
	getline(cin, new_program);
	if (-1 != searchProgram(new_program, *channel_pointer))
	{
		cout << endl << endl << "This name is already in use by another program.";
		Sleep(2000);
		createdProgram(channel);
	}

	int duration, hour, min;
	string type, day;




	/////////////////////////////////////////////
	// VERIFICAR A COMPATIBILIDADE DE HORÁRIOS //
	//										   //
	/////////////////////////////////////////////


	Date new_program_date = Date();




	
		cout << endl << endl << "Insert the program specifications:\n \n";
		//INSERIR DURACAO
		cout << "Duration(in minutes): ";
		cin >> duration;
		while (cin.fail() || duration < 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number equal or bigger then 1.\n";
			cout << "Duration(in minutes): ";
			cin >> duration;
		}


		//INSERIR HORA INÍCIO

		cout << "Starting hour: "; cin >> hour;
		while (cin.fail() || hour > 23 || hour < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number between 0 and 23.";
			cout << "\nStarting hour: ";
			cin >> hour;
		}


		// INSERIR MINUTOS
		cout << "Starting minutes: "; cin >> min;
		while (cin.fail() || min > 59 || min < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong format. Please insert a number between 0 and 59.";
			cout << "\nStarting minutes: ";
			cin >> min;
		}


		// INSERIR DIA DA SEMANA
		int option;
		cout << "\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n";
		cout << "Choose a day of the week : ";
		cin >> option;

		while (cin.fail() || option < 1 || option > 7)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Option mismatch. Please choose a number between 1 and 7: ";
			cin >> option;
		}
		
		
		day = new_program_date.getStr(option);

		new_program_date.setDate(day, hour, min);
		
		if (!checkProgramDate(new_program_date, duration, *channel_pointer))
		{
		cout << endl << "Error. The exhibition time matches the exhibition time of an already existing program.\nPlease enter different values\n";
		Sleep(2000);
		createdProgram(channel);
		}

	


	// ADICIONAR TIPO DE PROGRAMA

	cout << "\nProgram Type: ";
	cin.clear();
	cin.ignore(1000, '\n');
	cin >> type;

	 
	
	

	bool recorded = false;

	// ADICIONAR Programa
	channel_pointer->addProgram(new_program, duration, type, recorded, day, hour, min);
	saveChannels();
	return true;
	
}





void Box::removeProgram(){
	int channel_position = 0;
	int program_position;
	string programn;
	cin.ignore();
	cin.clear();
	cout << "\nInsert a program name: ";
	getline(cin, programn);
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	if (program_position == -1)
	{
		cout << endl << endl << "This program doesn't exist." << endl << endl << endl;
	}
	else
	{
		cout << endl << endl << "The program \"" << channels[channel_position].getPrograms()[program_position].getName();
		cout << "\", from the channel \"" << channels[channel_position].getName() << "\", was sucefully removed" << endl << endl << endl;
		channels[channel_position].removeProgram(channel_position);
	}
}




bool Box::updateProgram(string &programn){
	int channel_position = 0;
	int program_position = 0;
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	if (program_position == -1)
	{
		return false;
	}
	else
		return true;
}


void Box::updateProgramName(string &programn)
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a program" << endl << endl << endl;
	int channel_position = 0;
	int program_position = 0;
	string newname;
	cout << "Insert a new name to this program: ";
	cin.clear();
	cin.ignore();
	getline(cin, newname);
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	cout << endl << endl << "The name of the program \"" << channels[channel_position].getPrograms()[program_position].getName() << "\"";
	cout << " was change to \"" << newname << "\"";
	Sleep(3000);
	channels[channel_position].setProgramName(newname, program_position);
}

void Box::updateProgramDuration(string &programn)
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a program" << endl << endl << endl;
	int channel_position = 0;
	int program_position = 0;
	int newdur;
	cout << "Insert a new duration to this program: ";
	cin >> newdur;
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}

	Channel * channel_pointer;
	channel_pointer = &channels[channel_position];
	Program oldp(channels[channel_position].getPrograms()[program_position]);
	Program newp(channels[channel_position].getPrograms()[program_position]);
	newp.setDuration(newdur);
	channels[channel_position].removeProgram(program_position);
	if (!checkProgramDate(oldp.getDate(), newdur, *channel_pointer))
	{
		channels[channel_position].addProgram(oldp);
		cout << endl << "Error. The exhibition time matches the exhibition time of an \n";
		cout << "already existing program.\n \nPlease enter different values\n";
		Sleep(3000);
	}
	else
	{
		channels[channel_position].addProgram(newp);
		cout << endl << endl << "The duration of the program \"" << newp.getName() << "\"";
		cout << " was change to \"" << newdur << "\"";
		Sleep(3000);
	}
	
}

void Box::updateProgramType(string &programn)
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a program" << endl << endl << endl;
	int channel_position = 0;
	int program_position = 0;
	string newtype;
	cout << "Insert a new type to this program: ";
	cin.clear();
	cin.ignore();
	getline(cin, newtype);
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	cout << endl << endl << "The type of the program \"" << channels[channel_position].getPrograms()[program_position].getName() << "\"";
	cout << " was change to \"" << newtype << "\"";
	Sleep(3000);
	channels[channel_position].setProgramType(newtype, program_position);
}

void Box::updateProgramState(string &programn)
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a program" << endl << endl << endl;
	int channel_position = 0;
	int program_position = 0;
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	if (compDates(GetCurrentDate(), channels[channel_position].getPrograms()[program_position].getDate()))
	{
		cout << "The program \"" << channels[channel_position].getPrograms()[program_position].getName() << "\"";
		cout << " wasn't reproduced yet";
		Sleep(3000);
	}
	else
	{
		cout << endl << endl << "The record state of the program \"" << channels[channel_position].getPrograms()[program_position].getName() << "\"";
		cout << " was change to \"";
		if (channels[channel_position].getPrograms()[program_position].getState())
			cout << "true";
		else
			cout << "false";
		cout << "\"";
		Sleep(3000);
		channels[channel_position].setProgramState(program_position);
	}
		
}

void Box::updateProgramDate(string &programn)
{
	system("CLS");
	cout << "     _       _                               _ " << endl;
	cout << "    / \\   __| |_   ____ _ _ __   ___ ___  __| |" << endl;
	cout << "   / _ \\ / _` \\ \\ / / _` | '_ \\ / __/ _ \\/ _` |" << endl;
	cout << "  / ___ \\ (_| |\\ V / (_| | | | | (_|  __/ (_| |" << endl;
	cout << " /_/   \\_\\__,_| \\_/ \\__,_|_| |_|\\___\\___|\\__,_|" << endl << endl;
	cout << "\t \t Update a program" << endl << endl << endl;
	int channel_position = 0;
	int program_position = 0;
	int hour, min;
	string day;
	Date new_program_date = Date();
	//INSERIR HORA INÍCIO

	cout << "New starting hour: "; cin >> hour;
	while (cin.fail() || hour > 23 || hour < 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Wrong format. Please insert a number between 0 and 23.";
		cout << "\nNew starting hour : ";
		cin >> hour;
	}


	// INSERIR MINUTOS
	cout << "New starting minutes: "; cin >> min;
	while (cin.fail() || min > 59 || min < 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Wrong format. Please insert a number between 0 and 59.";
		cout << "\nNew starting minutes: ";
		cin >> min;
	}


	// INSERIR DIA DA SEMANA
	int option;
	cout << "\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n";
	cout << "Choose a day of the week: ";
	cin >> option;

	while (cin.fail() || option < 1 || option > 7)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Option mismatch. Please choose a number between 1 and 7: ";
		cin >> option;
	}

	day = new_program_date.getStr(option);
	
	for (channel_position; channel_position < channels.size(); channel_position++)
	{
		program_position = searchProgram(programn, channels[channel_position]);
		if (program_position != -1)
			break;
	}
	Channel * channel_pointer;
	channel_pointer = &channels[channel_position];
	Program oldp(channels[channel_position].getPrograms()[program_position]);
	Program newp(channels[channel_position].getPrograms()[program_position]);
	newp.setDate(day, hour, min);
	channels[channel_position].removeProgram(program_position);
	if (!checkProgramDate(newp.getDate(), oldp.getDuration(), *channel_pointer))
	{
		channels[channel_position].addProgram(oldp);
		cout << endl << "Error. The exhibition time matches the exhibition time of an \n";
		cout << "already existing program.\n \nPlease enter different values\n";
		Sleep(3000);
	}
	else
	{
		channels[channel_position].addProgram(newp);
		cout << endl << endl << "The date of the program \"" << newp.getName() << "\"";
		cout << " was change to \"";
		newp.getDate().showDate();
		cout << "\"";
		Sleep(3000);
	}

}




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


