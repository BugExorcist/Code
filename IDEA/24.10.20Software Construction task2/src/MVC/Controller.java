package MVC;

import java.util.Set;

public class Controller {

    private final Model model;
    private final View view;

    public Controller(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    public void generateAndDisplayProblems() {
        Set<String> additionProblems = model.generateAdditionProblems(50);
        view.displayProblems(additionProblems, "加法：");

        Set<String> subtractionProblems = model.generateSubtractionProblems(50);
        view.displayProblems(subtractionProblems, "减法：");

        Set<String> mixedProblems = model.generateMixedProblems(50);
        view.displayProblems(mixedProblems, "加减混合：");
    }
}
