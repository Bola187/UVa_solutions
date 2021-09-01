#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

void multiply(char str1[], char str2[], char result[]) {
	int len_1, len_2;
	int i, j, temp, carry;
	len_1 = strlen(str1);
	len_2 = strlen(str2);
	for (i = 0; i < len_1 + len_2; i++)
		result[i] = '0';
	result[i] = '\0';
	for (i = len_1 - 1; i >= 0; i--) {
		for (j = len_2 - 1, carry = 0; j >= 0; j--) {
			temp = (str1[i] - '0') * (str2[j] - '0') + result[i + j + 1] - '0' + carry;
			carry = temp / 10;
			result[i + j + 1] = (temp % 10) + '0';
		}
		result[i] = carry + '0';
	}
	for (j = 0; result[j] == '0'; j++);
	if (j >= len_1 + len_2)
		result[1] = '\0';
	else
		for (i = 0; result[i] != '\0'; i++)
			result[i] = result[i + j];
}
int main() {
	char str1[100000];
	char str2[100000];
	char result[100000];
	while (cin>>str1) {
		cin>>str2;
		multiply(str1, str2, result);
		cout << result << endl;
	}
	return 0;
}