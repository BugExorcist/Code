package project;

public class Staff extends Person {
    private String employeeId;
    private String position;

    public Staff(String name, String gender, int age, String employeeId, String position) {
        super(name, gender, age);
        this.employeeId = employeeId;
        this.position = position;
    }

    @Override
    public void work() {
        System.out.println("这个职工正在工作");
    }
}