package 拓展;

// 儿童片计费规则
public class ChildrenPrice implements PriceStrategy {
    @Override
    public double calculateAmount(int daysRented) {
        // 新规则：前2天免费，之后每天1元
        return Math.max(0,  daysRented - 2) * 1.0;
    }
    @Override
    public int calculateFrequentRenterPoints(int daysRented) {
        // 新规则：周末双倍积分
        return isWeekend() ? 2 : 1;
    }

    private boolean isWeekend() {
        return true;
    }
}
