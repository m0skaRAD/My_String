#pragma once
class MyString
{
	char* _text;
	int _length;
public:
	MyString();
	MyString(const char* text);
	
	void print();
	size_t getLength();
	bool isEmpty();
	void clear();
	char getAt(size_t index);
	void setAt(size_t index, char ch);
	int compare(const MyString& other) const;
	void append(const MyString& other);
	int find(char ch);
	void toUpper();

	~MyString();
};

