package 拓展;


import java.util.Enumeration;

public class Customer {
    private final String _name;
    private final Rentals _rentals = new Rentals(); // 替换原有Vector

    public void addRental(Rental arg) {
        _rentals.add(arg);
    }

    public Customer(String name) {
        _name = name;
    }

    public String getName() {
        return _name;
    }

     public String statement() {
        return buildHeader()
            + _rentals.getRentalLines()
            + buildFooter(
                _rentals.getTotalAmount(),
                _rentals.getTotalPoints()
            );
    }

    private String buildHeader() {
        return "Rental Record for " + getName() + "\n";
    }


    private String buildFooter(double totalAmount, int totalPoints) {
        return "Amount owed is " + totalAmount + "\n" +
               "You earned " + totalPoints + " frequent renter points";
    }

    public String htmlStatement() {
    return "<h1>Rental Record for " + getName() + "</h1>\n" +
           "<ul>\n" + _rentals.getHtmlRentalLines()  + "\n</ul>\n" +
           "<p>Amount owed: <em>" + _rentals.getTotalAmount()  + "</em></p>\n" +
           "<p>You earned <em>" + _rentals.getTotalPoints()  + "</em> points</p>";
}
}