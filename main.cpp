#include <random>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
std::random_device rd;
std::uniform_int_distribution<int> dist(0,9);
std::uniform_int_distribution<int> dist2(0,6);
int num1 = dist(rd);
int num2 = dist(rd);
int num3 = dist(rd);
int order = dist(rd);
char guesschar[3];
string response;
int i;
string a;
string b;
string c;
string ultimate = "false";
string guess;
void guess1() { 
cout << "Enter your guess: " << endl;
  cin >> guess;
if (guess.length() == 3) {
  
  for (i = 0; i < 3; i++) { 
        guesschar[i] = guess[i]; 
    }
    cout << guesschar[0] << guesschar[1] << guesschar[2] << endl;
  if (guesschar[0] == num1) {
    a = "P";
  }
  else if (guesschar[0] == num2) {
	a = "F";
  }
  else if (guesschar[0] == num3) {
	 a = "F";
  }

  else {
    a = "B";
  }
  if (guesschar[1] == num1) {
    b = "F";
  }
  else if (guesschar[2] == num1) {
    c = "F";
  }
  
  else if (guesschar[1] == num2) {
    b = "P";
  }
  else if (guesschar[1] == num3) {
    b = "F";
  }
  else if (guesschar[1] != num1 && num2 && num3) {
    b = "B";
  }
  
  else if (guesschar[2] == num2) {
    c = "F";
  }
  else if (guesschar[2] == num3) {
    c = "P";
  }
  else if (guesschar[2] != num1 && num2 && num3) {
    c = "B";
  }
  else if (order == 1) {
    response = a + b + c;
  }
  else if (order == 2) {
    response = a + c + b;
  }
  else if (order == 3) {
    response = b + a + c;
  }
  else if (order == 4) {
    response = b + c + a;
  }
  else if (order == 5) {
    response = c + b + a;
  }
  else if (order == 6) {
    response = c + a + b;
  }
  else {
    response = a + b + c;
  }
  cout << response << endl;
  if (response == "PPP") {
    ultimate = "true";
  }
 
}
else {
  cout << "Please enter a 3 digit number." << endl;
}
}
int main() {
cout << num1 << num2 << num3 << endl;
cout << "Welcome to Pico, Fermi, Bagel!" << endl;
while (ultimate == "false") {
guess1();
}
}

