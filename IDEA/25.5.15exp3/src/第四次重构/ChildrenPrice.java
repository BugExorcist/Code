package 第四次重构;

// 儿童片计费规则
public class ChildrenPrice implements PriceStrategy {
    @Override
    public double calculateAmount(int daysRented) {
        double amount = 1.5;
        if (daysRented > 3) {
            amount += (daysRented - 3) * 1.5;
        }
        return amount;
    }

    @Override
    public int calculateFrequentRenterPoints(int daysRented) {
        return 1; // 儿童片默认1积分
    }
}
