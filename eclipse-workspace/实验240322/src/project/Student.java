package project;

public class Student extends Person {
    private String studentId;
    private String major;

    public Student(String name, String gender, int age, String studentId, String major) {
        super(name, gender, age);
        this.studentId = studentId;
        this.major = major;
    }

    @Override
    public void work() {
        System.out.println("这个学生正在学习");
    }
}