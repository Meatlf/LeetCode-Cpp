// Problem:  http://oj.leetcode.com/problems/implement-strstr/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/23655843
// 1988lilong@163.com

#include <iostream>
#include <string>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	std::string str(haystack);
    	std::string target(needle);

    	if(target.empty())
    	{
    		return haystack;
    	}

    	int len1 = str.length();
    	int len2 = target.length();
    	if(len1 < len2)
    	{
    		return NULL;
    	}

    	for(int i = 0; i <= len1 - len2; ++i)
    	{
    		int j = 0;
    		int k = i;
    		while(j < len2 && target[j] == str[k])
    		{
    			k++;
    			j++;
    		}

    		if(j == len2)
    		{
    			return (char*)str.substr(i).c_str();  //
    		}
    	}

    	return NULL;
    }
};


class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle)
        {
            return haystack;
        }
        
        char *advance = haystack;
        char *p = haystack;
        char *p2 = needle + 1;
        
        while(*p2)
        {
            ++advance;
            ++p2;
        }
        
        while(*advance)  // control max cmp times
        {
            char *p1 = p;
            p2 = needle;
            while(*p2 && *p1 == *p2)
            {
                ++p1;
                ++p2;
            }
            
            if(!*p2)
            {
                return p;
            }
            
            ++advance;
            ++p;
        }
        
        return NULL;
    }
};

int main()
{
	char *a = "abcdab";
	char *needle = "da";

	Solution slt;
	std::cout << slt.strStr(a, needle) << std::endl;
}

// KMP
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
		if(haystack == NULL || needle == NULL) return NULL;  
		int hlen = strlen(haystack);  
		int nlen = strlen(needle);  
		if(nlen == 0) return haystack;  
		if(hlen == 0 ) return NULL;  
		int pattern[100000];  
		GeneratePattern(needle, nlen, pattern);  
		return Match(haystack, needle, pattern);  
    }

	void GeneratePattern(char* str, int len, int* pattern)  
	{  
		pattern[0] = -1;  
		int k = -1;  
		for(int j = 1; j < len; j++)  
		{  
			while(k > -1 && str[k + 1] != str[j])  
				k = pattern[k];  
			if(str[k + 1] == str[j])  
				k++;  
			pattern[j] = k;  
		}  
	}  

	char* Match(char* haystack, char* needle, int* pattern)  
	{  
		int hlen = strlen(haystack);  
		int nlen = strlen(needle);      
		int k = -1;  
		for(int j = 0; j < hlen; j++, haystack++)  
		{  
			while(k > -1 && needle[k + 1] != *haystack)  
				k = pattern[k];  
			if(needle[k + 1] == *haystack)  
				k++;  
			if(k == nlen - 1)  
				return haystack - k;  
		}  
		return NULL;  
	}  
};

