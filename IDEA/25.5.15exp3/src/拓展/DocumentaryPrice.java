package 拓展;

public class DocumentaryPrice implements PriceStrategy {
    @Override
    public double calculateAmount(int daysRented) {
        return daysRented * 1.2; // 纪录片每天1.2元
    }
    @Override
    public int calculateFrequentRenterPoints(int daysRented) {
        return daysRented > 3 ? 2 : 1; // 租超3天额外积分
    }
}
