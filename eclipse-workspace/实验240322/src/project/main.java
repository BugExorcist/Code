package project;

public class main {

	public static void main(String[] args) {
		Student student = new Student("张三", "男", 20, "S001", "软件工程");
        Teacher teacher = new Teacher("王老师", "女", 35, "T001", "数学");
        Staff staff = new Staff("李四", "男", 30, "E001", "经济学");
        
        System.out.println("Total persons: " + Person.getTotalPersons());
        
        student.work();
        teacher.work();
        staff.work();
	}

}

