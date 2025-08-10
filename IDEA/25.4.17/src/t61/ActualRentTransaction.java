package t61;

public class ActualRentTransaction implements RentTransaction {
    @Override
    public void execute() {
        System.out.println("Executing transaction: Paying deposit, signing contract, getting keys.");
    }
}
