#include <string>
#include <iostream>
#include <memory>
#include "json/json.h"
using namespace std;
//g++ json_test.cpp -I/usr/local/cftlib/lctlib/lctcommon/third_party/jsoncpp-0.y.z/include -L/usr/local/cftlib/lctlib/lctcommon/third_party/jsoncpp-0.y.z/libs -ljsoncpp  -std=c++0x -o json_test
int main()
{
	string s = "{\"a\":1, \"b\":\"2\"}";
	Json::Value v;
	Json::Reader r;
	r.parse(s, v);

	for (int i = 0; i < v.getMemberNames().size(); i++)
	{
		cout << v.getMemberNames()[i] << ": " << v[v.getMemberNames()[i]].asString() << endl;
	}

	for (Json::Value::iterator cit = v.begin(); cit != v.end(); cit++)
	{
		cout << cit.name() << ": " << cit->asString() << endl;
	}


	for (auto cit = v.begin(); cit != v.end(); cit++)
	{
		cout << cit.name() << ": " << cit->asString() << endl;
	}

	string s1 = "[{\"a\":1, \"b\":\"2\"}, {\"a\":\"h\", \"b\":\"2\"}]";
	Json::Value v1;
	r.parse(s1, v1);
	for (int i = 0; i < v1.size(); i++)
	{
		Json::Value v = v1[i];
		for (Json::Value::iterator cit = v.begin(); cit != v.end(); cit++)
		{
			cout << cit.name() << ": " << cit->asString() << endl;
		}
	}

	Json::Value v2;	
	v2["abcd"] = "a";
	v2["234"] = 1;

	Json::Value v3;
	v3.append(v2);

/*
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "";  // or whatever you like
	std::unique_ptr<Json::StreamWriter> writer(
			builder.newStreamWriter());
	writer->write(v3, &std::cout);
	cout << endl;
	*/


	Json::FastWriter w;
	string output = w.write(v3);
	cout <<output << endl;

	string s4 = "{\"a\":[1, 2, 3, 4]}";
	Json::Value v4;
	r.parse(s4, v4);
	cout << v4.isMember("a") << endl;
	return 0;
}
