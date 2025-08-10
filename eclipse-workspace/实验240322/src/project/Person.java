package project;

public class Person {
    private String name;
    private String gender;
    private int age;
    private static int totalPersons = 0;

    public Person(String name, String gender, int age) {
        this.name = name;
        this.gender = gender;
        this.age = age;
        totalPersons++;
    }

    public static int getTotalPersons() {
        return totalPersons;
    }

    public void work() {
        System.out.println("这是一个人");
    }
}