// stack implementation
#include<iostream>
#include<vector>

using namespace std;

template<typename S>
class stack {
    vector<S> content;
    public:
        stack() {
        }
        stack(S value)
        {
            this.push_back(value)
        }

        void push(S value);
        S pop();
        S peek();
};

template<typename S>
void stack::push(S value)
{
 
}
int main()
{
    return 0;
}