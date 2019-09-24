#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include "dataEntry.h"
#include "dataLookup.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc;

int main()
{
    //cgi object
    Cgicc cgi;
    //main
    //gets info from web page
    form_iterator itts = cgi.getElement("type_select");
    form_iterator itname = cgi.getElement("name");
    //gets the parameters from web page
    string type = **itts;
    string name = **itname;
    //passes input file name to dataLookup constructor, constructs the map indexed by PID
    string fileName = "input.txt";
    dataLookup ourMap(fileName);
    //create year and name maps used for user lookup
    ourMap.createYearAndNameMaps();
    //allows user to repeat
    //bool repeat = true;
    //while (repeat)
        //{
        vector<dataEntry> characters;
        characters = ourMap.userSearch(type, name);
        ourMap.readMatches(characters);
        //cout << "Enter 0 and press return to quit. Enter any other character to search again" << endl;
        //char repeatChar;
        //cin >> repeatChar;
        //if (repeatChar == '0')
           // {
           // repeat = false;
           // }
        //}
return 0;
}





