package t7;

import java.util.Scanner;

// 服饰接口
interface Clothing {
    String getDescription();
    double getPrice();
}

// 通用服饰类
class GenericClothing implements Clothing {
    private String description;
    private double price;

    public GenericClothing(String description, double price) {
        this.description = description;
        this.price = price;
    }

    @Override
    public String getDescription() {
        return description;
    }

    @Override
    public double getPrice() {
        return price;
    }
}

// 服饰工厂接口
interface ClothingFactory {
    Clothing createUpper();
    Clothing createLower();
    Clothing createSocks();
    Clothing createShoes();
}

// 高端服饰工厂
class HighEndClothingFactory implements ClothingFactory {
    @Override
    public Clothing createUpper() {
        return new GenericClothing("高端上装：真丝手工衬衫", 999.9);
    }

    @Override
    public Clothing createLower() {
        return new GenericClothing("高端下装：羊毛西裤", 899.9);
    }

    @Override
    public Clothing createSocks() {
        return new GenericClothing("高端袜子：蚕丝商务袜", 199.9);
    }

    @Override
    public Clothing createShoes() {
        return new GenericClothing("高端鞋子：手工牛津鞋", 1499.9);
    }
}

// 普通服饰工厂
class RegularClothingFactory implements ClothingFactory {
    @Override
    public Clothing createUpper() {
        return new GenericClothing("普通上装：纯棉T恤", 59.9);
    }

    @Override
    public Clothing createLower() {
        return new GenericClothing("普通下装：休闲牛仔裤", 129.9);
    }

    @Override
    public Clothing createSocks() {
        return new GenericClothing("普通袜子：运动短袜", 9.9);
    }

    @Override
    public Clothing createShoes() {
        return new GenericClothing("普通鞋子：帆布鞋", 199.9);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入服装等级（高档/普通）: ");
        ClothingFactory factory = createFactory(scanner.nextLine());

        System.out.print("请选择服饰部件（上装/下装/袜子/鞋子）: ");
        Clothing clothing = createClothing(factory, scanner.nextLine());

        System.out.println("\n商品信息：\n" + clothing.getDescription() + "\n价格：" + clothing.getPrice());
    }

    private static ClothingFactory createFactory(String level) {
        if ("高档".equals(level)) return new HighEndClothingFactory();
        if ("普通".equals(level)) return new RegularClothingFactory();
        throw new IllegalArgumentException("无效的服装等级");
    }

    private static Clothing createClothing(ClothingFactory factory, String part) {
        switch (part) {
            case "上装": return factory.createUpper();
            case "下装": return factory.createLower();
            case "袜子": return factory.createSocks();
            case "鞋子": return factory.createShoes();
            default: throw new IllegalArgumentException("无效的服装部件");
        }
    }
}
