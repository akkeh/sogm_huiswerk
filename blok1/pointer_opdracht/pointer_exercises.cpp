#include <iostream>

using namespace std;


int main()
{
char letter = 97;
char *letterpointer;

  cout << "Inhoud van de variabele letter: ";
  cout << letter << endl;

  letterpointer = &letter;
  cout << "Inhoud van de pointer letterpointer: ";
  cout << (unsigned long) letterpointer << endl;

  cout << "Inhoud van waar de pointer letterpointer naar wijst: ";
  cout << *letterpointer << endl;

  *letterpointer = 'b';
  cout << "De variabele letter heeft via letterpointer een nieuwe waarde gekregen: ";
  cout << *letterpointer << endl;

  cout << "Inhoud van de variabele letter: ";
  cout << letter << endl;

  // OEFENINGEN
  unsigned short year = 2013;
  cout << "Inhoud van de variabele year: " << year << endl;
    unsigned short* year_ptr = &year;
  cout << "Inhoud van de pointer yearpointer: " << year_ptr << endl;
  cout << "Inhoud van waar de pointer yearpointer naar wijst: " << *year_ptr << endl;
  // geef year via de pointer een nieuwe waarde
   *year_ptr = 2014; 
  cout << "Inhoud van de variabele year: " <<  *year_ptr << endl;

  // maak nog een pointer genaamd anotheryearpointer en laat deze ook naar
  // year wijzen
  //anotheryearpointer = yearpointer;
    unsigned short* anotheryearpointer = &year;
  cout << "Inhoud van de pointer anotheryearpointer: " << anotheryearpointer << endl;
  cout << "Inhoud van waar de pointer anotheryearpointer naar wijst: " << *anotheryearpointer << endl;
  // geef year via de pointer een nieuwe waarde
    *anotheryearpointer = 2015;
  cout << "Inhoud van de variabele year: " << year << endl;
  cout << "Inhoud van waar de pointer yearpointer naar wijst: " << *year_ptr << endl;

} // main()

