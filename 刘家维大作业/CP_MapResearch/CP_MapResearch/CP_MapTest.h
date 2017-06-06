#ifndef CP_MAPTEST_H
#define CP_MAPTEST_H
#include<iostream>
#include<string>
#include<map>
using namespace std;

template<class T1, class T2>
void printMap(map<T1, T2> m)
{
	if(m.empty()) // or if(m.begin() == m.end())
	{
		cout<<"An empty map. "<<endl;
		return;
	}
	typename map<T1,T2>::iterator iter;
	for(iter =  m.begin(); iter != m.end(); iter++)
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
}

template<class T1, class T2>
void printReverseMap(map<T1, T2> m)
{
	if(m.empty()) // or if(m.begin() == m.end())
	{
		cout<<"An empty map. "<<endl;
		return;
	}
	typename map<T1,T2>::reverse_iterator riter;
	for(riter =  m.begin(); iter != m.rend(); iter++)
		cout<<"[ "<<riter->first<<", "<<riter->second<<" ]"<<endl;
}

extern void mapTest();
extern void mapInsertTest(map<string, double> &studentScore);
extern void mapFindTest(map<string, double> &studentScore);
extern void mapInsertRepeatedKeyTest(map<string, double> &studentScore);
extern void mapKeyModifyTest(map<string, double> &studentScore);
extern void mapValueModifyTest(map<string, double> &studentScore);
extern void mapDeleteTest(map<string, double> &studentScore);


#endif