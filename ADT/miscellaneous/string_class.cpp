#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

class String
{
	/*
	
		My own implementation of String type
		The inernal data structure of string makes use of std::vector
		and its operations
	*/
	vector<char> feed;
	long _size;
	
	public:
	String() {
		this->_size = this->feed.size();
	}

	String(long _size) {
		this->feed.reserve(this->_size);
		this->_size = _size;
	}

	String(vector<char> feed) {
		this->feed = feed;
		this->_size = this->feed.size();
	}
	//operations


	String(const char* str) {
		for(auto *i=str; *i!='\0'; i++)
			this->feed.push_back(*i);
		this->_size = this->feed.size();
	}

	String(const String &s) {
		this->feed = s.feed;
		this->_size = this->feed.size();
	}


	// display values
	void display() {
		for(auto i=this->feed.begin(); i!=this->feed.end(); ++i)
			cout<<*i;
	}

	long size(){return this->_size;}


	//operator overloads and operations
	char operator[](long idx) {
		try{
			if(idx < 0 || idx >= this->size())
				throw(idx);
			else
				return this->feed[idx];
		} catch(long val) {
			cout<<"\nError: "<<val<<" index is out of range.";
		}
	}

	//concatenate two strings
	String operator+(String s1);
	
	void append(String s) {
		this->feed.insert(this->feed.end(), s.feed.begin(), s.feed.end());
	}


	// some operations
	String capitalize();
	String upper();
	String lower();

	friend ostream& operator<<(ostream& os, String s) {
		for(long i=0; i<s.size(); i++)
			os<<s.feed[i];
	}
};


// Function definitions for some methods
String String::operator+(String s1) {
	//O(n) 
	// currently searching ways for efficient concatenation
	// if possible might change entire data structure for string
	// to accomodate for good concatenation
	String s;
	s.feed.insert(s.feed.end(), this->feed.begin(), this->feed.end());
	s.feed.insert(s.feed.end(), s1.feed.begin(), s1.feed.end());
	return s;
}

String String::capitalize() {
	String s(this->feed);
	if(s.feed[0] >= 'a' && s.feed[0] <='z')
		s.feed[0] = s.feed[0] - ('a' - 'A');
	return s;
}

String String::upper() {
	String s(this->feed);
	
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'a' && s.feed[i] <='Z')
			s.feed[i] = s.feed[i] - ('a' - 'A');
	return s;
}

String String::lower() {
	String s = this->feed;
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'A' && s.feed[i] <= 'Z')
			s.feed[i] = s.feed[i] + ('a' - 'A');
	return s;
}

//Function definitions for String end here //



int main() {
	
	//string s1 = "aash", s2 = "aash";
	//cout<<s1.compare(s2);
	
	String s1 = "hello";
	cout<<s1;

	String s2 = s1.upper();
	cout<<s2;
	return 0;
}