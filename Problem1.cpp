

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// Pseudocode
// Algorithm MagicIndex(A[0..n-1])
// Inputs: array A of size n to be analyzed
// Outputs: integer j, representing the magic index, or -1 if none found
//  j <- 0
//  while j<=n-1 do
//      else if A[j]=j
//          return j
//      else if A[j]<j
//          j <- j + 1
//      else
//          j <- A[j]
//  return -1

int main() {

    int j = 0;
    int temporaryValue;

    std::string temporaryString;
    std::string noMagicIndex = "None";
    std::ifstream inFile("inputFile.txt");
    std::string arrayAString = "-10 -5 0 3 7";
    std::stringstream ss;
    int  arrayA[100];

    // while (inFile.good() && !inFile.eof()) {
        ss.str (arrayAString);    

        while (j < 99) {
            ss >> temporaryString;
            arrayA[j] = std::stoi (temporaryString);
            j++;
        }

        for (int i = 0; i <= j; i++) {
            std::cout << arrayA[i] << "\n";
        }

    // }
}