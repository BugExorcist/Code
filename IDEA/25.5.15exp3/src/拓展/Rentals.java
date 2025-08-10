package 拓展;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

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

    public String getHtmlRentalLines() {
    return rentals.stream()
        .map(r -> String.format("<li>%s:  %.2f</li>",
             r.getMovie().getTitle(),  r.getCharge()))
        .collect(Collectors.joining("\n"));
}
}