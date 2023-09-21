/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
using namespace sdds;
using namespace std;

void FirstTen(TextFile T);
void Copy(const string &dest, const string &source);
void Dump(const string &filename);

int main()
{
   TextFile Empty;                           // Create an empty TextFile object
   TextFile BadFilename("badFilename");      // Create TextFile obj with a bad name
   Copy("echoes.txt", "echoesOriginal.txt"); // Copy echoesOriginal to echoes
   Copy("seamus.txt", "seamusOriginal.txt"); // Copy seamusOriginal to seamus

   TextFile E;               // Create an empty TextFile object
   TextFile S("seamus.txt"); // Create a TextFile object using seamus.txt

   cout << "Type echoes.txt and hit <ENTER>" << endl;
   cout << "Enter the text file name: ";

   cin >> E;          // Read filename from the user and store it in TextFile E
   cout << E << endl; // Print the contents of TextFile E
   cout << S << endl; // Print the contents of TextFile S

   FirstTen(E); // Call FirstTen function with TextFile E as an argument
   FirstTen(S); // Call FirstTen function with TextFile S as an argument

   E = S; // Assign the contents of TextFile S to TextFile E

   cout << E << endl; // Print the contents of TextFile E
   cout << "============================================================" << endl;

   Dump("echoes.txt");                                 // Print the contents of echoes.txt
   Dump("seamus.txt");                                 // Print the contents of seamus.txt
   Dump("C_echoes.txt");                               // Print the contents of C_echoes.txt
   Dump("C_seamus.txt");                               // Print the contents of C_seamus.txt
   cout << "*" << Empty << BadFilename << "*" << endl; // Print the contents of Empty and BadFilename TextFile objects

   return 0;
}

void FirstTen(TextFile T)
{
   if (T)
   {                                                           // Check if TextFile T is valid (not empty)
      cout << ">>> First ten lines of : " << T.name() << endl; // Print the name of TextFile T
      for (unsigned i = 0; i < 10; i++)
      {
         cout << (i + 1) << ": " << T[i] << endl; // Print each line of TextFile T
      }
   }
   else
   {
      cout << "Nothing to print!" << endl; // Print a message indicating that there is nothing to print
   }
   cout << endl
        << "-------------------------------------------------------------" << endl;
}

void Dump(const string &filename)
{
   cout << "DUMP---------------------------------------------------------" << endl;
   cout << ">>>" << filename << "<<<" << endl;
   ifstream fin(filename.c_str()); // Open the file with the given filename
   char ch;
   while (fin.get(ch))
      cout << ch; // Read and print each character from the file
   cout << endl
        << "-------------------------------------------------------------" << endl;
}

void Copy(const string &dest, const string &source)
{
   ifstream fin(source.c_str()); // Open the source file
   ofstream fout(dest.c_str());  // Create or overwrite the destination file
   char ch;
   while (fin.get(ch))
      fout << ch; // Read each character from the source file and write it to the destination file
}
