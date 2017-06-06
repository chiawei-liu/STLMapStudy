#ifndef CP_MULTIMAPTEST_H
#define CP_MULTIMAPTEST_H
#include<iostream>
#include<string>
#include<map>
using namespace std;

template<class T1, class T2>
void printMap(multimap<T1, T2> m)
{
	if(m.empty()) // or if(m.begin() == m.end())
	{
		cout<<"An empty map. "<<endl;
		return;
	}
	typename multimap<T1,T2>::iterator iter;
	for(iter =  m.begin(); iter != m.end(); iter++)
		cout<<"[ "<<iter->first<<", "<<iter->second<<" ]"<<endl;
}

template<class T1, class T2>
void printReverseMap(multimap<T1, T2> m)
{
	if(m.empty()) // or if(m.begin() == m.end())
	{
		cout<<"An empty map. "<<endl;
		return;
	}
	typename multimap<T1,T2>::reverse_iterator riter;
	for(riter =  m.begin(); iter != m.rend(); iter++)
		cout<<"[ "<<riter->first<<", "<<riter->second<<" ]"<<endl;
}


extern void multimapTest();
extern void multimapInsertRepeatedKeyTest(multimap<string, double> &studentScore);
extern void multimapFindTest(multimap<string, double> &studentScore);
extern void multimapDeleteTest(multimap<string, double> &studentScore);


#endif