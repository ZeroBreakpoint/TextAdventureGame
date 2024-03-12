// I have changed the preprocessor definitions on my project to include _CRT_SECURE_NO_WARNINGS to allow for the classic "C style" string functions (such as strcmp, strlen etc) to run without errors / warnings


#include <iostream>
#include "String.h"  // Used to include the header file
#include <cstring>  // Used for correct functionality of the classic "C style" string functions (such as strcmp, strlen etc)
#include <cctype>  //  Used for correct functionality of toupper() and tolower() functions
#include <cstddef>  // Used for correct functionality of size_t
using namespace std;  // Used to help keep my code tidier and remove the need to add std:: before various ojects (such as std::cin and std::cout etc)


String::String()  // Constructor
{
	data = new char[1];  // Allocate memory for an empty character array
	data[0] = '\0';  // Ensure the string is null-terminated
}

String::String(const char* _str)

{
	data = new char[strlen(_str) + 1];  // Allocate memory for the string
	strcpy(data, _str);  // Copy the content of the input C-string into the new string
}

String::String(const String& _other)
{
	data = new char[_other.Length() + 1];  // Allocate memory for the new string
	strcpy(data, _other.data);  // Copy the content of the input String object into the new string
}

String::~String()
{
	delete[] data;  // Cleaning up allocated memory
}


size_t String::Length() const  // Returns an integer representing the count of characters up to the null termination character
{
	size_t length = 0;  // Initialise the string length to zero

	while (data[length] != '\0')  // While loop to keep iterating through the character array until the null terminator is found
	{
		length++;  // Increment the length for each character
	}
	return length;  // Output of length of the array (minus the null terminator)
}

char& String::CharacterAt(size_t _index)  // Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'
{
	if (_index >= Length() || _index < 0)  // If statament to check if index requested is out of bounds
	{
		return data[Length()];  // Return the null terminator if out of bounds
	}
	else
	{
		return data[_index];  // Return the character at the specified index if within bounds
	}
}

const char& String::CharacterAt(size_t _index) const  // Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'
{
	if (_index >= Length() || _index < 0)  // If statament to check if index requested is out of bounds
	{
		return data[Length()];  // Return the null terminator if out of bounds
	}
	else
	{
		return data[_index];  // Return the character at the specified index if within bounds
	}
}

bool String::EqualTo(const String& _other) const  // Returns true if str contains the same characters
{
	return strcmp(data, _other.data) == 0;  // strcmp function used to compare both strings and return if they are the same
}

String& String::Append(const String& _str)  // Adds str to the end of the string
{
	size_t oldLength = Length();  // Get the current length of the string
	char* newData = new char[oldLength + _str.Length() + 1];  // Allocate memory for the new string
	strcpy(newData, data);  // Copy the current string into the new string
	strcat(newData, _str.data);  // Join the content of the input string to the new string
	delete[] data;  // Clean up memory used by the old string
	data = newData;  // Update the pointer to the new string
	return *this;  // Return the modified string
}

String& String::Prepend(const String& _str)  // Adds str to the beginning of the string
{
	size_t oldLength = Length();  // Get the current length of the string
	char* newData = new char[oldLength + _str.Length() + 1];  // Allocate memory for the new string
	strcpy(newData, _str.data);  // Copy the content of the input string into the new string
	strcat(newData, data);  // Join the current string to the new string
	delete[] data;  // Clean up memory used by the old string
	data = newData;  // Update the pointer to the new string
	return *this;  // Return the modified string
}

const char* String::CStr() const  // Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
{
	return data;  // Return the pointer to the character array
}

String& String::ToLower()  // Convert all characters to lowercase
{
	size_t caseLength = Length();  // Get the length of the string
	for (size_t i = 0; i < caseLength; ++i)  // For loop to iterate through each character in the string
	{
		data[i] = tolower(data[i]);  // Converting each character to lowercase
	}
	return *this;  // Return the modified string
}

String& String::ToUpper()  // Convert all characters to uppercase
{
	size_t caseLength = Length();  // Get the length of the string
	for (size_t i = 0; i < caseLength; ++i)  // For loop to iterate through each character in the string
	{
		data[i] = toupper(data[i]);  // Converting each character to uppercase
	}
	return *this;  // Return the modified string
}

size_t String::Find(const String& _str)  // Returns the location of the findString. If not found, return -1
{
	char* found = strstr(data, _str.data);  // Search for the substring (_str) in the string
	if (found != nullptr)
	{
		return found - data;  // If the substring is found, calculate and return the index where it starts
	}
	else
	{
		return -1;  // Return -1 if the substring is not found
	}
}

size_t String::Find(size_t _startIndex, const String& _str)  // Returns the location of the strToFind. Beginning the search from startIndex. If not found, return -1
{
	const char* strToFind = _str.CStr();  // Get the C-style string to find
	size_t length = Length();  // Get the length of the string
	if (_startIndex >= length)  // If statement to check if starting index is out of bounds
		return static_cast<size_t>(-1);  // Return -1 if the start index is out of bounds

	char* found = strstr(data + _startIndex, strToFind);  // Search for the substring from the start index
	if (found != nullptr)
	{
		return found - data;  // Calculate the index of the found substring
	}
	return static_cast<size_t>(-1);  // Return -1 if the substring is not found
}

String& String::Replace(const String& _find, const String& _replace)  // Replaces all occurrences of findString with replaceString
{
	size_t found = Find(_find);  // Find the position of the substring to replace
	while (found != string::npos)  // While loop until the substring is not found
	{
		string temp(data);  // Create a temporary string from the current string
		temp.replace(found, _find.Length(), _replace.data);  // Replace the substring in the temporary string
		*this = temp.c_str();  // Update the current string with the modified temporary string
		found = Find(_find);  // Find the position of the substring to replace again
	}
	return *this;  // Return the modified string
}

String& String::ReadFromConsole()  // Wait for input in the console window and store the result
{
	const int bufferSize = 1024;  // Initialising the size of the input buffer
	char buffer[bufferSize];  // Creating an input buffer
	cin.getline(buffer, bufferSize);  // Grabs input from console and puts into the buffer
	*this = buffer;  // Update the current string with the content of the buffer
	return *this;  // Return the modified string
}

String& String::WriteToConsole()  // Write the string to the console window
{
	cout << data;  // Output the content of the string to the console
	return *this;  // Return the string
}

bool String::operator==(const String& _other)  // Returns true if lhs == rhs
{
	return EqualTo(_other);  // Checks if the content of two strings are the same (using the previously defined EqualTo function)
}

bool String::operator!=(const String& _other)
{
	return !EqualTo(_other);  // Checks if the content of two strings are not the same (using the previously defined EqualTo function)
}

String& String::operator=(const String& _str)  // Replaces the characters in lhs with the characters in rhs
{
	if (this != &_str)  // Check for self-assignment
	{
		delete[] data;  // Cleaning up memory used by the old string
		data = new char[_str.Length() + 1];  // Allocate memory for the new string
		strcpy(data, _str.data);  // Copy the content of the input string into the new string
	}
	return *this;  // Return the modified string
}

bool String::operator<(const String& _other)  // Returns true if this string comes before rhs in the alphabet
{
	return strcmp(data, _other.data) < 0;  // Compares the content of two strings alphabetically
}


char& String::operator[](size_t _index)  // Returns the character located at position n (non-const)
{
	return CharacterAt(_index);  // Return the character at the specified index in the string
}

const char& String::operator[](size_t _index) const  // Returns the character located at position n (const)
{
	return CharacterAt(_index);  // Return the character at the specified index in the string
}