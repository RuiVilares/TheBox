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



float Box::moneySpent(){
	float totalCost = 0;

	for (int i = 0; i < seenMovies.size(); i++)
	{
		totalCost = totalCost + seenMovies[i].getCost();
	}
	return totalCost;
}

int Box::timesWhatched(string &title){
	for (int i = 0; i < seenMovies.size(); i++)
	{
		if (title == movieClub[i].getTitle())
		{
			return movieClub[i].getTimesRented();
		}
	}
}







// Channel CRUD


bool Box::createdChanel(){
	return true;

}
