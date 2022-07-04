#include <iostream>
#include <string>


using namespace std;

class GymMembership
{
  public:
    GymMembership();
    void create(int inputId, string name);
    void deleteId(int inputId);
    void extend(int id, int n);
    void cancel(int id);
    int getId(){return id;};
  private:
    int id;
    string name;
    int months;
  
};

GymMembership::GymMembership()
{
 
}

void GymMembership::create(int inputId, string UserName)
{
  id = inputId;
  name = UserName;
  months = 0;
  cout << "Member " << inputId << " : " << name  << ", subscription valid for " << months << " months" << endl;
  
}

void GymMembership::deleteId(int inputId)
{
  id = -1;
  name = "none";
  months = -1;
  cout << "done" << endl;
}

void GymMembership::extend(int id, int n)
{
  months = n;
  cout << "Member" << id << " : " << name << ", subscription valid for " << months << " months" << endl;
}

void GymMembership::cancel(int id)
{
  months = 0;
  cout << "Member" << id << " : " << name << ", subscription valid for " <<   months << " months" << endl;
}
  
// example input

// create 7 John Doe
// create 8 Jane Doe
// extend 7 6
// extend 8 12
// cancel 8
// delete 7
// quit

// example output

// No members in the system
// Member 7 : John Doe, subscription valid for 0 months
// Member 7 : John Doe, subscription valid for 0 months
// Member 8 : Jane Doe, subscription valid for 0 months
// Member 7 : John Doe, subscription valid for 6 months
// Member 8 : Jane Doe, subscription valid for 12 months
// Member 7 : John Doe, subscription valid for 6 months
// Member 8 : Jane Doe, subscription valid for 0 months
// Member 8 : Jane Doe, subscription valid for 0 months

int main() {
  GymMembership PlanetFitness[10]; 
  string command;
  int in; 
  string soundPeopleGetYourAttentionWith;
  int monthsYouPromisedToWorkOutButWon_t;
  int location;
  while (command != "quit")
  {
    cout << "What would you like to do?: " << endl;
    getline(cin,command);
    if(command.find("create") < command.length())
    {
      command.erase(0, command.find(' ') + 1);
      in = stoi(command.substr(0, command.find(' ')));
      soundPeopleGetYourAttentionWith = command.substr(command.find(' '));
      
      PlanetFitness[location].create(in, soundPeopleGetYourAttentionWith);
    }

    if(command.find("delete") < command.length()) 
    {
      in = stoi(command.substr(command.find(' ')));

      for(int x = 0; x < 10; x++)
      {
        if(in == PlanetFitness[x].getId())
        {
          location = x;
        }
      }
      
      PlanetFitness[location].deleteId(in);
    }

    if(command.find("extend") < command.length())
    {
      command.erase(0, command.find(' ') + 1);
      in = stoi(command.substr(0, command.find(' ')));
      monthsYouPromisedToWorkOutButWon_t = stoi(command.substr(command.find(' ')));

        for(int x = 0; x < 10; x++)
      {
        if(in == PlanetFitness[x].getId())
        {
          location = x;
        }
      }
      
        PlanetFitness[location].extend(in, monthsYouPromisedToWorkOutButWon_t);
    }

    if(command.find("cancel") < command.length())
    {
      in = stoi(command.substr(command.find(' ')));

      for(int x = 0; x < 10; x++)
      {
        if(in == PlanetFitness[x].getId())
        {
          location = x;
        }
      }
      
      PlanetFitness[location].cancel(in);
    }
    // handle the command
  }
  return 0;
}

// int u=8;
// int location;
// for(int x=0; x<10; x++)
//   {
//     if(u==PlanetFitness[x].getID())
//     {
//       loca
//     }
//   }