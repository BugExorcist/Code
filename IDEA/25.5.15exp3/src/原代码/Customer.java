package 原代码;

import java.util.Enumeration;
import java.util.Vector; /**
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
        double totalAmount = 0;  // 总消费金额
        int frequentRenterPoints = 0;  // 积分
        Enumeration rentals = _rentals.elements();
        String result = "原代码.Rental Record for " + getName() + "\n";

        while (rentals.hasMoreElements()) {
            double thisAmount = 0;
            Rental rental = (Rental) rentals.nextElement();  // 获取一笔租借记录

            switch (rental.getMovie().getPriceCode()) {  // 取得影片出租价格
                case Movie.REGULAR:  // 普通片
                    thisAmount += 2;
                    if (rental.getDaysRented() > 2)
                        thisAmount += (rental.getDaysRented() - 2) * 1.5;
                    break;
                case Movie.NEW_RELEASE:  //  新片
                    thisAmount += rental.getDaysRented() * 3;
                    break;
                case Movie.CHILDRENS:  //  儿童片
                    thisAmount += 1.5;
                    if (rental.getDaysRented() > 3)
                        thisAmount += (rental.getDaysRented() - 3) * 1.5;
                    break;
            }

            // add frequent renter points（累加 积分）
            frequentRenterPoints++;
            if ((rental.getMovie().getPriceCode() == Movie.NEW_RELEASE) &&
                rental.getDaysRented() > 1)
                frequentRenterPoints++;

            // show figures for this rental（显示此笔租借数据）
            result += "\t" + rental.getMovie().getTitle() + "\t" + String.valueOf(thisAmount) + "\n";
            totalAmount += thisAmount;
        }

        // add footer lines（结尾打印）
        result  += "Amount owed is " + String.valueOf(totalAmount) + "\n";
        result += "You earned " + String.valueOf(frequentRenterPoints) + " frequent renter points";
        return result;
    }
}
