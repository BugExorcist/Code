package 第四次重构;

import 第三次重构.Movie;

import java.util.Enumeration;

public class Rental {
    private Movie _movie;
    private int _daysRented;

    public Movie getMovie() {
        return _movie;
    }

    public double getCharge() {
        return _movie.getCharge(_daysRented);
    }

    public int getFrequentRenterPoints() {
        return _movie.getFrequentRenterPoints(_daysRented);
    }

    // 新增静态方法处理集合
    public static double getTotalAmount(Enumeration rentals) {
        double total = 0;
        while (rentals.hasMoreElements())  {
            Rental each = (Rental) rentals.nextElement();
            total += each.getCharge();
        }
        return total;
    }

    public static int getTotalPoints(Enumeration rentals) {
        int points = 0;
        while (rentals.hasMoreElements())  {
            Rental each = (Rental) rentals.nextElement();
            points += each.getFrequentRenterPoints();
        }
        return points;
    }
}
