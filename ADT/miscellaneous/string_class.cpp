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

		you can access and change the internal element of the string using subscript [] operator
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

	//concatenate two strings
	String operator+(String s1);
	String operator+(char c);

	//append methods
	void append(String s) {
		this->feed.insert(this->feed.end(), s.feed.begin(), s.feed.end());
		this->_size = this->feed.size();
	}
	void append(char s) {
		this->feed.push_back(s);
		this->_size = this->feed.size();
	}


	// some operations
	String capitalize();
	String upper();
	String lower();
	bool startsWith(char val);
	bool endsWith(char val);
	vector<String> split(char separator);
	String strip();

	// operator overloads below
	friend ostream& operator<<(ostream& os, String s) {
		for(long i=0; i<s.size(); i++)
			os<<s.feed[i];
	}

	char& operator[](long idx) {
		try{
			if(idx > -1 && idx < this->size())
				return this->feed[idx];
			else if(idx >= -this->size() && idx < 0 )
				return this->feed[this->size() + idx];
			else
				throw(idx);
				
		} catch(long val) {
			cout<<"\nError: "<<val<<" index is out of range.";
		}
	}

	//String slicing
	String operator()(long,long);
};


// Function definitions for some methods

String String::operator()(long start, long end){
	String s = *this, toss;
	try{
		if(start >= end)
			throw(-1);
		if(start >= 0 && end >= 0){
			if(start >= this->size() || end >= this->size())
				throw(0);
			else {
				for(long i=start; i<end; i++)
					toss.append(s[i]);

				return toss;
			}
		}
		else if(start < 0 && end < 0) {
			if(start < -this->size() || end < -this->size())
				throw(0);
			else {
				for(long i=start; i<=end; i++)
					toss.append(s[i]);

				return toss;
			}
		}
		else throw(1);
	} //try ends
	catch(int val) {
		switch(val) {
			case 0 :
				cout<<"Index out of range.";
				break;
			case -1 :
				cout<<"Start index greater than end index.";
				break;
			case 1 :
				cout<<"Unexceptional error in slicing String.";
				break;
			default :
				cout<<"Unreadable error code thrown.";
		}
	} //catch ends
}


String String::operator+(char c) {
	String s = *this;
	s.append(c);
	return s;
}

vector<String> String::split(char separator=' ') {
    /*
		Returns a vector of Strings
		Each element of the vector is a string separated by the `separator` char
		variable which is a whitespace by default

		The separator is not included within the elements of the vector returned
	*/
	vector<String> container;
	String stringy="";
	
	for(long i=0; i<this->size(); i++) {
		if(this->feed[i] == separator ) {
			container.push_back(stringy);
			stringy = "";
		} else if(i == this->size() - 1) {
			stringy = stringy + this->feed[i];
			container.push_back(stringy);
		}
		else stringy = stringy + this->feed[i];
	 }

	 return container;
}


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
	String s = *this;
	if(s.feed[0] >= 'a' && s.feed[0] <='z')
		s.feed[0] = s.feed[0] - ('a' - 'A');
	return s;
}

String String::upper() {
	String s = *this;
	
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'a' && s.feed[i] <='z')
			s.feed[i] = s.feed[i] - ('a' - 'A');
	return s;
}

String String::lower() {
	String s = *this;
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'A' && s.feed[i] <= 'Z')
			s.feed[i] = s.feed[i] + ('a' - 'A');
	return s;
}

bool String::startsWith(char val) {
	if(this->feed[0] == val)
		return true;
	return false;
}

bool String::endsWith(char val) {
	long final_index = this->size() - 1;
	if(this->feed[final_index] == val)
		return true;
	return false;
}

//Function definitions for String end here //

int main() {
	
	//string s1 = "aash", s2 = "aash";
	//cout<<s1.compare(s2);
	
	String s1 = "Hello world!";
	//cout<<s1;
	cout<<s1;
	String s2 = s1(1,3);
	String s3 = s1(-5, -3);
	cout<<endl;
	cout<<s1(5, 10);
	String s4 = s1(5,10); cout<<endl;
	cout<<s4;
	return 0;
}