#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T> class MultiplyBy
{
private:
    T _mult = 0;
    MultiplyBy();
public:
    MultiplyBy(T n): _mult(n){}
    void mult(T n) {_mult = n;}
    T mult() const {return _mult;}
    T operator() (T n) const {return _mult * n;}
};

template <typename T> void disp_v(vector<T> &v){
    if (!v.size())
    {
        return;
    }
    for (T element: v)
    {
        cout << element << ", ";
    }
    
    cout << endl;
}


int main(){
    MultiplyBy<int> x(6);
    cout << "x mult is " << x.mult() << endl;

    cout << "x(5) is " << x(5) << endl;
    cout << "x(25) is " << x(25) << endl;

    vector<long> v1 = {1,0,1,1};
    vector<long> v2 = {0,0,1,1};
    vector<long> v3(v1.size(), 0);

    // multiplies<long> f;
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);

    logical_and<long> f1;
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f1);

    disp_v(v3);
}