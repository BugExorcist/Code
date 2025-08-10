package t9;

// 武器行为接口
interface WeaponBehavior {
    void useWeapon();
}

// 具体武器行为实现
class DaggerBehavior implements WeaponBehavior {
    @Override
    public void useWeapon() {
        System.out.println("使用匕首刺杀敌人");
    }
}

class BowBehavior implements WeaponBehavior {
    @Override
    public void useWeapon() {
        System.out.println("使用弓箭射击敌人");
    }
}

class AxeBehavior implements WeaponBehavior {
    @Override
    public void useWeapon() {
        System.out.println("使用斧头砍劈敌人");
    }
}

// 角色抽象类
abstract class Character {
    protected String name;
    protected WeaponBehavior weaponBehavior;

    public Character(String name) {
        this.name = name;
    }

    public void attack() {
        System.out.print(name + ": ");
        weaponBehavior.useWeapon();
    }

    public void setWeapon(WeaponBehavior weaponBehavior) {
        this.weaponBehavior = weaponBehavior;
    }

    public abstract void display();
}

// 具体角色实现
class King extends Character {
    public King(String name) {
        super(name);
        this.weaponBehavior = new AxeBehavior(); // 默认武器
    }

    @Override
    public void display() {
        System.out.println("我是国王");
    }
}

class Queen extends Character {
    public Queen(String name) {
        super(name);
        this.weaponBehavior = new DaggerBehavior(); // 默认武器
    }

    @Override
    public void display() {
        System.out.println("我是王后");
    }
}

class Knight extends Character {
    public Knight(String name) {
        super(name);
        this.weaponBehavior = new BowBehavior(); // 默认武器
    }

    @Override
    public void display() {
        System.out.println("我是骑士");
    }
}

// 武器工厂(可选)
class WeaponFactory {
    public static WeaponBehavior createWeapon(String type) {
        switch (type.toLowerCase()) {
            case "dagger": return new DaggerBehavior();
            case "bow": return new BowBehavior();
            case "axe": return new AxeBehavior();
            default: throw new IllegalArgumentException("未知武器类型");
        }
    }
}

// 游戏模拟
public class TombRaiderGame {
    public static void main(String[] args) {
        // 创建角色
        Character king = new King("国王");
        Character queen = new Queen("皇后");
        Character knight = new Knight("骑士");

        // 显示角色信息
        king.display();
        queen.display();
        knight.display();

        System.out.println("\n=== 初始武器攻击 ===");
        king.attack();
        queen.attack();
        knight.attack();

        // 切换武器
        System.out.println("\n=== 切换武器后攻击 ===");
        king.setWeapon(new BowBehavior());
        queen.setWeapon(new AxeBehavior());
        knight.setWeapon(new DaggerBehavior());

        king.attack();
        queen.attack();
        knight.attack();

        // 使用武器工厂创建新武器
        System.out.println("\n=== 使用新武器攻击 ===");
        WeaponBehavior crossbow = WeaponFactory.createWeapon("bow");
        king.setWeapon(crossbow);
        king.attack();
    }
}