package t61;

public class Main {
    public static void main(String[] args) {
        // 创建实际的交易对象
        RentTransaction actualTransaction = new ActualRentTransaction();

        // 使用LoggingRentTransactionDecorator装饰实际的交易对象以添加日志功能
        RentTransaction loggedTransaction = new LoggingRentTransactionDecorator(actualTransaction);

        // 执行装饰后的交易
        loggedTransaction.execute();
    }
}