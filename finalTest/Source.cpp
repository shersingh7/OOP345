
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <list>
using namespace std;

struct Country
{
    std::string name;
    size_t population;  // # people living in the country
    bool accessToOcean; // true if has access to ocean
    double gdp;         // Gross Domestic Product
};

list<Country> inspectMap(vector<Country>& src)
{
    int tempCounter=0;
    //Q1
    find_if(src.begin(), src.end(), [&](const Country& c) {
        if (!c.accessToOcean) tempCounter++; });

    if (tempCounter > 0) cout << "Yes\n";
    else cout << "No\n";



    //Q2
    int tempGdp = 0;

    auto totalGdp = accumulate(src.begin(), src.end(), 0, [&](const Country & c){
            return tempGdp += c.gdp; });

    auto averageGdp = totalGdp / src.size();

    cout << "The average GDP is " << averageGdp << endl;



    //Q3
    auto temp = count_if(src.begin(), src.end(), [&](const Country& c) {
        return c.gdp < averageGdp; });

    list<Country> list(temp);
    copy_if(src.begin(), src.end(), list.begin(), [&](const Country& c) {
        return c.gdp < averageGdp; });



    //Q4
    sort(src.begin(), src.end(), [&](const Country& c, const Country& c2) {
        return c.population > c2.population; });

    //Q5
    for_each(src.begin(), src.end(), [&](const Country& c) {
        cout << c.name << ": " << c.population << endl; });


    return list;
}

int main() 
{
    


	return 0;
}