package 第一次重构;

public class Movie {
    private String _title;
    private PriceStrategy _priceStrategy; // 不再用 priceCode，改用策略

    public Movie(String title, PriceStrategy priceStrategy) {
        _title = title;
        _priceStrategy = priceStrategy;
    }

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