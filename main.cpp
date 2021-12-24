#include <iostream>
using namespace std;
long transform(char *str){
    long rslt = 0;
    if (*str == '-' || *str == '+') {
        str++;
    }
    str+=2;
    while (*str != '\0') {
        int num;
        num = *str - '0';
        if (num > 9) {
            num = (num - 7) % 32;
        }
        rslt = 16 * rslt + num;
        str++;
    }
    return rslt;
}
int str_check(int argc, char *argv[]){
    for (int i = 0; i < argc-1; ++i) {
        char *str = argv[argc - i - 1];
        bool is_negative = (*str == '-');
        long rslt = transform(str);
        if (is_negative) {
            rslt = -rslt;
        }
        rslt = 121 + rslt;
        cout << rslt << endl;
    }
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(-1);
    }
    str_check(argc, argv);
    return 0;
}
