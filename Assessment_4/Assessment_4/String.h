#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
public:

	String();  // Constructor
	String(const char* _str);  // Parameterized constructor with C-string 

	String(const String& _other);  // Copy constructor

	~String();  // Destructor


public:

	size_t Length() const;  // Calculate the length of the string
	char& CharacterAt(size_t _index);  //  Check character at a specified index in array (non-const)
	const char& CharacterAt(size_t _index) const;  // Check character at a specified index in array (const)

	bool EqualTo(const String& _other) const;  // Check if strings are equal to one another

	String& Append(const String& _str);  // Append a string to another string
	String& Prepend(const String& _str);  // Prepend a string to another string

	const char* CStr() const;  // Grab C-style string

	String& ToLower();  // Convert a string to be all lowercase
	String& ToUpper();  // Convert a string to be all uppercase

	size_t Find(const String& _str);  // Find a string within a string
	size_t Find(size_t _startIndex, const String& _str);  // Find a substring within a string, starting from the specified index

	String& Replace(const String& _find, const String& _replace);  // Replace substring

	String& ReadFromConsole();  // Read string from console
	String& WriteToConsole();  // Write string to console

public:

	bool operator==(const String& _other);  // Equality operator overload
	bool operator!=(const String& _other);  // Inequality operator overload

	String& operator=(const String& _str);  // Assignment operator overload

	bool operator<(const String& _other);  // Less than operator overload

	char& operator[](size_t _index);  // Subscript operator overload (non-const)
	const char& operator[](size_t _index) const;  // Subscript operator overload (const)


private:

	char* data; // Pointer to a dynamically allocated character array
};

#endif

