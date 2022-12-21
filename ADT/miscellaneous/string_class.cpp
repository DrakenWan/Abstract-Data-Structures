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

	friend ostream& operator<<(ostream& os, String& s) {
		s.display();
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
//Function definitions for String end here //


int main() {
	
	//string s1 = "aash", s2 = "aash";
	//cout<<s1.compare(s2);
	
	String s1("hello"), s2(" "), s3("World"), s4("!");
	s1.display();
	String s5 = s1+s2+s3+s4;
	cout<<endl;
	s1.append(s2);
	cout<<s1<<s3;
	cout<<endl;
	cout<<s3[4];
	cout<<s3.size();
	return 0;
}