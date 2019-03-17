// Lab_02_Task_27

#include <iostream>
#define MAX_NUM 100

class UkrainianString {
private:
	int *symbolsNumber;
	char *ukrString;

public:
	static char ukrAlphabet[67];
	UkrainianString(void) { symbolsNumber = new int(0); ukrString = (char*)malloc(MAX_NUM * sizeof(char)); }
	UkrainianString(const char *s);
	UkrainianString(const UkrainianString &obj);
	~UkrainianString() { delete[] symbolsNumber; delete ukrString; };

	void PrintOut(void);
	void PrintIn(const char *s);
	const char* GetString();
	int GetSymbolsNumber();
};

char UkrainianString::ukrAlphabet[67] = "ÀàÁáÂâÃã¥´ÄäÅåªºÆæÇçÈè²³¯¿ÉéÊêËëÌìÍíÎîÏïĞğÑñÒòÓóÔôÕõÖö×÷ØøÙùÜüŞşßÿ";


UkrainianString::UkrainianString(const char *s) {
	int realNumber = strlen(s) <= MAX_NUM ? strlen(s) : MAX_NUM;
	ukrString = (char*)malloc((MAX_NUM) * sizeof(char));
	symbolsNumber = new int(realNumber);
	for (int i = 0; i < realNumber; i++)
	{
		if (((int) *(s + i) >= 65 && (int)*(s + i) <= 90)
			|| ((int)*(s + i) >= 65 && (int)*(s + i) <= 90)) {
			throw std::exception();
		}
	}

	for (int i = 0; i < realNumber; i++)
	{
		ukrString[i] = *(s + i);
	}

	ukrString[realNumber] = '\0';
}

UkrainianString::UkrainianString(const UkrainianString &obj) {
	ukrString = (char*)malloc(MAX_NUM * sizeof(char));
	symbolsNumber = new int(*obj.symbolsNumber);

	char *s = obj.ukrString;

	for (int i = 0; i < *symbolsNumber; i++)
	{
		ukrString[i] = *(s + i);
	}

	ukrString[*symbolsNumber] = '\0';
}

void UkrainianString::PrintOut(void) {
	printf("%s\n", ukrString);
}

void UkrainianString::PrintIn(const char *s) {
	int realNumber = strlen(s) <= MAX_NUM ? strlen(s) : MAX_NUM;
	symbolsNumber = new int(realNumber);
	for (int i = 0; i < realNumber; i++)
	{
		if (((int) *(s + i) >= 65 && (int)*(s + i) <= 90)
			|| ((int)*(s + i) >= 65 && (int)*(s + i) <= 90)) {
			throw std::exception();
		}
	}

	for (int i = 0; i < realNumber; i++)
	{
		ukrString[i] = *(s + i);
	}

	ukrString[realNumber] = '\0';
}

const char* UkrainianString::GetString() {
	return ukrString;
}

int UkrainianString::GetSymbolsNumber() {
	return *symbolsNumber;
}


int NumberInAlphabet(int letter) {
	for (int i = 0; i < 66; i++)
	{
		if (letter == UkrainianString::ukrAlphabet[i]) {
			return i;
		}
	}

	return -1;
}

int AreStringsEqual(UkrainianString *u1, UkrainianString *u2) {

	const char *s1 = (u1->GetString()),
		*s2 = (u2->GetString());

	if (strlen(s1) != strlen(s2)) {
		return 0;
	}

	int n = strlen(s1);

	for (int i = 0; i < n; i++)
	{
		int l1 = NumberInAlphabet(*(s1 + i)),
			l2 = NumberInAlphabet(*(s2 + i));

		if (l1 >= 0 && l2 >= 0) {
			if ((l1 - l1 % 2) != (l2 - l2 % 2))
			{
				return 0;
			}
		}

		if (l1 < 0 && l2 < 0) {
			l1 = *(s1 + i);
			l2 = *(s2 + i);
			if (l1 != l2) {
				return 0;
			}
		}
	}

	return 1;
}

int IsStringHigherOrLower(UkrainianString *u1, UkrainianString *u2) {

	const char *s1 = (u1->GetString()),
		*s2 = (u2->GetString());

	int length1 = strlen(s1), length2 = strlen(s2);

	int minLength = length1 <= length2 ? length1 : length2;

	for (int i = 0; i < minLength; i++)
	{
		int l1 = NumberInAlphabet(*(s1 + i)),
			l2 = NumberInAlphabet(*(s2 + i));


		if ((l1 - l1 % 2) < (l2 - l2 % 2)) {
			return 1;
		}

		else if ((l1 - l1 % 2) > (l2 - l2 % 2)) {
			return 0;
		}
	}

	if (length1 <= length2) {
		return 1;
	}
	else
	{
		return 0;
	}
}


int main(void) {
	system("chcp 1251");
	system("color F0");
	//UkrainianString s1("String") Ï³ääàºòüñÿ âèêëş÷åííş;
	UkrainianString s2("Ğÿäîê");
	UkrainianString *s3 = new UkrainianString;
	s3->PrintIn("ĞßÄÎÊ");
	UkrainianString s4(s2);
	UkrainianString s5("Äîâøèé ğÿäîê");

	//s1.PrintOut();
	s2.PrintOut();
	s3->PrintOut();
	s4.PrintOut();
	s5.PrintOut();

	printf("%d\n", AreStringsEqual(&s2, s3));
	printf("%d\n", AreStringsEqual(&s2, &s4));
	printf("%d\n", AreStringsEqual(&s2, &s5));
	printf("%d\n", IsStringHigherOrLower(&s5, &s2));
	printf("%d\n", IsStringHigherOrLower(&s2, &s5));

	system("pause");
}