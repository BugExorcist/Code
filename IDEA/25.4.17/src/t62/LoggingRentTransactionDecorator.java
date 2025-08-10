package t62;

public class LoggingRentTransactionDecorator implements RentTransaction {
    private RentTransaction decoratedTransaction;

    public LoggingRentTransactionDecorator(RentTransaction decoratedTransaction) {
        this.decoratedTransaction = decoratedTransaction;
    }

    @Override
    public void execute() {
        log("A new rent transaction is about to start.");
        decoratedTransaction.execute();
        log("The rent transaction has been completed.");
    }

    private void log(String message) {
        System.out.println("Logging: " + message);
    }
}
