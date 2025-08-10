package 第四次重构;


import java.util.Enumeration;
import java.util.Vector;

public class Customer {
    private String _name;  // 顾客姓名
    private Vector _rentals = new Vector();  // 租借记录

    public Customer(String name) {
        _name = name;
    }

    public void addRental(Rental arg) {
        _rentals.addElement(arg);
    }

    public String getName() {
        return _name;
    }

    public String statement() {
        return buildHeader()
            + getRentalLines()
            + buildFooter(
                Rental.getTotalAmount(_rentals.elements()),
                Rental.getTotalPoints(_rentals.elements())
            );
    }

    private String buildHeader() {
        return "Rental Record for " + getName() + "\n";
    }

    private String getRentalLines() {
        StringBuilder result = new StringBuilder();
        Enumeration rentals = _rentals.elements();
        while (rentals.hasMoreElements())  {
            Rental each = (Rental) rentals.nextElement();
            result.append(formatRentalLine(each));
        }
        return result.toString();
    }

    private String formatRentalLine(Rental rental) {
        return "\t" + rental.getMovie().getTitle()  + "\t" +
               rental.getCharge()  + "\n";
    }

    private double getTotalAmount() {
        double total = 0;
        Enumeration rentals = _rentals.elements();
        while (rentals.hasMoreElements())  {
            Rental each = (Rental) rentals.nextElement();
            total += each.getCharge();
        }
        return total;
    }

    private int getTotalPoints() {
        int points = 0;
        Enumeration rentals = _rentals.elements();
        while (rentals.hasMoreElements())  {
            Rental each = (Rental) rentals.nextElement();
            points += each.getFrequentRenterPoints();
        }
        return points;
    }

    private String buildFooter(double totalAmount, int totalPoints) {
        return "Amount owed is " + totalAmount + "\n" +
               "You earned " + totalPoints + " frequent renter points";
    }
}