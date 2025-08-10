package t8;
import java.util.HashMap;
import java.util.Map;

// 身份证类
class IDCard {
    private final String number;

    IDCard(String number) {
        this.number = number;
    }

    public String getNumber() {
        return number;
    }
}

// 身份证工厂（单例）
class IDCardFactory {
    private static final String PREFIX = "No";
    private static long nextNumber = 6000654321L; // 修改为 long 类型
    private static final IDCardFactory instance = new IDCardFactory();
    private final Map<String, IDCard> registry = new HashMap<>();

    private IDCardFactory() {}

    public static IDCardFactory getInstance() {
        return instance;
    }

    public IDCard getIDCard(String name) {
        return registry.computeIfAbsent(name, k -> new IDCard(PREFIX + nextNumber++));
    }
}

public class Main {
    public static void main(String[] args) {
        IDCardFactory factory = IDCardFactory.getInstance();
        String resident = "张三";

        // 首次办理
        IDCard card1 = factory.getIDCard(resident);
        System.out.println("第一次办理身份证，分配新号码！");
        System.out.println("身份证号为：" + card1.getNumber());

        // 补办
        IDCard card2 = factory.getIDCard(resident);
        System.out.println("\n重复办理身份证，获取旧号码！");
        System.out.println("身份证号码是否一致？" + card1.getNumber().equals(card2.getNumber()));
        System.out.println("第一次号码：" + card1.getNumber());
        System.out.println("第二次号码：" + card2.getNumber());
        System.out.println("内容是否相等：" + card1.getNumber().equals(card2.getNumber()));
        System.out.println("是否是相同对象：" + (card1 == card2));
    }
}
