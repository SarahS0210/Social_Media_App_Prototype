// This program shall test your implementation of the Account abstract data type
// Ensure that you showcase your code works in many/all possible scenarios.
// Try to build something that could be useful for managing accounts in a social media app.
#include <iostream>
#include "Account.h"
using namespace std;

int main() {
  srand(time(NULL)*rand());
  string username;
  int option = 0;
  string key;

cout << "Please enter your username" << endl;
  getline(cin, username);
Account a(username);

bool menu_operator = true;
do{
  cout << "Please choose from the menu" << endl;
  cout << "1. Follow a user\n2. Unfollow a user\n3. Show total people following\n4. Show People following with a key term\n5. Account Info\n6. Log out/Quit" << endl;
  cin >> option;
  switch(option){
    case 1:
      cout << "insert a username you would like to follow" << endl;
      cin.ignore();
      getline(cin, username);
      a.follow(username);
    break;
    case 2:
      cout << "insert a username you would like to unfollow" << endl;
      cin.ignore();
      getline(cin, username);
      a.unfollow(username);
    break;
    case 3:
      cout << a.get_following() << endl;; 
    break;
    case 4:
      cout << "Please insert your characters you would like to filter by" << endl;
      cin.ignore();
      getline(cin, key);
      cout << a.get_following(key) << endl;
    break;
    case 5:
      cout << a.to_string() << endl;
    break;
    case 6:
      menu_operator = false;
    break;
    }
  } while(menu_operator);
	return 0;
}