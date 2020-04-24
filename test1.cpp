//test1.cpp - using for_each and find 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cout;
using std::vector;
using std::find;
using std::find_if;
using std::for_each;
using std::isdigit;
using std::string;


void output_val(int v){
    cout << v << " ";
}

bool isspc(char c){
    return c == ' ';
}

//function object: overload operator()
struct is_aprox_pi{
    bool operator()(double d){
        return d >= 3.141 && d < 3.142;
    }
};

int main ()
{
    vector<int> v = { 42, 128, 995, 443, 9000, 3, 4, 5 };
    cout << "for loop with iterator: \n";

    for(auto itr = v.begin(); itr != v.end(); ++itr){
        cout<<*itr<<" ";
    }

    cout<<"\n\n";
    cout << "for_each loop a funtion: \n";
    for_each(v.begin(), v.end(), output_val);
    cout<< "\n\n";
    cout << "for_each loop with lambda expression: \n";
    for_each(v.begin(), v.end(), [](int v){
        cout << v <<" ";
    });

    cout << "\nstart loop from given value " << std::endl;
    auto iter = find(v.begin(), v.end(), 443);
    while(iter!=v.end()){
        cout<<*iter << " ";
        ++iter;
    }
    cout << "\n";

    //find_if tests
    string s = "This is just a test. 1";
    vector<double> si = { 1, 2, 3, 3.14159, 5, 6, 100 };

    //build-in function (isdigit from cctype)
//    auto r = find_if(s.begin(), s.end(), isdigit);

    auto u = find_if(s.begin(), s.end(), isspc);
    if (u != s.end())
        cout << "u: " << std::boolalpha << ((*u) == ' ') << std::endl;

    //lambda expressions
    auto l = find_if(s.begin(), s.end(), [](char c) {  
        return c == 'x';});
    
    if (l != s.end())
        cout << "l: " << *l << std::endl;

    auto z = find_if(si.begin(), si.end(), is_aprox_pi{});

    return 0;
}
