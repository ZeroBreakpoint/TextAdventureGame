#include <iostream>
#include "String.h"  // Used to include the header file
#include <cstring>  // Used for correct functionality of the classic "C style" string functions (such as strcmp, strlen etc)
#include <cctype>  // Used for correct functionality of toupper() and tolower() functions
#include <cstddef>  // Used for correct functionality of size_t
using namespace std;  // Used to help keep my code tidier and remove the need to add std:: before various ojects and functions (such as std::cin and std::cout etc)

int main() {

    String hello("Hello, ");  // Creating string 'Hello, '
    String world("World");  // Creating string 'World'
    String displayMessage("Hello, World");  // Creating string 'Hello, World'
    cout << displayMessage.CStr();  // Outputting the 'Hello, World' string  
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "The length of the 'Hello, World' string (not including the null terminator) is: " << displayMessage.Length() << endl;  // Outputting the length of the 'Hello, World' string (using the Length definition and its' contents from String.h & String.cpp)
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "Now we can test the 'characterat' function.  The character at index 7 is: " << displayMessage.CharacterAt(7);  // Outputting the character at index 7 in the 'Hello, World' string (using the CharacterAt definition and its' contents from String.h & String.cpp) 
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    if (hello.EqualTo(world)) {  // If statement to check if string 'Hello, ' is equal to string 'World' and output based on result (using the EqualTo definition and its' contents from String.h & String.cpp)
        cout << "String 1 is equal to String 2\n";
    }
    else {
        cout << "String 1 is not equal to String 2\n";
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "After using the 'append' function we have: ";
    String appended = hello.Append(world);  // Using the Append function (and its' contents from definition in String.h & String.cpp) to append the string 'World' to the string 'Hello, ' and outputting the newly created string
    appended.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "After using the 'prepend' function we have: ";
    String bang("! ");
    String prepended = appended.Prepend(bang);  // Using the Prepend function (and its' contents from definition in String.h & String.cpp) to prepend the string '! ' to the string 'Hello, World' and outputting the newly created string
    prepended.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    displayMessage.ToLower();  // Using the ToLower function (calling upon the ToLower definition and its' contents from String.h & String.cpp) to convert the 'Hello, World' string to lowercase and then outputting
    cout << "Testing of the 'ToLower' function.  String in lowercase: "; displayMessage.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    displayMessage.ToUpper();  // Using the ToUpper function (calling upon the ToUpper definition and its' contents from String.h & String.cpp) to convert the 'hello, world' string to uppercase and then outputting
    cout << "Testing of the 'ToUpper' function.  String in uppercase: "; displayMessage.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    size_t foundIndex = displayMessage.Find("RLD");  // Find the position of the substring "RLD" in the 'HELLO, WORLD' string (calling upon the Find definition and its' contents from String.h & String.cpp)
    if (foundIndex != static_cast<size_t>(-1))  // If the substring "RLD" is found in the string below code will run
    {
        cout << "Using the 'find' function to detect 'RLD' in 'HELLO, WORLD'.  'RLD' is detected to start at index location: " << foundIndex;
    }
    else // If the substring "RLD" is not found in the 'HELLO, WORLD' string the below code will run
    {
        cout << "String not found: -1";
    }
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    size_t foundIndexTwo = displayMessage.Find(3, "RLD");  // Find the pisition of the substring "RLD" in the 'HELLO, WORLD' string, starting the search from index 3 (calling upon the Find definition and its' contents from String.h & String.cpp)
    if (foundIndexTwo != static_cast<size_t>(-1))  // If the substring "RLD" is found in the string below code will run
    {
        cout << "Using the 'find from index' function to detect 'RLD' in 'HELLO, WORLD' searching only from index location 3.\n'RLD' is detected to start at index location: " << foundIndexTwo;
    }
    else  // If the substring "RLD" is not found in the 'HELLO, WORLD' string the below code will run 
    {
        cout << "String not found: -1";
    }
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    displayMessage.Replace("HELLO", "GREETINGS");  // Using the Replace function (based on the Replace definition and its' contents from String.h & String.cpp) to replace 'HELLO' (from the string 'HELLO, WORLD') with 'GREETINGS' and outputting
    cout << "After using the 'replace' function to replace the word 'HELLO' with the word 'GREETINGS', we have: " << displayMessage.CStr();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "Please enter some numbers or text to test the 'ReadFromConsole' function: ";
    String inputString;  // Creating a new uninitialised string (which will be set to whatever the user enters in the next line)
    inputString.ReadFromConsole();  // ReadFromConsole function used (by referring to its' definition and contents from String.h & String.cpp) to set whatever the user enters as the contents of string 'inputString' 
    cout << "You entered: "; inputString.WriteToConsole();  // Outputting the users string to the console using the WriteToConsole function (which draws upon the WriteToConsole definition used in String.h & String.cpp)
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    String helloTwo("Hello, ");  // Creating three new strings for a fresh slate to work with 'Hello, World' again as the original strings have been altered by the above functions
    String worldTwo("World");
    String displayMessageTwo("Hello, World");



    cout << "Now we can test the 'equality operator' function to check if 'Hello, ' is equal to 'World': " << (helloTwo == worldTwo ? "Equal" : "Not Equal") << endl;  // Using the equality operator (defined with its' contents in String.h & String.cpp) to check if 'Hello, ' string is equal to 'World' string and outputting based upon the result 
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "Testing the 'subscript operator' function to see which character is at index 4 in 'Hello, World': " << displayMessageTwo[4] << endl;  // Using the subscript operator to output the character at index 4 in the 'Hello, World' string (using its' definition and contents from String.h & String.cpp)
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    cout << "Testing the 'lessthan operator' function to check if 'Hello, ' comes before 'World' in the alphabet: " << (String(helloTwo) < String(worldTwo) ? "Yes" : "No") << endl;  // Using the less than operator (defined with its' contents in String.h & String.cpp) to check if 'Hello ' string comes before 'World' string in the alphabet and outputting based upon the result
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    system("pause");
}