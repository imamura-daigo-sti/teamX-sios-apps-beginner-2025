items = [
    {'name': 'りんご', 'price': 100, 'stock': 10},
    {'name': 'バナナ', 'price': 80, 'stock': 20},
    {'name': 'みかん', 'price': 50, 'stock': 15},
    {'name': 'お肉', 'price': 500, 'stock': 5},
    {'name': '牛乳', 'price': 300, 'stock': 25},
    {'name': '魚', 'price': 400, 'stock': 30}
]

order_list = []

def menu():
    print("商品一覧:")
    for item in items:
        print(f"商品名: {item['name']}, 価格: {item['price']}円, 在庫: {item['stock']}個")

def order_item():
    print("注文可能な商品一覧:")
    menu()

    name = input("注文する商品名を入力してください: ")
    quantity = int(input("注文する数量を入力してください: "))

    for item in items:
        if item['name'] == name:
            if item['stock'] >= quantity:
                total_price = item['price'] * quantity
                print(f"注文内容: {name}を{quantity}個")
                print(f"合計金額: {total_price}円")
                while True:
                    confirm = input("商品を確定しますか？ (はい/いいえ): ")
                    if confirm.lower() == 'はい':
                        item['stock'] -= quantity
                        order_list.append({'name': name, 'quantity': quantity, 'total_price': total_price})
                        print(f"{name}を{quantity}個確定しました。在庫が更新されました。")
                        break
                    elif confirm.lower() == 'いいえ':
                        print("注文をキャンセルしました。")
                        break
                    else:
                        print("「はい」または「いいえ」で入力してください。")
            else:
                print(f"{name}の在庫が不足しています。")
            return
    print(f"{name}は見つかりませんでした。")

def main():
    while True:
        print("\nメニュー:")
        print("1. 注文")
        print("2. 終了")

        choice = input("選択してください: ")

        if choice == '1':
            order_item()
        elif choice == '2':
            print("終了します。")
            break
        else:
            print("'1'または'2'で入力お願いします。")

    if order_list:
        print("\n購入履歴:")
        total_amount = 0
        for order in order_list:
            print(f"商品名: {order['name']}, 個数: {order['quantity']}個, 合計金額: {order['total_price']}円")
            total_amount += order['total_price']
        print(f"お会計: {total_amount}円")
    else:
        print("\n購入履歴はありません。")
if __name__ == '__main__':
    main()