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

bool Box::rentMovies(string &title){
	for (int i = 0; i < movieClub.size(); i++)
	{
		if (title == movieClub[i].getTitle())
		{
			seenMovies.push_back(movieClub[i]);
			movieClub.erase(movieClub.begin() + i);
			return true;
		}
	}
	return false;
}

bool Box::changePassword(string np){
	password = np;
	return true;
}


void Box::show_movies_movieClub()
{
	cout << "NAME" << setw(35) << "COST" << endl;
	for (int i = 0; i < movieClub.size(); i++)
	{
		cout << movieClub.at(i).getTitle() << setw(40 - movieClub.at(i).getTitle().length()) << movieClub.at(i).getCost() << endl;
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
		c = string_to_int(s.substr(i + 2, s.length()));
		Movie temp(name, c);
		Club.push_back(temp);
	}
	file.close();
	movieClub = Club;
}

float Box::moneySpent()/* const*/{
	float totalCost = 0;

	for (int i = 0; i < seenMovies.size(); i++)
	{
		totalCost = totalCost + seenMovies[i].getCost();
	}
	return totalCost;
}

int Box::timesWhatched(string &title)/* const*/{
	for (int i = 0; i < seenMovies.size(); i++)
	{
		if (title == movieClub[i].getTitle())
		{
			return movieClub[i].getTimesRented();
		}
	}
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
	
	Channel new_channel(n);	// Isto dá erro
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

//bool updateChannel(){
//	system("cls");
//	cout << ""
//}