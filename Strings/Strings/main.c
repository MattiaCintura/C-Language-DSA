//
//  main.c
//  Strings
//
//  Created by test on 14/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>

// Finding the lenght of a String
void lenght(char S[]) {
    int i;
    
    for (i = 0; S[i] != '\0'; i++);
    printf("%d\n", i);
}

// Change case of a String
char* lowerCase(char S[]) {
    int i;
    for (i = 0; S[i] != '\0'; i++) {
        S[i] += 32;
    }
    return S;
}

char* upperCase(char S[]) {
    int i;
    for (i = 0; S[i] != '\0'; i++) {
        S[i] -= 32;
    }
    return S;
}

// Toggle cases of a String
char* toggleCase(char S[]) {
    int i;
    for (i = 0; S[i] != '\0'; i++) {
        // Check if uppercase or lowercase
        if (S[i] >= 65 && S[i] <= 90) {
            S[i] += 32;
        }else if (S[i] >= 97 && S[i] <= 122) {
            S[i] -= 32;
        }
    }
    return S;
}

// Check how many vowels are in a String
int countVowels(char S[]) {
    int i;
    int count = 0;
    for (i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' ||
            S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U') {
            count++;
        }
    }
    return count;
}

// Check how many words are in a String
int wordsCount(char S[]) {
    int i;
    int count = 0;
    
    for (i = 0; S[i] != '\0'; i++) {
        if (S[i] == 32 && S[i - 1] == 32) {
            count++;
        }
    }
    
    if (count == 0){
        return 1;
    }
    return count + 1;
}

// Validate a String
int validate(char S[]) {
    int i;
    
    for (i = 0; S[i] != '\0'; i++) {
        if (!(S[i] >= 65 && S[i] <= 90) &&
            !(S[i] >= 97 && S[i] <= 122) &&
            !(S[i] >= 48 && S[i] <= 57)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char S[] = "welcome";
    return 0;
}
