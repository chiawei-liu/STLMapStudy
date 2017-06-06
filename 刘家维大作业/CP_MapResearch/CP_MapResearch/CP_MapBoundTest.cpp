#include"CP_MapBoundTest.h"

void mapBoundTest()
{
	map<int, string> studentID;

	// Initialization
	cout<<"A map has been initialized: "<<endl;
	studentID.insert(pair<int, string>(1, "Sandy"));
	studentID[2] = "Rebecca";
	studentID.emplace(3, "Nancy");
	printMap(studentID);
	cout<<endl;

	// Test lower and upper bound;
	cout<<"The lower_bound of key 2"<<endl;
	auto iter = studentID.lower_bound(2);
	if(iter != studentID.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	cout<<"The upper_bound of key 4"<<endl;
	iter = studentID.upper_bound(4);
	if(iter != studentID.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	// use equal_range to find element
	cout<<"Try to find key 1: (using equal_range)"<<endl;
	pair<map<int, string>::iterator, map<int, string>::iterator> iterPair = studentID.equal_range(1);
	if(iterPair.first != iterPair.second)
		cout<<"[ "<<iterPair.first->first<<", "<<iterPair.first->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	cout<<"Try to find key 4: (using equal_range)"<<endl;
	iterPair = studentID.equal_range(4);
	if(iterPair.first != iterPair.second)
		cout<<"[ "<<iterPair.first->first<<", "<<iterPair.first->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	cout<<"Clear the map."<<endl;
	studentID.clear();
	cout<<"The map has become: "<<endl;
	printMap(studentID);
	cout<<endl;
}