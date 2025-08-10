package t6;

// 飞行行为接口
interface FlyBehavior {
    void fly();
}

// 起飞行为接口
interface TakeOffBehavior {
    void takeOff();
}

// 具体飞行行为实现
class SubSonicFly implements FlyBehavior {
    @Override
    public void fly() {
        System.out.println("亚音速飞行");
    }
}

class SuperSonicFly implements FlyBehavior {
    @Override
    public void fly() {
        System.out.println("超音速飞行");
    }
}

// 具体起飞行为实现
class VerticalTakeOff implements TakeOffBehavior {
    @Override
    public void takeOff() {
        System.out.println("垂直起飞");
    }
}

class LongDistanceTakeOff implements TakeOffBehavior {
    @Override
    public void takeOff() {
        System.out.println("长距离起飞");
    }
}

// 抽象飞机类
abstract class Aircraft {
    protected FlyBehavior flyBehavior;
    protected TakeOffBehavior takeOffBehavior;
    protected String name;

    public Aircraft(String name) {
        this.name = name;
    }

    public void performFly() {
        System.out.print(name + ": ");
        flyBehavior.fly();
    }

    public void performTakeOff() {
        System.out.print(name + ": ");
        takeOffBehavior.takeOff();
    }

    // 动态改变行为
    public void setFlyBehavior(FlyBehavior fb) {
        this.flyBehavior = fb;
    }

    public void setTakeOffBehavior(TakeOffBehavior tb) {
        this.takeOffBehavior = tb;
    }

    public void display() {
        System.out.println(name);
    }
}

// 具体飞机类
class Helicopter extends Aircraft {
    public Helicopter() {
        super("直升机");
        this.flyBehavior = new SubSonicFly();
        this.takeOffBehavior = new VerticalTakeOff();
    }
}

class AirPlane extends Aircraft {
    public AirPlane() {
        super("客机");
        this.flyBehavior = new SubSonicFly();
        this.takeOffBehavior = new LongDistanceTakeOff();
    }
}

class Fighter extends Aircraft {
    public Fighter() {
        super("歼击机");
        this.flyBehavior = new SuperSonicFly();
        this.takeOffBehavior = new LongDistanceTakeOff();
    }
}

class Harrier extends Aircraft {
    public Harrier() {
        super("鹞式战斗机");
        this.flyBehavior = new SuperSonicFly();
        this.takeOffBehavior = new VerticalTakeOff();
    }
}

// 飞机模拟系统
public class AircraftSimulationSystem {
    public static void main(String[] args) {
        // 创建各种飞机
        Aircraft helicopter = new Helicopter();
        Aircraft airPlane = new AirPlane();
        Aircraft fighter = new Fighter();
        Aircraft harrier = new Harrier();

        // 模拟飞机行为
        Aircraft[] aircrafts = {helicopter, airPlane, fighter, harrier};

        for (Aircraft aircraft : aircrafts) {
            aircraft.display();
            aircraft.performTakeOff();
            aircraft.performFly();
            System.out.println();
        }

        // 动态改变行为示例
        System.out.println("动态改变飞行行为:");
        helicopter.setFlyBehavior(new SuperSonicFly());
        helicopter.display();
        helicopter.performFly();
    }
}