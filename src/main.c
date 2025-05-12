#include <stdio.h>
#include <string.h>

struct Item {
    char name[10];
    int price;
    int stock;
};

int total(int x) {
    

    return 0;
}

int main() {
    struct Item items[] = {
        {"りんご", 100, 10},
        {"バナナ", 80, 20},
        {"みかん", 50, 15},
        {"お肉", 500, 5},
        {"牛乳", 300, 25},
        {"魚", 400, 30},
    };

    int itemCount = sizeof(items) / sizeof(items[0]);
    char orderName[10];
    int orderQuantity;
    int found = 0; // 商品が見つかったかどうかを判定するフラグ
    int totalPrice = 0;

    printf("お会計システム作成\n");
    printf("商品名と在庫数を表示します:\n");

    for (int i = 0; i < itemCount; i++) {
        printf("商品名: %s, 在庫数: %d\n", items[i].name, items[i].stock);
    }

    printf("\n注文する商品名を入力してください: ");
    scanf("%s", orderName);

    printf("注文する数量を入力してください: ");
    scanf("%d", &orderQuantity);
 

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, orderName) == 0) {
            found = 1;
            if (orderQuantity <= items[i].stock) {
                totalPrice = items[i].price * orderQuantity;
                items[i].stock -= orderQuantity; // 在庫を減らす
                printf("\n注文内容:\n");
                printf("商品名: %s, 数量: %d, 合計金額: %d円\n", items[i].name, orderQuantity, totalPrice);
            } else {
                printf("\n在庫が不足しています。\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\n指定された商品は見つかりませんでした。\n");
    }

    return 0;
}