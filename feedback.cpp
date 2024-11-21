#include "feedback.h"
#include "operations.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// function to add feedback
void feedback::add_feedback(string user_name, string resturant_name) {
  ofstream output("feedbacks.txt", ios::app);
  cout << "Enter Feedback: ";
  getline(cin >> ws, feedback);
  if (output.is_open()) {
    output << "- user name: "<< user_name << " - resturant name: " << resturant_name << " - " << feedback << " - # -" << endl;
    cout << "Feedback added successfully." << endl;
    output.close();
  } else {
    cout << "Error: Unable to open file for writing." << endl;
  }
}