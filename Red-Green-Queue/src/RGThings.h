#include <string>
using namespace std;

enum Color {
    NONE = - 1,
    RED = 0,
    GREEN = 1
};

struct RGThing {
    Color color = Color::NONE;
    string label = "default";
};

struct RGTPair {
    RGThing thing1;
    RGThing thing2;
};

class RGThings {
    RGTPair queue[50];
    int start = 0;
    int size = 0;
    public:

    bool empty();
    void insert(RGThing newThing);
    RGTPair remove();
};