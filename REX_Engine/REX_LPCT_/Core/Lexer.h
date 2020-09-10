#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<type_traits>


/*
@Auther: LPCTSTR_MSR(毛思睿 180310235)
@Record:
9/10/20-18:26: Define the WordDespritionType, WordDesprition and Lexer, arrange the word code.
9/10/20-23:13: 1.Define functions like IsMO,IsBO,IsKeyword  2.Define class Reader

@Brief:
Keyword map definition:
//Lexer.cpp---------------
const string* Lexer::keyword= new string[40]
{
	"break","case","char","continue","do","default","double",
	"else","float","for","if","int","include","long","main",
	"return","switch","typedef","void","unsigned","while"
};
//------------------------
######KEYWORD segment (KEYWORD = 10) #########
Keyword | CODE | [CODE-KEYWORD](INDEX)
break   |  10  | keyword[10-10]
case    |  11  | keyword[11-10]
char    |  12  | keyword[12-10]
continue|  13  | keyword[13-10]
char    |  14  | keyword[14-10]
... ...


// "+","-","*","/","!","%","~","&","|","^","="
// "++","--","&&","||","<=","!=","==",">=","+=","-=","*=","/="
######OPERATOR segment (OPERATOR = 500) ######

Operator| CODE | [CODE-OPERATOR](INDEX)
   +    | 500  | Monocular_Operator[500-500]
   -    | 501  | Monocular_Operator[501-500]
   *    | 502  | Monocular_Operator[502-500]
   /    | 503  | Monocular_Operator[503-500]
   !    | 504  | Monocular_Operator[504-500]
... ...			   ---Binocular_Offset=511  [CODE-Binocular_Offset]
   ++   | 511  | Binocular_Operator[511-Binocular_Offset]
   --   | 512  | Binocular_Operator[512-Binocular_Offset]
   &&   | 513  | Binocular_Operator[513-Binocular_Offset]
   ||   | 514  | Binocular_Operator[514-Binocular_Offset]
... ...


*/

#define Binocular_Offset 511
enum class WordDespritionType {
	KEYWORD = 10,
	OPERATOR = 500,
	IDENTIFIER = 999,
	CONSTANT = 1000,
	DELIMITER = 1001
};
using WDT = WordDespritionType;
/*
Word Description:
text: The origin text of the word.
type: The type of the Word, to see the details(## WordDespritionType)
*/
struct WordDesprition {
	static const WD UnknownWDT() { return WD("UNKNOWN", WDT::IDENTIFIER); }
	std::string name;
	WDT type;
	WordDesprition(std::string n, WDT t) { name = n, type = t; }
};
using WD = WordDesprition;

struct Reader {
private:
	std::string data;
	int index;
	int len;
public:
	Reader(std::string d) :data(d), index(0), len(d.size()) {}
	char getNextChar() {
		if (index < len)
			return data[index++];
		return -1;
	}
};

class Lexer {
	std::queue<WD> buffer;

	bool hasNext();
	WD getNext();
	void digest(std::string&& str);
	Lexer() {}
public:
	static const std::string* keyword;
	static const std::string* Monocular_Operator;
	static const std::string* Binocular_Operator;
	static const std::string* Delimiter;
	static Lexer* getInst();
	void operator<<(std::string text);
};
#define LEXER *(Lexer::getInst())

