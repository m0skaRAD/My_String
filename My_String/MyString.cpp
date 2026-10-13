#include "MyString.h"
#include <iostream>
#include <cstring>;
using namespace std;

MyString::MyString()
{
	_length = 0;
	_text = nullptr;
}

MyString::MyString(const char* text)
{
	_length = strlen(text);
	_text = new char[_length + 1];
	strcpy_s(_text, _length + 1, text);

}

void MyString::print()
{
	cout << _text;
}

size_t MyString::getLength()
{
	return _length;
}

bool MyString::isEmpty()
{
	if (_length == 0) {
		return true;
	}
	else {
		return false;
	}
	
}

void MyString::clear()
{
	_length = 0;
	delete[] _text;
	_text = nullptr;
}

char MyString::getAt(size_t index)
{
	if (index >= _length) {
		cout << "Out of range";
		return '\0';
	}
	return _text[index];
}

void MyString::setAt(size_t index, char ch)
{
	if (index >= _length) {
		cout << "Out of range";
		return;
	}
	_text[index] = ch;
}

int MyString::compare(const MyString& other) const
{
	int i = 0;
	while (_text[i] != '\0' && _text[i] == other._text[i]) {
		i++;
	}
	return _text[i] - other._text[i];
}

void MyString::append(const MyString& other)
{
	char* buff = new char[_length + other._length + 1];
	for (int i = 0; i < _length; i++) {
		buff[i] = _text[i];
	}
	for (int i = _length; i < _length + other._length; i++) {
		buff[i] = other._text[i-_length];
	}
	buff[_length + other._length] = '\0';
	_length += other._length;
	delete[] _text;
	_text = buff;
}

int MyString::find(char ch)
{
	for (int i = 0; i < _length; i++) {
		if (_text[i] == ch) {
			return i;
		}
	}
	return -1;
}

void MyString::toUpper()
{
	for (int i = 0; i < _length; i++) {
		if (_text[i] <= 122 && _text[i] >= 97) {
			_text[i] -= 32;
		}
	}
}

MyString::~MyString()
{
	delete[] _text;
}


