#include"CP_MultimapTest.h"

void multimapTest()
{
	
	cout<<"A multimap has been initialized: "<<endl;
	multimap<string, double> studentScore;
	printMap(studentScore);
	cout<<endl;

	// Add Basic members
	cout<<"Insert some members: "<<endl;
	studentScore.insert(pair<string, double>("Andy", 97.8)); //Student Andy got 97.8
	studentScore.emplace("Tony", 95.6);  //Student Tony got 95.6
	printMap(studentScore);
	cout<<endl;

	// Insert repeated keys with different values
	multimapInsertRepeatedKeyTest(studentScore);

	// Find and get value: find() v.s. equal_range() v.s. lower_bound()
	multimapFindTest(studentScore);

	// Delete pairs with same key
	multimapDeleteTest(studentScore);
}

void multimapInsertRepeatedKeyTest(multimap<string, double> &studentScore)
{
	cout<<"Insert another Tony with score 91.1"<<endl;
	studentScore.emplace("Tony", 91.1);

	cout<<"Insert the other Andy who also scored 97.8"<<endl;
	studentScore.emplace("Andy", 97.8);

	cout<<"Insert the other Tony with score 99.2"<<endl;
	studentScore.emplace("Tony", 99.2);
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}

void multimapFindTest(multimap<string, double> &studentScore) // find() v.s. equal_range v.s. bound
{
	// find() Tony once
	cout<<"Find Tony by using find(): "<<endl;
	auto iter = studentScore.find("Tony");
	if(iter != studentScore.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	// find() Tony again to see if there's a difference.
	cout<<"Find Tony by using find() again: "<<endl;
	iter = studentScore.find("Tony");
	if(iter != studentScore.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;

	// equal_range().  Find all pairs that have the same key.
	cout<<"Find and print all Tony: "<<endl;
	auto iterPair = studentScore.equal_range("Tony");
	for(iter = iterPair.first; iter != iterPair.second; iter++ )
	{
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	}
	cout<<endl;

	// lower_bound().  Find certain pair.  
	cout<<"Find the second pair of Tony: "<<endl;
	iter = studentScore.lower_bound("Tony");
	for(int i = 0; i < 2-1; i++ )
		iter ++;
	if(iter != studentScore.end())
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
	else
		cout<<"Element not found."<<endl;
	cout<<endl;
}

void multimapDeleteTest(multimap<string, double> &studentScore)
{
	// erase one kind of the keys
	cout<<"Erase all Tony: "<<endl;
	auto iterPair = studentScore.equal_range("Tony");
	studentScore.erase(iterPair.first, iterPair.second);
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;

	// Clear all
	cout<<"clear(): "<<endl;
	studentScore.clear();
	cout<<"The map has become: "<<endl;
	printMap(studentScore);
	cout<<endl;
}