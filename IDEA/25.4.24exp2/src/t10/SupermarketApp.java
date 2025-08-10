package t10;

// 促销策略接口
interface PromotionStrategy {
    double applyPromotion(double originalPrice);
    String getDescription();
}

// 具体策略实现
class WashCareDiscount implements PromotionStrategy {
    @Override
    public double applyPromotion(double originalPrice) {
        return originalPrice >= 99 ? originalPrice - 40 : originalPrice;
    }

    @Override
    public String getDescription() {
        return "洗护用品满99减40";
    }
}

class NewUserCoupon implements PromotionStrategy {
    @Override
    public double applyPromotion(double originalPrice) {
        return originalPrice - 10;
    }

    @Override
    public String getDescription() {
        return "新人券减10元";
    }
}

class OrderRebate implements PromotionStrategy {
    @Override
    public double applyPromotion(double originalPrice) {
        return originalPrice >= 199 ? originalPrice - 10 : originalPrice;
    }

    @Override
    public String getDescription() {
        return "订单满199返10元";
    }
}

// 促销策略装饰器（支持叠加）
class PromotionDecorator implements PromotionStrategy {
    protected PromotionStrategy decorated;

    public PromotionDecorator(PromotionStrategy decorated) {
        this.decorated = decorated;
    }

    @Override
    public double applyPromotion(double originalPrice) {
        return decorated.applyPromotion(originalPrice);
    }

    @Override
    public String getDescription() {
        return decorated.getDescription();
    }
}

class FreeShippingDecorator extends PromotionDecorator {
    public FreeShippingDecorator(PromotionStrategy decorated) {
        super(decorated);
    }

    @Override
    public double applyPromotion(double originalPrice) {
        double price = super.applyPromotion(originalPrice);
        return originalPrice >= 99 ? price : price + 10; // 假设运费10元
    }

    @Override
    public String getDescription() {
        return super.getDescription() + " + 满99免运费";
    }
}

// 促销策略工厂
class PromotionFactory {
    public static PromotionStrategy createFullPromotion(boolean isNewUser) {
        PromotionStrategy strategy = new WashCareDiscount();
        strategy = new OrderRebateDecorator(strategy);
        if (isNewUser) {
            strategy = new NewUserCouponDecorator(strategy);
        }
        strategy = new FreeShippingDecorator(strategy);
        return strategy;
    }

    private static class OrderRebateDecorator extends PromotionDecorator {
    public OrderRebateDecorator(PromotionStrategy decorated) {
        super(decorated);
    }

    @Override
    public double applyPromotion(double originalPrice) {
        System.out.println("正在检查订单满199返10元优惠...");
        double priceBefore = super.applyPromotion(originalPrice);
        if (originalPrice >= 199) {
            System.out.println("符合条件，减免10元");
            return priceBefore - 10;
        }
        System.out.println("未达到199元门槛，不享受此优惠");
        return priceBefore;
    }

    @Override
    public String getDescription() {
        return super.getDescription() + " + 订单满199返10元";
    }
}

private static class NewUserCouponDecorator extends PromotionDecorator {
    public NewUserCouponDecorator(PromotionStrategy decorated) {
        super(decorated);
    }

    @Override
    public double applyPromotion(double originalPrice) {
        System.out.println("应用新人10元优惠券...");
        double priceBefore = super.applyPromotion(originalPrice);
        System.out.println("新人券减免10元");
        return priceBefore - 10;
    }

    @Override
    public String getDescription() {
        return super.getDescription() + " + 新人券减10元";
    }
}
}

// 支付方式接口
interface PaymentMethod {
    void pay(double amount);
}

// 验证方式接口
interface VerificationMethod {
    boolean verify();
}

// 具体支付方式
class WeChatPay implements PaymentMethod {
    private VerificationMethod verification;

    public WeChatPay(VerificationMethod verification) {
        this.verification = verification;
    }

    @Override
    public void pay(double amount) {
        if (verification.verify()) {
            System.out.println("微信支付成功: " + amount);
        }
    }
}

// 具体验证方式
class PasswordVerification implements VerificationMethod {
    @Override
    public boolean verify() {
        System.out.println("密码验证通过");
        return true;
    }
}

// 指纹验证适配器
class FingerprintVerification implements VerificationMethod {
    private FingerprintSensor sensor;

    public FingerprintVerification() {
        this.sensor = new FingerprintSensorAdapter();
    }

    @Override
    public boolean verify() {
        return sensor.scanFingerprint();
    }
}

// 指纹传感器适配器接口
interface FingerprintSensor {
    boolean scanFingerprint();
}

// 具体适配器（封装手机原生API）
class FingerprintSensorAdapter implements FingerprintSensor {
    @Override
    public boolean scanFingerprint() {
        // 调用手机原生指纹识别API
        System.out.println("调用手机指纹识别模块");
        return true; // 假设验证成功
    }
}

public class SupermarketApp {
    public static void main(String[] args) {
        // 创建促销策略
        PromotionStrategy promotion = PromotionFactory.createFullPromotion(true);
        double originalPrice = 250.0;
        double finalPrice = promotion.applyPromotion(originalPrice);
        System.out.println(promotion.getDescription());
        System.out.println("原价: " + originalPrice + ", 优惠后: " + finalPrice);

        // 支付流程
        VerificationMethod verification = new FingerprintVerification();
        PaymentMethod payment = new WeChatPay(verification);
        payment.pay(finalPrice);
    }
}