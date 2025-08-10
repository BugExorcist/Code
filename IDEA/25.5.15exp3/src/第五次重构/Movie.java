package 第五次重构;

public class Movie {
    private final String _title;
    private final PriceStrategy _priceStrategy;

    // 改为包私有，强制使用工厂创建
    Movie(String title, PriceStrategy priceStrategy) {
        this._title = title;
        this._priceStrategy = priceStrategy;
    }

    // 原有方法保持不变
    public String getTitle() {
        return _title;
    }

    public double getCharge(int daysRented) {
        return _priceStrategy.calculateAmount(daysRented);
    }

    public int getFrequentRenterPoints(int daysRented) {
        return _priceStrategy.calculateFrequentRenterPoints(daysRented);
    }
}