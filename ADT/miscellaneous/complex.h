using namespace std;

namespace adt {
class complex {
	
		double real, img;
		
		public:
			
			complex() {
				this->real = 0;
				this->img = 0;
			}
			
			complex(double real) {
				this->real = real;
				this->img = 0;
			}
			
			complex(double real, double img) {
				this->real = real;
				this->img = img;
			}
			
			void display() {
				
				if(this->real != 0)
					cout<<this->real;
				
				if(this->real !=0 && this->img !=0) {
					if(this->img > 0)
						cout<<'+';
				} 
				
				if(this->img !=0) 
					cout<<this->img<<'i';
					
				if(this->img == 0 && this->real == 0)
					cout<<0;
			}
			
			void change(double val, bool isReal=true) {
				if(isReal)
					this->real =  val;
				else
					this->img = val;
			}

			//operator overloading for some operations
			complex operator+(complex c1);
			complex operator-(complex c1);
			complex operator*(complex c1);
			complex operator/(complex c1);
			double operator[](int index);
			bool operator==(complex c1);
			friend ostream& operator<<(ostream& os, const complex& c);
};


complex complex::operator+(complex c1) {
	complex c;
	c.real = this->real + c1.real;
	c.img = this->img + c1.img;
	return c;
}

complex complex::operator-(complex c1) {
	complex c;
	c.real = this->real - c1.real;
	c.img = this->img - c1.img;
	return c;
}

complex complex::operator*(complex c1) {
	complex c;
	c.real = this->real * c1.real + (-1) * (this->img * c1.img);
	c.img = this->img * c1.real + this->real * c1.img;
	return c;
}

complex complex::operator/(complex c1) {
	complex c;
	double denom = c1.real*c1.real + c1.img*c1.img;
	c1.change(-c1.img, false);
	c.real = this->real * c1.real + (-1) * (this->img * c1.img);
	c.img = this->img * c1.real + this->real * c1.img;

	c.real /= denom;
	c.img /= denom;

	return c;
}

bool complex::operator==(complex c1) {
	if(c1.img == this->img && c1.real == this->real)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const complex& c)
{
    if(c.real != 0)
		os<<c.real;
	
	if(c.real !=0 && c.img !=0) {
		if(c.img > 0)
			os<<'+';
	} 
	
	if(c.img > 1) 
		os<<c.img<<'i';
	else if(c.img == 1 )
		os<<'i';
	else if(c.img == -1)
		os<<"-i";
	else if(c.img < 0)
		os<<c.img<<'i';

	if(c.img == 0 && c.real == 0)
		os<<0;
}

double complex::operator[](int index) {
	try {
		switch(index) {
			case 0 :
				return this->real;
			case 1 :
				return this->img;
			default :
				throw(index);
		}
	} catch(int num) {
		cout<<"index "<<num<<" not in range. Accepted values: 0 (real) and 1 (imaginary).";
	}
}
} 