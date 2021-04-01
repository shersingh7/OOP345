#include <iostream>
#include <cstring>

using namespace std;
struct Indicator
{
    int id;
    char ledColour;
};

class ControlPanel
{
    struct Indicator* ptr = NULL;
    unsigned int num = 0;

public:

    ControlPanel() {}

    ControlPanel(int* id, char* ledColour, unsigned int len = 0)
    {
        if ((id == NULL || ledColour == NULL) && (id != NULL || ledColour != NULL))
        {
            throw invalid_argument("invalid argument");
        }

        this->num = len;
        ptr = new struct Indicator[len];

        for (int i = 0; i < len; i++)
        {
            ptr[i].id = id[i];
            ptr[i].ledColour = ledColour[i];
        }
    }

    void changeLED(int id, char colour)
    {
        int i;
        if (ptr == NULL) exit(40);
        for (i = 0; i < num; i++)
        {
            if (ptr[i].id == id)
            {
                ptr[i].ledColour = colour;
                break;
            }
        }
        if (i == num)
        {
            throw "LED not found!";
        }
    }

    int countRedLED()
    {
        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (ptr[i].ledColour == 'r')count++;
        }
        return count;
    }

    ~ControlPanel()
    {
        delete[]ptr;
    }

};



int main()
{
    int a[] = { 1,2,3 };
    char b[] = { 'r','g','g' };

    try {
        ControlPanel obj(a, b, 3);
        cout << obj.countRedLED() << endl;
        obj.changeLED(2, 'r');
        cout << obj.countRedLED() << endl;
    }
    catch (const char* e)
    {
        cout << e;
    }

    return 0;
}

