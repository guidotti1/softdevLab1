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
    form_iterator itcharNumber = cgi.getElement("charNumber");
    //gets the parameters from web page
    string type = **itts;
    char ctype = type[0];
    string name = **itname;
    string charNumber = **itcharNumber;
    int charNumInt;
    istringstream iss(charNumber);
    iss >> charNumInt;
    //passes input file name to dataLookup constructor, constructs the map indexed by PID
    string fileName = "guidotti1_input.txt";
    dataLookup ourMap(fileName);
    //create year and name maps used for user lookup
    ourMap.createYearAndNameMaps();
    
    vector<dataEntry> characters;
    //we read matches for a name/year if the user hasn't selected a specific character,i.e. we haven't read matches
    characters = ourMap.userSearch(ctype, name);
    if (charNumInt == 0)
    {
        ourMap.readMatches(characters);
    }
    else
    {
        cout<<characters[charNumInt-1];
    }

return 0;
}





