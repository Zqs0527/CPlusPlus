#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T> class accum
{
private:
    T _acc = 0;
    accum(){}
public:
    accum(T n): _acc(n){}
    T operator() (T y) {_acc+=y;return _acc;}
};

template <typename T> void disp_v(vector<T> & v){
    if (!v.size())
    {
        return;
    }
    for (T element: v)
    {
        cout << element << " ";
    }
    
    cout << endl;
}
static int number = 6;

int accumulate(int &i){
    return number += i;
}

int main(){
    int firstElement = 6;
    /*
    Lambda function
    */
    auto secondElement = [firstElement](int d) mutable -> int {return firstElement += d;};

    accum<int> x(17);
    cout << x(2) << endl;

    vector<int> v1 = {1,2,3,4,5};
    disp_v(v1);

    vector<int> v2(v1.size());
    transform(v1.begin(),v1.end(),v2.begin(),x);

    vector<int> v3(v1.size());
    transform(v1.begin(), v1.end(), v3.begin(), accumulate);
    
    disp_v(v3);

    disp_v(v2);
    return 0;
}