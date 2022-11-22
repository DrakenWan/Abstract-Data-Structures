using namespace std;

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

			friend ostream& operator<<(ostream& os, const complex& c);
};

ostream& operator<<(ostream& os, const complex& c)
{
    if(c.real != 0)
		cout<<c.real;
	
	if(c.real !=0 && c.img !=0) {
		if(c.img > 0)
			cout<<'+';
	} 
	
	if(c.img !=0) 
		cout<<c.img<<'i';
		
	if(c.img == 0 && c.real == 0)
		cout<<0;
}