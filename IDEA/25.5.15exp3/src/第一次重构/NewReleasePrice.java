package 第一次重构;

// 新片计费规则
public class NewReleasePrice implements PriceStrategy {
    @Override
    public double calculateAmount(int daysRented) {
        return daysRented * 3; // 新片每天3元
    }

    @Override
    public int calculateFrequentRenterPoints(int daysRented) {
        return (daysRented > 1) ? 2 : 1; // 租超过1天额外加1积分
    }
}
