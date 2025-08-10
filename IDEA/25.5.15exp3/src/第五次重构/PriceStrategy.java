package 第五次重构;

public interface PriceStrategy {
    double calculateAmount(int daysRented);
    int calculateFrequentRenterPoints(int daysRented);
}