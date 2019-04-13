#include <cstdio>

using namespace std;

int cycle(int num) {
    int seq;
    for (seq = 0; num != 1; seq++) {
        num = (num % 2 == 0) ? (num >> 1) : (num * 3 + 1);
    }

    return seq + 1;
}

int iter (int start, int end) {
    int seq, length = 0, i;

    for (i = start; i <= end; i++) {
        seq = cycle(i);
        if (seq > length)
            length = seq;
    }
    return length;
}

int main(int argc, const char* argv[]) {
    int start, end;
    while(scanf("%d %d", &start, &end) == 2) {
        if(start < end)
            printf("%d %d %d\n", start, end, iter(start, end));
        else
            printf("%d %d %d\n", start, end, iter(end, start));
    }
    return 0;
}