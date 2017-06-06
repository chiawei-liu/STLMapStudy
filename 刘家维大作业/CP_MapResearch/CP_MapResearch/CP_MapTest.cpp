#include"CP_MapTest.h"

void mapTest()
{
	// Some test of initialization
	map<int, string> mapTest;
	map<int, int> map1;
	map<int, double> map2;
	


	// Initialization
	cout<<"A map has been initialized: "<<endl;
	map<string, double> studentScore;
	printMap(studentScore);
	cout<<endl;

	// Insert new pairs
	mapInsertTest(studentScore);

	// Find and get values: find() v.s. at() v.s. operator[]
	mapFindTest(studentScore);

	// Insert repeated key: insert() v.s. operator[] v.s. emplace()
	mapInsertRepeatedKeyTest(studentScore);

	// Modify keys of existing pairs
	mapKeyModifyTest(studentScore);

	// Modify values of existing pairs
	mapValueModifyTest(studentScore);

	// Delete pairs and the map
	mapDeleteTest(studentScore);
}



void mapInsertTest(map<string, double> &studentScore)
{
	cout<<"Insert 3 pairs by 3 different ways."<<endl;
	studentScore.insert(pair<string, double>("Andy", 97.8)); //Student Andy got 97.8
	studentScore["Tony"] = 95.6;  //Student Tony got 95.6
	studentScore.emplace("Sean", 80.0);
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}


void mapFindTest(map<string, double> &studentScore) // find() v.s. at() v.s. operator[]
{
	// find()
	cout<<"Find Tony using find(): "<<endl;
	auto iter = studentScore.find("Tony");
	if(iter != studentScore.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;
	
	cout<<"Find Elbert using find(): "<<endl;
	iter = studentScore.find("Elbert");
	if(iter != studentScore.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	// at()
	cout<<"Find Tony using at(): "<<endl;
	try
	{
		cout<<"[ Tony, "<<studentScore.at("Tony")<<" ]"<<endl;
	}
	catch(...)
	{
		cout<<"Element not found."<<endl;
	}
	cout<<endl;

	cout<<"Find Elbert using at(): "<<endl;
	try
	{
		cout<<"[ Elbert, "<<studentScore.at("Elbert")<<" ]"<<endl;
	}
	catch(...)
	{
		cout<<"Element not found."<<endl;
	}
	cout<<endl;

	// operator[]
	cout<<"Find Tony using []: "<<endl;
	try
	{
		cout<<"[ Tony, "<<studentScore["Tony"]<<" ]"<<endl;
	}
	catch(...)
	{
		cout<<"Element not found."<<endl;
	}
	cout<<endl;

	cout<<"Find Elbert using []: "<<endl;
	try
	{
		cout<<"[ Elbert, "<<studentScore["Elbert"]<<" ]"<<endl;
	}
	catch(...)
	{
		cout<<"Element not found."<<endl;
	}
	cout<<endl;
}

void mapInsertRepeatedKeyTest(map<string, double> &studentScore) //  insert() v.s. emplace() v.s. []
{
	// insert()
	cout<<"Insert Tony with value 80.0 by using insert(): "<<endl;
	studentScore.insert(pair<string, double>("Tony", 80.0));
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;

	// emplace()
	cout<<"Insert Tony with value 80.0 by using emplace(): "<<endl;
	studentScore.emplace("Tony", 78.8);
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;

	// operator[]
	cout<<"Insert Tony with value 80.0 by using []: "<<endl;
	studentScore["Tony"] = 80.0;
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}

void mapKeyModifyTest(map<string, double> &studentScore)
{
	cout<<"Rename Tony as Ana"<<endl;
	auto iter = studentScore.find("Tony");
	// errors with the following '='
	// iter->first = "Ana";
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}

void mapValueModifyTest(map<string, double> &studentScore)
{
	cout<<"Modify Tony's value to 85.3 by using iterateor: "<<endl;
	auto iter = studentScore.find("Tony");
	iter->second = 85.3;
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;

	cout<<"Modify Tony's value to 88.3 by using []: "<<endl;
	studentScore["Tony"] = 88.3;
	iter->second = 88.3;
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}

void mapDeleteTest(map<string, double> &studentScore)
{
	cout<<"Erase Tony. "<<endl;
	auto iter = studentScore.find("Tony");
	studentScore.erase(iter);
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;

	// Erase non-existing pair
	cout<<"Erase Tony again: "<<endl;
	if( studentScore.erase("Tony"))
		cout<<"Erased successfully."<<endl;
	else
		cout<<"Failed erasing."<<endl;
	cout<<endl;
	
	// Clear all
	cout<<"clear(): "<<endl;
	studentScore.clear();
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}

