package 第五次重构;

import java.util.ArrayList;
import java.util.List;

public class Rentals {
    private final List<Rental> rentals = new ArrayList<>();

    public void add(Rental rental) {
        rentals.add(rental);
    }

    public double getTotalAmount() {
        return rentals.stream()
            .mapToDouble(Rental::getCharge)
            .sum();
    }

    public int getTotalPoints() {
        return rentals.stream()
            .mapToInt(Rental::getFrequentRenterPoints)
            .sum();
    }

    public String getRentalLines() {
        StringBuilder sb = new StringBuilder();
        rentals.forEach(rental  ->
            sb.append("\t")
              .append(rental.getMovie().getTitle())
              .append("\t")
              .append(rental.getCharge())
              .append("\n")
        );
        return sb.toString();
    }
}