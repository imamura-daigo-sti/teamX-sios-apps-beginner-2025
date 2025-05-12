class PointCardSystem:
    def __init__(self, total_amount):
        self.total_amount = total_amount
        
    def confirmationCard(self):
        """ポイントカードを持っているか確認し、その後の処理を分岐するメソッド"""
        has_card = input("ポイントカードをお持ちですか？ (yes/no): ").lower()
        if has_card == "yes":
            self.addPoints()
        elif has_card == "no":
            self.createCard()
            # カード作成直後にポイント付与を行うか確認
            add_point_now = input("ポイントカード作成が完了しました。今回の購入でポイントを付与しますか？ (yes/no): ").lower()
            if add_point_now == "yes":
                self.addPoints(is_new_card=True)
        else:
            print("無効な入力です。")
            
    def addPoints(self, is_new_card=False):
        """ポイントを付与するメソッド"""
        earned_points = 0
        earned_points = int(self.total_amount * 0.01)
        print(f"{earned_points}ポイント付与されました。")
        
    def createCard(self):
        """新しいポイントカードを作成するメソッド"""
        phone_number = input("新しいポイントカードの電話番号を入力してください: ")
        name = input("お名前を入力してください: ")
        print(f"{name}様のポイントカードを作成しました。")

    
    
if __name__ == "__main__":
    point_system = PointCardSystem(2000)
    point_system.confirmationCard()