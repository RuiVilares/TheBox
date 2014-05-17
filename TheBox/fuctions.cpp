#include "fuctions.h"




void RentMovie()
{
	// Completar depois
}

void ListNeverSeen()
{
	// Completar
}

void ListPreviouslySeen()
{
	// Completar
}

void MoneySpent()
{
	// Completar
}

void saveChannels(vector<Channel> &channels){
	ofstream channels_file;
	channels_file.open("Info\\Channels.txt");

	for (int i = 0; i < channels.size(); i++)
	{
		vector<Program> program_list;
		program_list = channels[i].getPrograms();
		
		channels_file << endl << channels[i].getName();
		channels_file << endl << program_list.size();

		for (int k = 0; k < program_list.size(); k++)
		{
			channels_file << endl << program_list[k].getName();
		}
	}
	channels_file.close();
}

void loadConfigs(){

}