
#include <iostream>
using namespace std;

class Vector { public:
    Vector(int s) :elem{new double[s]}, sz{s}
    // constructor: acquire resources
    {
        // initialize elements
        for (int i=0; i!=s; ++i)
            elem[i]=0;
    }
    // destructor: release resources
    ~Vector() { delete[] elem; }

    double& operator[](int i);
    int size() const;

private:
    double* elem; // elem points to an array of sz doubles
    int sz;
};

int main(int argc, const char * argv[]) {
    Vector v(10);
    cout << v.size();
}
