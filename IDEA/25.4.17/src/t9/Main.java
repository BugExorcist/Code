package t9;

// 基础房间接口
interface Room {
    int getCost();
}

// 宿舍（基础房型）
class Dormitory implements Room {
    @Override
    public int getCost() {
        return 0; // 基础宿舍没有设施，租金为0
    }
}

// 公寓（基础房型）
class Apartment implements Room {
    @Override
    public int getCost() {
        return 0; // 基础公寓没有设施，租金为0
    }
}

// 装饰器基类
abstract class RoomDecorator implements Room {
    protected Room room;

    public RoomDecorator(Room room) {
        this.room = room;
    }

    @Override
    public int getCost() {
        return room.getCost();
    }
}

// 卫生间装饰器
class Bathroom extends RoomDecorator {
    public Bathroom(Room room) {
        super(room);
    }

    @Override
    public int getCost() {
        return super.getCost() + 100; // 每个卫生间+100元
    }
}

// 沐浴间装饰器
class Shower extends RoomDecorator {
    public Shower(Room room) {
        super(room);
    }

    @Override
    public int getCost() {
        return super.getCost() + 100; // 每个沐浴间+100元
    }
}

// 厨房装饰器
class Kitchen extends RoomDecorator {
    public Kitchen(Room room) {
        super(room);
    }

    @Override
    public int getCost() {
        return super.getCost() + 100; // 每个厨房+100元
    }
}

// 测试选房系统
public class Main {
    public static void main(String[] args) {
        // 1. 普通宿舍（1卫生间 + 1沐浴间）
        Room dormitory = new Dormitory();
        dormitory = new Bathroom(dormitory);
        dormitory = new Shower(dormitory);
        System.out.println("普通宿舍月租金: " + dormitory.getCost()); // 200

        // 2. 公寓（2卫生间 + 2沐浴间 + 1厨房）
        Room apartment = new Apartment();
        apartment = new Bathroom(apartment);
        apartment = new Bathroom(apartment); // 第二个卫生间
        apartment = new Shower(apartment);
        apartment = new Shower(apartment); // 第二个沐浴间
        apartment = new Kitchen(apartment);
        System.out.println("公寓月租金: " + apartment.getCost()); // 500
    }
}
