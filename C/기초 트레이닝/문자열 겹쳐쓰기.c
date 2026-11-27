/*
제한사항
    my_string와 overwrite_string은 숫자와 알파벳으로 이루어져 있습니다.
    1 ≤ overwrite_string의 길이 ≤ my_string의 길이 ≤ 1,000
    0 ≤ s ≤ my_string의 길이 - overwrite_string의 길이
입출력 예
    my_string	overwrite_string	s	result
    "He11oWor1d"	"lloWorl"	2	"HelloWorld"
    "Program29b8UYP"	"merS123"	7	"ProgrammerS123"
입출력 예 설명
    입출력 예 #1
        예제 1번의 my_string에서 인덱스 2부터 overwrite_string의 길이만큼에 해당하는 부분은 "11oWor1"이고 이를 "lloWorl"로 바꾼 "HelloWorld"를 return 합니다.
    입출력 예 #2
        예제 2번의 my_string에서 인덱스 7부터 overwrite_string의 길이만큼에 해당하는 부분은 "29b8UYP"이고 이를 "merS123"로 바꾼 "ProgrammerS123"를 return 합니다.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, const char* overwrite_string, int s) {
    int my_len = 0;
    while (my_string[my_len] != '\0') {
        my_len++;
    }

    int over_len = 0;
    while (overwrite_string[over_len] != '\0') {
        over_len++;
    }

    char* answer = (char*)malloc((size_t)my_len + 1);
    if (answer == NULL) {
        return NULL;
    }

    for (int i = 0; i <= my_len; i++) {
        answer[i] = my_string[i];
    }

    for (int i = 0; i < over_len; i++) {
        answer[s + i] = overwrite_string[i];
    }

    return answer;
}

int main(void) {
    char* res1 = solution("He11oWor1d", "lloWorl", 2);
    if (res1 != NULL) {
        printf("%s\n", res1); 
        free(res1);
    }

    char* res2 = solution("Program29b8UYP", "merS123", 7);
    if (res2 != NULL) {
        printf("%s\n", res2); 
    }

    return 0;
}