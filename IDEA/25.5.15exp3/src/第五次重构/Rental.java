package 第五次重构;

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

}
