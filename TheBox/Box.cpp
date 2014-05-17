#include "Box.h"


Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}


Date Box::GetCurrentDate(Box box)
{
	return box.currentDate;
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

bool Box::changePassword(){
	system("cls");
	cout << "Are you sure you want to change the password?\nEnter Y to yes or N to no \n";
	char ans;
	cin >> ans;
	if ('N'==ans)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	if ('Y' == ans)
	{
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		string pass;
		string new_pass;
		cout << "Enter current password:\n";
		cin >> pass;
		while (pass!=password)
		{
			cout << "Password mismatch\nRepeat password:\n";
			cin >> pass;
		}
		while (pass != new_pass)
		{
			system("cls");

			cout << "Enter new password:\n";
			cin >> pass;

			system("cls");

			cout << "Repeat the new password:\n";
			cin >> new_pass;

			if (pass != new_pass)
			{
				cout << "Password mismatch";
				Sleep(2000);
			}
		}
	}
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
	Channel new_channel = Channel(n);				// Isto dá erro
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