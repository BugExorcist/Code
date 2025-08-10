package 第五次重构;

// 普通片计费规则
public class RegularPrice implements PriceStrategy {
    @Override
    public double calculateAmount(int daysRented) {
        double amount = 2;
        if (daysRented > 2) {
            amount += (daysRented - 2) * 1.5;
        }
        return amount;
    }

    @Override
    public int calculateFrequentRenterPoints(int daysRented) {
        return 1; // 普通片默认1积分
    }
}

