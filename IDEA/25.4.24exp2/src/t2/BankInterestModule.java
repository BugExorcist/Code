package t2;

// 用户验证类
class UserAuthenticator {
    public boolean authenticate(String account, String password) {
        // 用户验证逻辑
        return true;
    }
}

// 利息计算策略接口
interface InterestCalculationStrategy {
    double calculateInterest(double balance);
}

// 活期账户利息计算策略
class CurrentAccountInterest implements InterestCalculationStrategy {
    @Override
    public double calculateInterest(double balance) {
        return balance * 0.003; // 活期利率0.3%
    }
}

// 定期账户利息计算策略
class FixedAccountInterest implements InterestCalculationStrategy {
    @Override
    public double calculateInterest(double balance) {
        return balance * 0.025; // 定期利率2.5%
    }
}

class InterestCalculator {
    private InterestCalculationStrategy strategy;

    public void setStrategy(InterestCalculationStrategy strategy) {
        this.strategy = strategy;
    }

    public double calculate(double balance) {
        return strategy.calculateInterest(balance);
    }
}

enum UserType {
    CURRENT_ACCOUNT, FIXED_ACCOUNT
}

public class BankInterestModule {
    private UserAuthenticator authenticator;
    private InterestCalculator calculator;

    public BankInterestModule() {
        this.authenticator = new UserAuthenticator();
        this.calculator = new InterestCalculator();
    }

    public void calculateInterest(String account, String password, UserType userType, double balance) {
        // 1. 验证用户
        if (!authenticator.authenticate(account, password)) {
            System.out.println("错误：账号或密码不正确");
            return;
        }

        // 2. 根据用户类型设置计算策略
        switch (userType) {
            case CURRENT_ACCOUNT:
                calculator.setStrategy(new CurrentAccountInterest());
                break;
            case FIXED_ACCOUNT:
                calculator.setStrategy(new FixedAccountInterest());
                break;
            default:
                System.out.println("错误：未知的用户类型");
                return;
        }

        // 3. 计算并显示利息
        double interest = calculator.calculate(balance);
        System.out.println("利息计算结果: " + interest);
    }

    // 使用示例
    public static void main(String[] args) {
        BankInterestModule module = new BankInterestModule();

        // 测试用例
        module.calculateInterest("12345", "password",
                               UserType.CURRENT_ACCOUNT, 10000);
        module.calculateInterest("12345", "password",
                               UserType.FIXED_ACCOUNT, 10000);
        module.calculateInterest("wrong", "password",
                               UserType.CURRENT_ACCOUNT, 10000);
    }
}
