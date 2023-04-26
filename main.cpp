
#include <iostream>
using namespace std;


// Question 2

const int MaximumSize = 100; // const method , cannor be modified like final in Java or  let in Swift

bool is_palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Question 3


const int maxNumber = 1000000;

int numbers1[] = {2, 3, 4, 5, 6, 7, 9};
bool isPrime[maxNumber + 1];

int sieve_of_eratosthenes(int* numbers, int n) {
    int primeNumbers = 0;
    fill_n(isPrime, n, true);
    for (int i = 0; i < n; i++) {
        if (isPrime[numbers[i]]) {
            int number = numbers[i];
            if (number > 1) {
                primeNumbers++;
            }
            for (int j = number * 2; j <= maxNumber; j += number) {
                isPrime[j] = false;
            }
        }
    }
    return primeNumbers;
}
//  Question 4

string lowerCase(string a) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    return a;
}

string delete_space(string b) {
    b.erase(remove(b.begin(), b.end(), ' '), b.end());
    return b;
}

string sortedString(string s) {
    sort(s.begin(), s.end());
    return s;
}

bool anagrams1(string a1, string a2) {
    a1 = sortedString(delete_space(lowerCase(a1)));
    a2 = sortedString(delete_space(lowerCase(a2)));

    return a1 == a2;
}


// Question 1
int main() {
    int list1[] = {1,2,3,4,5};
    int list2[] = {-1,2,4,7,9};
    int n1 = sizeof(list1)/sizeof(list1[0]);
    int n2 = sizeof(list2)/sizeof(list2[0]);

    int common[n1 < n2 ? n1 : n2];
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (list1[i] == list2[j]) {
                bool isDifferent = true;
                for (int m = 0; m < k; m++) {
                    if (common[m] == list1[i]) {
                        isDifferent = false;
                        break;
                    }
                }
                if (isDifferent) {
                    common[k] = list1[i];
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << "\nCommon Values is : " << common[i] << " ";
    }
    cout << endl;


    //Question 2
    string inlist[MaximumSize] = {"mom", "dad", "junior", "language"};
    string palindromes[MaximumSize];
    int count = 0;
    for (int i = 0; i < MaximumSize; i++) {
        if (inlist[i] == "") {
            break;
        }
        if (is_palindrome(inlist[i])) {
            palindromes[count] = inlist[i];
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << "\nPalindrom string is : " << palindromes[i] << " ";
    }
    cout << " " ;
 // Question 3
    int c = sizeof(numbers1) / sizeof(int);
    int numPrimes = sieve_of_eratosthenes(numbers1, c);
    cout << "\nNumber of prime numbers are : " <<  numPrimes << endl;
    for (int i = 2; i <= maxNumber; i++) {
        if (isPrime[i]) {
            cout <<"\n Primes number is : " << i<<" " ;
        }
    }
    cout<< "\n " ;
//Question 4


    string word = "angle";
    string wordList[] = {"leang", "glean", "goal", "hello"};
    int n = sizeof(wordList) / sizeof(wordList[0]);

    for (int i = 0; i < n; i++) {
        if (anagrams1(word, wordList[i])) {
            cout <<"\nAnagram String is : " <<  wordList[i] << " ";
        }
    }

    return 0;
}

