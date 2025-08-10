package project;

public class Teacher extends Person {
    private String employeeId;
    private String researchArea;

    public Teacher(String name, String gender, int age, String employeeId, String researchArea) {
        super(name, gender, age);
        this.employeeId = employeeId;
        this.researchArea = researchArea;
    }

    @Override
    public void work() {
        System.out.println("这个老师正在授课");
    }
}
