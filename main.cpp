#include <iostream>
#include <string>

using namespace std;

class StringManipulator {
public:
    // Функція для першого завдання
    static string replaceSubstringWithBrackets(const string& original, const string& substr) {
        string result = original;
        size_t pos = 0;
        while ((pos = result.find(substr, pos)) != string::npos) {
            result.replace(pos, substr.length(), "(" + substr + ")");
            pos += 2 + substr.length();
        }
        return result;
    }

    // Функція для другого завдання
    static string evaluateExpressions(const string& input) {
        string result = input;
        size_t startPos = 0;
        while (startPos < result.length()) {
            size_t plusPos = result.find('+', startPos);
            size_t minusPos = result.find('-', startPos);
            if (plusPos == string::npos && minusPos == string::npos) break;
            size_t opPos = (plusPos != string::npos && (minusPos == string::npos || plusPos < minusPos)) ? plusPos : minusPos;
            size_t num1Start = opPos;
            while (num1Start > 0 && isdigit(result[num1Start - 1])) num1Start--;
            size_t num2End = opPos + 1;
            while (num2End < result.length() && isdigit(result[num2End])) num2End++;
            int num1 = stoi(result.substr(num1Start, opPos - num1Start));
            int num2 = stoi(result.substr(opPos + 1, num2End - opPos - 1));
            int resultValue = (result[opPos] == '+') ? num1 + num2 : num1 - num2;
            result = result.substr(0, num1Start) + to_string(resultValue) + result.substr(num2End);
            startPos = num1Start + to_string(resultValue).length();
        }
        return result;
    }
};

int main() {
    // Перше завдання
    string originalString = "abaracadabra";
    string substr = "ab";
    cout << StringManipulator::replaceSubstringWithBrackets(originalString, substr) << endl;

    // Друге завдання
    string expressionString = "alpha 5+26 beta 72-35 gamma 32+45 etc";
    cout << StringManipulator::evaluateExpressions(expressionString) << endl;

    return 0;
}
