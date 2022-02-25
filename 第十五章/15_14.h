#include <iostream>
#include <string>

using namespace std;

class base {
   public:
    base(string str) : basename(str) {}
    string name() { return basename; }
    virtual void print(ostream& os) {
        os << basename << endl;
    }

   private:
    string basename;
};
class derived : public base {
   public:
    derived(string str) : base(str) { i++; }
    void print(ostream& os) {
        base::print(os);
        os << i << endl;
        ;
    }

   private:
    static int i;
};

int derived::i = 0;