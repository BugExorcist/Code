import MVC.Controller;
import MVC.Model;
import MVC.View;

public class App {
    public static void main(String[] args) {
        Model model = new Model();
        View view = new View();
        Controller controller = new Controller(model, view);

        controller.generateAndDisplayProblems();
    }
}