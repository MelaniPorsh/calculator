#include <iostream>
#include <string>

int charToBinary(char c) {
    return c - '0';
}

char binaryToChar(int binary) {
    return char(binary + '0');
}

std::string addBinary(std::string a, std::string b) {
    std::string result = "";
    int carry = 0;

    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        int bitA = charToBinary(a[i]);
        int bitB = charToBinary(b[i]);
        int sum = bitA + bitB + carry;
        carry = sum / 2;
        result = binaryToChar(sum % 2) + result;
    }

    if (carry == 1) {
        result = "1" + result;
    }

    return result;
}

std::string subtractBinary(std::string a, std::string b) {
    std::string result = "";
    bool borrow = false;

    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        int bitA = charToBinary(a[i]);
        int bitB = charToBinary(b[i]);

        if (borrow) {
            bitA--;
        }

        if (bitA < bitB) {
            bitA += 2;
            borrow = true;
        }
        else {
            borrow = false;
        }

        result = binaryToChar(bitA - bitB) + result;
    }

    return result;
}

std::string multiplyBinary(std::string a, std::string b) {
    std::string result = "0";

    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1') {
            result = addBinary(result, a);
        }
        a = a + "0";
    }

    return result;
}

std::string divideBinary(std::string a, std::string b) {
    std::string quotient = "";
    std::string remainder = a;

    while (remainder.length() >= b.length()) {
        std::string aux = remainder.substr(0, b.length());
        remainder = remainder.substr(b.length());

        int q = 0;
        while (subtractBinary(aux, b) != "0" && aux.length() > 0) {
            aux = subtractBinary(aux, b);
            q++;
        }

        quotient += binaryToChar(q);
    }

    return quotient;
}

int main() {
    std::string num1 = "101";
    std::string num2 = "11";

    std::cout << "Number 1: " << num1 << std::endl;
    std::cout << "Number 2: " << num2 << std::endl;

    std::cout << "Sum: " << addBinary(num1, num2) << std::endl;
    std::cout << "Difference: " << subtractBinary(num1, num2) << std::endl;
    std::cout << "Product: " << multiplyBinary(num1, num2) << std::endl;
    std::cout << "Quotient: " << divideBinary(num1, num2) << std::endl;

    return 0;
}
