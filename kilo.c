//
// Created by xuying on 2021/11/26.
//
#include <termios.h> //termios is unix api for terminal i/o
#include <stdio.h>
#include <unistd.h> // 提供unix环境下大量的system call wrapper functions

void enableRowMode() {
    struct termios raw; // 将变量raw设置为termios结构类型
    tcgetattr(STDIN_FILENO, &raw); // 获取标准输入的属性，将其写入变量raw
    raw.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    printf("program beginning");
    enableRowMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    printf("hello,world\n");
    return 0;
}
