package 第二次重构;

import java.util.Enumeration;
import java.util.Vector;

/**
 * 顾客类
 */
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
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    Enumeration rentals = _rentals.elements();
    String result = "Rental Record for " + getName() + "\n";

    while (rentals.hasMoreElements())  {
        Rental each = (Rental) rentals.nextElement();
        double thisAmount = each.getCharge();  // 直接调用 Rental 计算费用
        frequentRenterPoints += each.getFrequentRenterPoints();  // 直接调用 Rental 计算积分

        result += "\t" + each.getMovie().getTitle()  + "\t" + thisAmount + "\n";
        totalAmount += thisAmount;
    }

    result += "Amount owed is " + totalAmount + "\n";
    result += "You earned " + frequentRenterPoints + " frequent renter points";
    return result;
}
}
