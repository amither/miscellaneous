#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#include <string>
#include <iostream>

using namespace std;

//g++ rapidjson_test.cpp -std=c++0x -I/data1/tlinux2_lib/usr/local/cftlib/ -o rapidjson_test
//http://rapidjson.org/md_doc_tutorial.html
int main() {
	string s = "{\"a\":\"1\", \"b\":\"2\"}";
	rapidjson::Document document;
	if (document.Parse(s.c_str()).HasParseError()) {
		cout << "prase error" << endl;
		return 1;
	}

	for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr) {
		cout << itr->name.GetString() << ": " << itr->value.GetString() << endl;
	}


	string s1 = "[{\"a\":\"1\", \"b\":\"2\"}, {\"a\":\"h\", \"b\":\"2\"}]";
	rapidjson::Document document1;
	document1.Parse(s1.c_str());
	for (rapidjson::Value::ConstValueIterator itr = document1.Begin(); itr != document1.End(); ++itr) {
		for (rapidjson::Value::ConstMemberIterator itr1 = itr->MemberBegin(); itr1 != itr->MemberEnd(); ++itr1) {
			cout << itr1->name.GetString() << ": " << itr1->value.GetString() << endl;
		}
	}

	rapidjson::Document d1(rapidjson::kArrayType);
	rapidjson::Document::AllocatorType& allocator = d1.GetAllocator();
	rapidjson::Value v(rapidjson::kObjectType);
	rapidjson::Value key(rapidjson::kStringType);
	rapidjson::Value value(rapidjson::kStringType);
	key.SetString(string("1").c_str(), allocator);
	value.SetString(string("2").c_str(), allocator);

	v.AddMember(key, value, allocator);
	for (rapidjson::Value::ConstMemberIterator itr = v.MemberBegin(); itr != v.MemberEnd(); ++itr) {
		cout << itr->name.GetString() << ": " << itr->value.GetString() << endl;
	}

	d1.PushBack(v, allocator);

	rapidjson::StringBuffer sb;
	rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
    d1.Accept(writer);
	cout << sb.GetString() << endl;

	sb.Clear();
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writerPretty(sb);
    d1.Accept(writerPretty);
	cout << sb.GetString() << endl;

	rapidjson::Document d2(rapidjson::kObjectType);
	rapidjson::Document::AllocatorType& allocator2 = d2.GetAllocator();
	d2.AddMember("1", "2", allocator2);
	d2.AddMember("2", "3", allocator2);
	for (rapidjson::Value::ConstMemberIterator itr = d2.MemberBegin(); itr != d2.MemberEnd(); ++itr) {
		cout << itr->name.GetString() << ": " << itr->value.GetString() << endl;
	}

	sb.Clear();
	rapidjson::Writer<rapidjson::StringBuffer> writer2(sb);
    d2.Accept(writer2);
	cout << sb.GetString() << endl;

	return 0;
}
