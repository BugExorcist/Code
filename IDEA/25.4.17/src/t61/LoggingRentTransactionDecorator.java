package t61;

public class LoggingRentTransactionDecorator implements RentTransaction {
    private RentTransaction decoratedTransaction;

    public LoggingRentTransactionDecorator(RentTransaction decoratedTransaction) {
        this.decoratedTransaction = decoratedTransaction;
    }

    @Override
    public void execute() {
        System.out.println("Logging: A new rent transaction is about to start.");
        decoratedTransaction.execute();
        System.out.println("Logging: The rent transaction has been completed.");
    }
}
