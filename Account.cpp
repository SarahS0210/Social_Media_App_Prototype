// You shall implement the member functions of the Account class in this file. 
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "Account.h"
using namespace std;

Account::Account(const string& username){
  //Generates number of characters
  nFollowing_ = 0;
  int characters = rand()%5 + 8;
  char password[characters];
  char temp = 0;
  int place = 0;
  int place2 = 0;
  char letter = 0;
  string valid = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ#$%&";
//Sets user's inputted name as username_
  username_ = username;
   //Places special characters
  place = rand()%characters;
  temp = rand()%3; // You can never generate 3 with this.
	// rand() % 4 could give you 0, 1, 2, or 3.
  if (temp == 0){
    letter = '#';
  }
  else if(temp == 1){
    letter = '$';
  }
  else if(temp == 2){
    letter = '%';
  }
  else if(temp == 3){
    letter = '&';
  }
  password[place] = letter;

   //Places a Number
  place2 = rand()%characters;
  temp = rand()%9; // gives 0 - 8 but as a number, not a character.
  password[place2] = temp + '0';
  
  //Generates remaining characters
  for (int i = 0; i<characters; i++){
    int generated;
    generated = rand()%65;
    if (i == place || i == place2){
    }
    else password[i] = valid[generated];
  }
  //Puts array into string
  for(int i = 0; i<characters; i++){
    password_ = password_ + password[i];
  }

	
}

//Accessors
string Account::get_following(const string& key) const{
  int find = -1;
  string follower_list;
  for (int i = 0; i<nFollowing_; i++){
    if (key == ""){
    follower_list = follower_list + following_[i] + ", ";
    }
    else find = following_[i].find(key);
    if (find != -1){
      follower_list = follower_list + following_[i] + ", ";
    }
  }
  return follower_list;
}

string Account::to_string() const{
  stringstream account_info;
  account_info << "The user " << username_ << " has " + password_ << " as their password and is following " << nFollowing_<< " account (s)." << endl;
  return account_info.str();
}

// Mutators
bool Account::follow(const string& username){
  int find = -1;
  for (int i = 0; i <= nFollowing_; i++){
    if (following_[i].find(username) != string::npos) {
      find = i;
      break;
    }
  }
  
  if (find != -1){
    cout << "You are already following " << username << endl;
    return false;
  }
  else{
    nFollowing_++;
    following_[nFollowing_-1] = username;
    cout << username << " successfully followed" << endl;
    return true;
    }
}

bool Account::unfollow(const string& username){
    int find = -1;
    for (int i = 0; i < nFollowing_; i++){
      if (following_[i].find(username) != string::npos) {
        find = i;
        break;
      }
    }
    if (find == -1){
      cout << "You are not following " << username << endl;
      return false;
    }
    else{
      for (int i = find; i<nFollowing_-1; i++){
        following_[i] = following_[i + 1];
      }
      nFollowing_--;
      cout << username << " successfully removed from following list" << endl;
      return true;
   }
}