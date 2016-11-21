/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

// INIFile adapted from https://sourceforge.net/p/simpleipconfig/code-git/ci/e50c0c07666ecb02b9b86124fee7276f46346869/tree/SimpleIpConfig/src/Beta%204/

class File
{
public:
	struct Record
	{
		string Comments;
		char Commented;
		string Section;
		string Key;
		string Value;
	};

	enum CommentChar
	{
		Pound = '#',
		SemiColon = ';'
	};

	File(void);
	virtual ~File(void);

	static bool AddSection(string SectionName, string FileName);
	static bool CommentRecord(CommentChar cc, string KeyName, string SectionName, string FileName);
	static bool CommentSection(char CommentChar, string SectionName, string FileName);
	static string Content(string FileName);
	static bool Create(string FileName);
	static bool DeleteRecord(string KeyName, string SectionName, string FileName);
	static bool DeleteSection(string SectionName, string FileName);
	static vector<Record> GetRecord(string KeyName, string SectionName, string FileName);
	static vector<Record> GetSection(string SectionName, string FileName);
	static vector<string> GetSectionNames(string FileName);
	static string GetValue(string KeyName, string SectionName, string FileName);
	static bool RecordExists(string KeyName, string SectionName, string FileName);
	static bool RenameSection(string OldSectionName, string NewSectionName, string FileName);
	static bool SectionExists(string SectionName, string FileName);
	static bool SetRecordComments(string Comments, string KeyName, string SectionName, string FileName);
	static bool SetSectionComments(string Comments, string SectionName, string FileName);
	static bool SetValue(string KeyName, string Value, string SectionName, string FileName);
	static bool Sort(string FileName, bool Descending);
	static bool UnCommentRecord(string KeyName, string SectionName, string FileName);
	static bool UnCommentSection(string SectionName, string FileName);

private:
	static vector<Record> GetSections(string FileName);
	static bool Load(string FileName, vector<Record>& content);
	static bool Save(string FileName, vector<Record>& content);

	struct RecordSectionIs : std::unary_function<Record, bool>
	{
		std::string section_;

		RecordSectionIs(const std::string& section) : section_(section) {}

		bool operator()(const Record& rec) const
		{
			return rec.Section == section_;
		}
	};

	struct RecordSectionKeyIs : std::unary_function<Record, bool>
	{
		std::string section_;
		std::string key_;

		RecordSectionKeyIs(const std::string& section, const std::string& key) : section_(section), key_(key) {}

		bool operator()(const Record& rec) const
		{
			return ((rec.Section == section_) && (rec.Key == key_));
		}
	};

	struct AscendingSectionSort
	{
		bool operator()(Record& Start, Record& End)
		{
			return Start.Section < End.Section;
		}
	};

	struct DescendingSectionSort
	{
		bool operator()(Record& Start, Record& End)
		{
			return Start.Section > End.Section;
		}
	};

	struct AscendingRecordSort
	{
		bool operator()(Record& Start, Record& End)
		{
			return Start.Key < End.Key;
		}
	};

	struct DescendingRecordSort
	{
		bool operator()(Record& Start, Record& End)
		{
			return Start.Key > End.Key;
		}
	};
};