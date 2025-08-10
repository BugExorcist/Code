package t4;

// 中介者接口
interface AnimalMediator {
    void notify(Animal sender, String event);
}

// 抽象动物类
abstract class Animal {
    protected AnimalMediator mediator;
    protected String name;

    public Animal(AnimalMediator mediator, String name) {
        this.mediator = mediator;
        this.name = name;
    }

    public abstract void receive(String event);

    public String getName() {
        return name;
    }
}

// 具体动物类
class Tiger extends Animal {
    public Tiger(AnimalMediator mediator, String name) {
        super(mediator, name);
    }

    public void run() {
        System.out.println(name + " is running");
        mediator.notify(this, "tigerRun");
    }

    public void hunt() {
        System.out.println(name + " is hunting");
        mediator.notify(this, "tigerHunt");
    }

    public void bite() {
        System.out.println(name + " is biting");
        mediator.notify(this, "tigerBite");
    }

    @Override
    public void receive(String event) {
        switch(event) {
            case "dogBark":
                System.out.println(name + " hears a dog barking");
                snarl();
                break;
            case "catMew":
                System.out.println(name + " hears a cat mewing");
                chase();
                break;
        }
    }

    private void snarl() {
        System.out.println(name + " is snarling");
    }

    private void chase() {
        System.out.println(name + " is chasing");
    }
}

class Dog extends Animal {
    public Dog(AnimalMediator mediator, String name) {
        super(mediator, name);
    }

    public void run() {
        System.out.println(name + " is running");
        mediator.notify(this, "dogRun");
    }

    public void bark() {
        System.out.println(name + " is barking");
        mediator.notify(this, "dogBark");
    }

    public void chase() {
        System.out.println(name + " is chasing");
        mediator.notify(this, "dogChase");
    }

    @Override
    public void receive(String event) {
        switch(event) {
            case "tigerRun":
                System.out.println(name + " sees tiger running");
                escape();
                break;
            case "catClimb":
                System.out.println(name + " sees cat climbing tree");
                bark();
                break;
        }
    }

    private void escape() {
        System.out.println(name + " is escaping");
    }
}

class Cat extends Animal {
    public Cat(AnimalMediator mediator, String name) {
        super(mediator, name);
    }

    public void run() {
        System.out.println(name + " is running");
        mediator.notify(this, "catRun");
    }

    public void mew() {
        System.out.println(name + " is mewing");
        mediator.notify(this, "catMew");
    }

    public void climbTree() {
        System.out.println(name + " is climbing tree");
        mediator.notify(this, "catClimb");
    }

    @Override
    public void receive(String event) {
        switch(event) {
            case "dogChase":
                System.out.println(name + " is being chased by dog");
                escape();
                break;
            case "tigerHunt":
                System.out.println(name + " sees tiger hunting");
                climbTree();
                break;
        }
    }

    private void escape() {
        System.out.println(name + " is escaping");
    }
}

// 具体中介者
class AnimalWorldMediator implements AnimalMediator {
    private Tiger tiger;
    private Dog dog;
    private Cat cat;

    public void setTiger(Tiger tiger) {
        this.tiger = tiger;
    }

    public void setDog(Dog dog) {
        this.dog = dog;
    }

    public void setCat(Cat cat) {
        this.cat = cat;
    }

    @Override
    public void notify(Animal sender, String event) {
        String senderName = sender.getName();

        if (sender instanceof Tiger) {
            if (event.equals("tigerRun")) {
                dog.receive(event);
            } else if (event.equals("tigerHunt")) {
                cat.receive(event);
            }
        }
        else if (sender instanceof Dog) {
            if (event.equals("dogBark")) {
                tiger.receive(event);
            } else if (event.equals("dogChase")) {
                cat.receive(event);
            }
        }
        else if (sender instanceof Cat) {
            if (event.equals("catMew")) {
                tiger.receive(event);
            } else if (event.equals("catClimb")) {
                dog.receive(event);
            }
        }
    }
}

// 游戏类
class Game {
    public void action() {
        AnimalWorldMediator mediator = new AnimalWorldMediator();

        Tiger tiger = new Tiger(mediator, "Tony(Tiger)");
        Dog dog = new Dog(mediator, "Rex(Dog)");
        Cat cat = new Cat(mediator, "Mimi(Cat)");

        mediator.setTiger(tiger);
        mediator.setDog(dog);
        mediator.setCat(cat);

        // 模拟游戏动作
        tiger.run();
        dog.bark();
        cat.climbTree();
        tiger.hunt();
        dog.chase();
    }

    public static void main(String[] args) {
        new Game().action();
    }
}
