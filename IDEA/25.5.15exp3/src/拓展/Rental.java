package 拓展;

import 第三次重构.Movie;

public class Rental {
    private Movie _movie;
    private int _daysRented;

    public Rental(Movie regularMovie, int i) {
        this._movie = regularMovie;
         this._daysRented = i;
    }

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
