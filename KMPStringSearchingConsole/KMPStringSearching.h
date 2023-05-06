#pragma once

#include <string>

using namespace std;

namespace StringSearching {
	class KMPStringSearching {
	private:
		string keyword;
		int* next;

		void PreCalculateNextIndexArray(string keyword);
	public:
		KMPStringSearching(string keyword);
		~KMPStringSearching();

		int GetKeywordLength();
		int Search(string text, int*& keywordsPosition); //return count of matches
	};
}