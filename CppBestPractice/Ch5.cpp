#include <iostream>
#include <string>
using namespace std;


class Resource
{
private:
    int resourceId;
public:
    Resource(int resourceId) : resourceId(resourceId){
        cout << "Create a resource with Id: " << resourceId << endl;
    }
    ~Resource(){
        cout << "Destructor on resource with Id: " << resourceId << endl;
    }
};

void showResult(bool isThrowException){
    Resource r1(20);
    Resource r2(30);

    if (isThrowException)
    {
        throw runtime_error("This a demo exception");
    }
    cout << "Finish demo" << endl;
}

int main(){
    try
    {
        showResult(true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}