#include <stdio.h>
#include <string.h>

struct Item {
    char name[10];
    int price;
    int stock;
};

// 支払関係
void payment(int totalAmount) {
    //printf("\n最終的な合計金額は %d 円です。\n", totalAmount);
    int payment, change;
    int coins[] = {10000,5000,1000,500, 100, 50, 10, 5, 1}; // 使用する貨幣の種類
    int coin_count[9] = {0}; // 各貨幣の枚数を記録

    // 支払金額の入力
    printf("合計金額: %d円\n", totalAmount);
    printf("支払金額を入力してください: ");
    scanf("%d", &payment);

    // 支払金額が不足している場合の処理
    while (payment < totalAmount) {
        printf("支払金額が不足しています。再度入力してください: ");
        scanf("%d", &payment);
    }

    // お釣りの計算
    change = payment - totalAmount;
    printf("お釣り: %d円\n", change);

    // 最小の貨幣枚数を計算
    for (int i = 0; i < 9; i++) {
        if (change >= coins[i]) {
            coin_count[i] = change / coins[i];
            change %= coins[i];
        }
    }

    // 結果の表示
    printf("お釣りの最小貨幣枚数:\n");
    for (int i = 0; i < 6; i++) {
        if (coin_count[i] > 0) {
            printf("%d円: %d枚\n", coins[i], coin_count[i]);
        }
    }
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
    int found;
    int totalPrice = 0;

    printf("お会計システム作成\n");
    printf("商品名と在庫数を表示します:\n");

    for (int i = 0; i < itemCount; i++) {
        printf("商品名: %s, 在庫数: %d\n", items[i].name, items[i].stock);
    }

    while (1) {
        printf("\n注文する商品名を入力してください（終了するには「終了」と入力）: ");
        scanf("%s", orderName);

        if (strcmp(orderName, "終了") == 0) {
            break;
        }

        printf("注文する数量を入力してください: ");
        scanf("%d", &orderQuantity);

        found = 0; // 商品が見つかったかどうかをリセット

        for (int i = 0; i < itemCount; i++) {
            if (strcmp(items[i].name, orderName) == 0) {
                found = 1;
                if (orderQuantity <= items[i].stock) {
                    int currentTotal = items[i].price * orderQuantity;
                    totalPrice += currentTotal;
                    items[i].stock -= orderQuantity; // 在庫を減らす
                    printf("\n注文内容:\n");
                    printf("商品名: %s, 数量: %d, 小計: %d円\n", items[i].name, orderQuantity, currentTotal);
                } else {
                    printf("\n在庫が不足しています。\n");
                }
                break;
            }
        }

        if (!found) {
            printf("\n指定された商品は見つかりませんでした。\n");
        }
    }

    // 合計金額を表示
    payment(totalPrice);

    return 0;
}