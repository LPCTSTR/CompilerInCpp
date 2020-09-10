#include "Lexer.h"
using std::string;



const unsigned short KWCount = 21;
const string* Lexer::keyword = new string[KWCount]
{
	"break","case","char","continue","do","default","double",
	"else","float","for","if","int","include","long","main",
	"return","switch","typedef","void","unsigned","while"
};

const unsigned short MOCount = 11;
const string* Lexer::Monocular_Operator = new string[MOCount]{ "+","-","*","/","!","%","~","&","|","^","=" };


const unsigned short BOCount = 12;
const string* Lexer::Binocular_Operator = new string[BOCount]{ "++","--","&&","||","<=","!=","==",">=","+=","-=","*=","/=" };

const unsigned short DCount = 9;
const string* Lexer::Delimiter = new string[DCount]{ ",", "(", ")", "{", "}", ";", "<", ">", "#" };

const unsigned short FCount = 4;
const static char FILTER[FCount] = { ' ','\t','\r','\n' };

/*
	@Return Is the parameter a filter.
*/
inline bool IsFilter(char a)
{
	for (int i = 0; i < FCount; ++i)
		if (FILTER[i] == a)
			return true;
	return false;
}


/*
	@Return Is the parameter a letter.
*/
inline bool IsLetter(char ch) {
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true;
	return false;
}

/*
	@Return Is the parameter a digit.
*/
inline bool IsDigit(char ch) {
	if (ch >= '0' && ch <= '9') return true;
	return false;
}


/*
	@Return Is the parameter a keyword.
*/
inline bool IsKeyword(string word) {
	for (int i = 0; i < KWCount; i++) {
		if (Lexer::keyword[i] == word) {
			return true;
		}
	}
	return false;
}

/*
	@Return Is the parameter a Binocular_Operator.
*/
inline bool IsBO(string word) {
	for (int i = 0; i < BOCount; i++) {
		if (Lexer::Binocular_Operator[i] == word) {
			return true;
		}
	}
	return false;
}

/*
	@Return Is the parameter a Monocular_Operator.
*/
inline bool IsMO(string word) {
	for (int i = 0; i < MOCount; i++) 
		if (Lexer::Monocular_Operator[i] == word) 
			return true;
	return false;
}


/*
	@Return Is the parameter a Delimiter.
*/
inline bool IsDelimiter(string a)
{
	for (int i = 0; i < DCount; ++i)
		if (Lexer::Delimiter[i] == a)
			return true;
	return false;
}





bool Lexer::hasNext() {
	if (buffer.size() > 0)
		return true;
	return false;
}

WD Lexer::getNext() {
	if (!hasNext())
		return WD::UnknownWDT();
	auto tmp = buffer.front();
	buffer.pop();
	return std::move(tmp);
}

void Lexer::digest(string&& str) {
	Reader reader(str);


	//State Machine


}

Lexer* Lexer::getInst() {
	static Lexer* inst = nullptr;
	if (inst == nullptr)
		inst = new Lexer();
	return inst;
}

void Lexer::operator<<(string text) {
	std::cout << text << std::endl << (unsigned)this;
}
