#include <random>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
/* Declaring all the variables */
/* Random number generators: */
std::random_device rd;
std::uniform_int_distribution<int> dist(0,9);
std::uniform_int_distribution<int> dist2(0,6);
std::uniform_int_distribution<int> dist3(1, 6);
/* Digits of target number, which are converted to strings so they can be used to compare: */
string num1 = to_string(dist3(rd));
string num2 = to_string(dist(rd));
string num3 = to_string(dist(rd));
/*  Random integer that decides order of output letters: */
int order = dist(rd);
/* Individual characters of guess: */
string digit1;
string digit2;
string digit3;
/* Response string: */
string response;
/* Integer used to split guess: */
int i;
/* Strings where letters are stored: */
string a;
string b;
string c;
/* String that ends game if true: */
string ultimate = "false";
/* String that stores raw guess*/
string guess;
/* Integer that stores how many attempts it took to guess the number right: */
int attempts;
/*Functions that check for each digit*/
void char1() {
	if (digit1 == num1) {
		a = "P";
	}
	else if (digit1 == num2) {
		a = "F";
	}
	else if (digit1 == num3) {
		a = "F";
	}

	else {
		a = "B";
	}
}
void char2() {
	if (digit2 == num1) {
		b = "F";
	}
	else if (digit2 == num2) {
		b = "P";
	}
	else if (digit2 == num3) {
		b = "F";
	}

	else {
		b = "B";
	}
}
void char3() {
	if (digit3 == num1) {
		c = "F";
	}
	else if (digit3 == num2) {
		c = "F";
	}
	else if (digit3 == num3) {
		c = "P";
	}

	else {
		c = "B";
	}
}
/* Main Function that prompts for guess and checks digits*/
void guess1() { 
	/* Asks user for input: */
cout << "Enter your guess: " << endl;
  cin >> guess;
  /* Checks if input is three characters: */
  if (guess.length() == 3) {
	/* Assigns each character of the guess to a seperate string: */
	  digit1 = guess[0];
	  digit2 = guess[1];
	  digit3 = guess[2];
	  /* Calls functions that check digits and output letters: */
	  char1();
	  char2();
	  char3();
	  /* Using the random integer order it randomly picks one of 6 different ways to output the letters: */
	  if (order == 1) {
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
	  /* If you get a PPP, it sets the string ultimate to be "true" which will end the game when it is checked in the while loop in the main function: */
	  if (response == "PPP") {
		  ultimate = "true";
	  }
  }
  /* If you don't enter three characters it will show you this message: */
  else {
	  cout << "Please enter a 3 digit number" << endl;
  }
}

/* Main function that runs on startup: */
int main() {
cout << "Welcome to Pico, Fermi, Bagel!" << endl;
/* Keeps calling guess function until the string ultimate is set to true: */
while (ultimate == "false") {
guess1();
/* Adds 1 to the integer attemps every time the loop runs: */
attempts++;
}
/* Outputs a victory message along with attempts: */
cout << "You guessed the number correctly! It took you " << attempts << " attempts." << endl;
}

