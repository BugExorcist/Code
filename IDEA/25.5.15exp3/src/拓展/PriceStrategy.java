package 拓展;

public interface PriceStrategy {
    double calculateAmount(int daysRented);
    int calculateFrequentRenterPoints(int daysRented);
}