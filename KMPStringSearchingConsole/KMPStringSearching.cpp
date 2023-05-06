#include "KMPStringSearching.h"

using namespace StringSearching;

KMPStringSearching::KMPStringSearching(const string keyword) {
	next = NULL;
	PreCalculateNextIndexArray(KMPStringSearching::keyword = keyword);
}

KMPStringSearching::~KMPStringSearching() {
	delete[] next;
}

int KMPStringSearching::GetKeywordLength() {
	return static_cast<int>(keyword.length());
}

void KMPStringSearching::PreCalculateNextIndexArray(const string match) {
	if (next) {
		delete[] next;
		next = NULL;
	}
	int length = static_cast<int>(match.length());
	if (length < 1)
		return;
	next = new int[length];

	//match itself and record each char how many next char it can match continuously.
	//more brief
	next[0] = -1;
	for (int i = 1, j = 0; i < length; j = 0) {
		do {
			next[i] = j;
		} while (match[i++] == match[j++] && i < length);
	}
}

//return count of matches
int KMPStringSearching::Search(const string text, int*& keywordsPosition) {
	//initialize
	keywordsPosition = NULL;
	//
	int matchedPointCount = 0;
	int* matchedPointArray = new int[matchedPointCount];
	const int textLength = static_cast<int>(text.length());
	const int matchLength = static_cast<int>(keyword.length());
	for (int i = 0; i < textLength;) {
		for (int j = 0; j < matchLength;) {
			if (text[i] == keyword[j]) {
				j++;
				i++;
				if (j == matchLength) {
					matchedPointCount++;
					int* newArray = new int[matchedPointCount];
					newArray[matchedPointCount - 1] = i - matchLength;
					for (int k = 0; k < matchedPointCount - 1; k++)
						newArray[k] = matchedPointArray[k];
					delete[] matchedPointArray; // delete old array
					matchedPointArray = newArray;
					newArray = NULL;
					break;
				}
			}
			else {
				j = next[j]; // go to prefix position and match again
				if (j < 0) {
					i++;
					break;
				}
			}
		}
	}
	keywordsPosition = matchedPointArray;
	matchedPointArray = NULL;
	return matchedPointCount; //return count of matches
}

//void KMPStringSearching::PreCalculateNextIndexArray(const string match) {
//	if (next)
//		delete[] next;
//	int length = match.length();
//	next = new int[length];
//
//	//brief
//	next[0] = -1;
//	for (int i = 1; i < length;) {
//		for (int j = 0; i < length;) {
//			next[i] = j;
//			if (match[i++] != match[j++])
//				break;
//		}
//	}
//	
//	// simple code
//	next[0] = -1;
//	for (int i = 1; i < length;) {
//		for (int j = 0; i < length;) {
//			if (match[i] == match[j]) {
//				next[i] = j;
//				i++;
//				j++;
//			}
//			else {
//				next[i] = j;
//				i ++;
//				break;
//			}
//		}
//	}
//}
