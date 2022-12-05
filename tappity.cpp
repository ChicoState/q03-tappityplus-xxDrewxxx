#include "tappity.h"
#include <cmath>
/**
 * Class for tappity
**/
#include<iostream>
#include<string.h>
using namespace std;

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  referenceTap = reference;
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  inputTap = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  return std::abs((int)referenceTap.length() - (int)inputTap.length());
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  
  int exact = 0;
  int max = std::max(referenceTap.length(), inputTap.length());
  int min = std::min(referenceTap.length(), inputTap.length());

  if (referenceTap == "" && inputTap == "") {
    return 100;
  }

  for (int x = 0; x < min; x++) {
    if (referenceTap[x] == inputTap[x]) {
      exact++;
    }
  }

  return (exact/double(max))*100.0;

}

//  docker run --mount type=bind,source="C:\Users\andre\CSCI430\TappityPlus/",target=/usr/src -it gtest sh
//  docker run --mount type=bind,source="C:\Users\andre\School\CSCI430\tappityPro/",target=/usr/src -it gtest sh