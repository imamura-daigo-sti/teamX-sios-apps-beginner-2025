def process_payment(total):
    """
    お支払い処理を行う関数
    :param total: 合計金額
    """
    print(f"合計金額: {total}円")
    while True:
        try:
            payment = int(input("お支払い金額を入力してください: "))
            if payment < total:
                print("金額が不足しています。再度入力してください。")
            else:
                change = payment - total
                if change == 0:
                    print("お釣りなし")
                else:
                    print(f"お釣り: {change}円")
                    calculate_change(change)
                break
        except ValueError:
            print("無効な入力です。数字を入力してください。")

def calculate_change(change):
    """
    お釣りを最少の貨幣枚数で計算する関数
    :param change: お釣りの金額
    """
    denominations = [10000, 5000, 1000, 500, 100, 50, 10, 5, 1]  # 日本の貨幣単位
    result = {}
    for denom in denominations:
        count = change // denom
        if count > 0:
            result[denom] = count
            change %= denom

    print("お釣りの内訳:")
    for denom, count in result.items():
        print(f"{denom}円: {count}枚")