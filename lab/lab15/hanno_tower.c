#include <stdio.h>
#include <stdbool.h>

#define MAX_DISKS 100

// 定义塔的结构体
typedef struct {
    int disks[MAX_DISKS];
    int top; // 指向栈顶的索引
} Tower;

// 初始化塔的状态
void init_towers(Tower *towers, int n) {
    for (int i = 0; i < 3; ++i) {
        towers[i].top = -1; // 初始化为空塔
    }
    // 将所有圆盘放在起始塔上
    for (int i = n; i > 0; --i) {
        towers[0].top++;
        towers[0].disks[towers[0].top] = i;
    }
}

// 打印当前塔的状态
void print_state(Tower *towers, int n) {
    printf("Current state of towers:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Tower %c: ", 'A' + i);
        for (int j = towers[i].top; j >= 0; --j) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 移动圆盘的函数
void move(Tower *towers, int n, char from, char to) {
    int fromIndex = from - 'A';
    int toIndex = to - 'A';
    // 从from塔移动到to塔
    towers[toIndex].disks[++towers[toIndex].top] = towers[fromIndex].disks[towers[fromIndex].top--];
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// 汉诺塔递归函数
void hanoi_tower(int n, char from, char to, char aux, Tower *towers) {
    if (n == 1) {
        move(towers, n, from, to);
        print_state(towers, n);
        return;
    }
    hanoi_tower(n - 1, from, aux, to, towers);
    move(towers, n, from, to);
    print_state(towers, n);
    hanoi_tower(n - 1, aux, to, from, towers);
}

int main() {
    int n ; // 圆盘数量
    scanf("%d", &n);
    Tower towers[3]; // 三个塔

    init_towers(towers, n);
    hanoi_tower(n, 'A', 'C', 'B', towers);

    return 0;
}